/*
 * risout.c
 *
 * Copyright (c) Chris Putnam 2003-2012
 *
 * Program and source code released under the GPL
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utf8.h"
#include "newstr.h"
#include "strsearch.h"
#include "fields.h"
#include "doi.h"
#include "risout.h"

void
risout_initparams( param *p, const char *progname )
{
	p->writeformat      = BIBL_RISOUT;
	p->format_opts      = 0;
	p->charsetout       = BIBL_CHARSET_DEFAULT;
	p->charsetout_src   = BIBL_SRC_DEFAULT;
	p->latexout         = 0;
	p->utf8out          = 0;
	p->utf8bom          = 0;
	p->xmlout           = 0;
	p->nosplittitle     = 0;
	p->verbose          = 0;
	p->addcount         = 0;
	p->singlerefperfile = 0;

	if ( p->charsetout == BIBL_CHARSET_UNICODE ) {
		p->utf8out = p->utf8bom = 1;
	}

	p->headerf = risout_writeheader;
	p->footerf = NULL;
	p->writef  = risout_write;
}

enum { 
	TYPE_UNKNOWN,
	TYPE_STD,                /* standard/generic */
	TYPE_ABSTRACT,           /* abstract */
	TYPE_ARTICLE,            /* article */
	TYPE_BOOK,               /* book */
	TYPE_CASE,               /* case */
	TYPE_INBOOK,             /* chapter */
	TYPE_CONF,               /* conference */
	TYPE_ELEC,               /* electronic */
	TYPE_HEAR,               /* hearing */
	TYPE_MAGARTICLE,         /* magazine article */
	TYPE_NEWS,               /* newspaper */
	TYPE_MPCT,               /* mpct */
	TYPE_PAMP,               /* pamphlet */
	TYPE_PATENT,             /* patent */
	TYPE_PCOMM,              /* personal communication */
	TYPE_PROGRAM,            /* program */
	TYPE_REPORT,             /* report */
	TYPE_STATUTE,            /* statute */
	TYPE_THESIS,             /* thesis */
	TYPE_MASTERSTHESIS,      /* thesis */
	TYPE_PHDTHESIS,          /* thesis */
	TYPE_DIPLOMATHESIS,      /* thesis */
	TYPE_DOCTORALTHESIS,     /* thesis */
	TYPE_HABILITATIONTHESIS, /* thesis */
	TYPE_UNPUBLISHED,        /* unpublished */
};

typedef struct match_type {
	char *name;
	int type;
} match_type;

/* Try to determine type of reference from
 * <genre></genre>
 */
static int
get_type_genre( fields *f )
{
	match_type match_genres[] = {
		{ "academic journal",          TYPE_ARTICLE },
		{ "journal article",           TYPE_ARTICLE },
		{ "magazine",                  TYPE_MAGARTICLE },
		{ "conference publication",    TYPE_CONF },
		{ "newspaper",                 TYPE_NEWS },
		{ "legislation",               TYPE_STATUTE },
		{ "communication",             TYPE_PCOMM },
		{ "hearing",                   TYPE_HEAR },
		{ "electronic",                TYPE_ELEC },
		{ "legal case and case notes", TYPE_CASE },
		{ "book chapter",              TYPE_INBOOK },
		{ "Ph.D. thesis",              TYPE_PHDTHESIS },
		{ "Masters thesis",            TYPE_MASTERSTHESIS },
		{ "Diploma thesis",            TYPE_DIPLOMATHESIS },
		{ "Doctoral thesis",           TYPE_DOCTORALTHESIS },
		{ "Habilitation thesis",       TYPE_HABILITATIONTHESIS },
		{ "report",                    TYPE_REPORT },
		{ "abstract or summary",       TYPE_ABSTRACT },
		{ "patent",                    TYPE_PATENT },
		{ "unpublished",               TYPE_UNPUBLISHED },
	};
	int nmatch_genres = sizeof( match_genres ) / sizeof( match_genres[0] );
	int type, i, j;
	char *value;

	type = TYPE_UNKNOWN;

	for ( i=0; i<fields_num( f ); ++i ) {
		if ( !fields_match_tag( f, i,"GENRE" ) &&
		     !fields_match_tag( f, i,"NGENRE" ) )
			continue;
		value = ( char * ) fields_value( f, i, FIELDS_CHRP );
		for ( j=0; j<nmatch_genres; ++j )
			if ( !strcasecmp( match_genres[j].name, value ) )
				type = match_genres[j].type;
		if ( type==TYPE_UNKNOWN ) {
			if ( !strcasecmp( value, "periodical" ) )
				type = TYPE_ARTICLE;
			else if ( !strcasecmp( value, "thesis" ) )
				type = TYPE_THESIS;
			else if ( !strcasecmp( value, "book" ) ) {
				if ( fields_level( f, i )==0 ) type=TYPE_BOOK;
				else type=TYPE_INBOOK;
			}
			else if ( !strcasecmp( value, "collection" ) ) {
				if ( fields_level( f, i )==0 ) type=TYPE_BOOK;
				else type=TYPE_INBOOK;
			}
		}

	}

	return type;
}

/* Try to determine type of reference from
 * <TypeOfResource></TypeOfResource>
 */
static int
get_type_resource( fields *f )
{
	match_type match_res[] = {
		{ "software, multimedia",      TYPE_PROGRAM },
	};
	int nmatch_res = sizeof( match_res ) / sizeof( match_res[0] );
	int type, i, j;
	char *value;
	vplist a;

	type = TYPE_UNKNOWN;

	vplist_init( &a );
	fields_findv_each( f, LEVEL_ANY, FIELDS_CHRP, &a, "RESOURCE" );

	for ( i=0; i<a.n; ++i ) {
		value = ( char * ) vplist_get( &a, i );
		for ( j=0; j<nmatch_res; ++j ) {
			if ( !strcasecmp( value, match_res[j].name ) )
				type = match_res[j].type;
		}
	}

	vplist_free( &a );
	return type;
}

/* Try to determine type of reference from <issuance></issuance> and */
/* <typeOfReference></typeOfReference> */
static int
get_type_issuance( fields *f )
{
	int type = TYPE_UNKNOWN;
	int i, monographic = 0, text = 0, monographic_level = 0;
	for ( i=0; i<f->n; ++i ) {
		if ( !strcasecmp( f->tag[i].data, "issuance" ) &&
		     !strcasecmp( f->data[i].data, "MONOGRAPHIC" ) ){
			monographic = 1;
			monographic_level = f->level[i];
		}
		if ( !strcasecmp( f->tag[i].data, "typeOfResource" ) &&
		     !strcasecmp( f->data[i].data,"text") ) {
			text = 1;
		}
	}
	if ( monographic && text ) {
		if ( monographic_level==0 ) type=TYPE_BOOK;
		else if ( monographic_level>0 ) type=TYPE_INBOOK;
	}
	return type;
}

static int
get_type( fields *f )
{
	int type;
	type = get_type_genre( f );
	if ( type==TYPE_UNKNOWN ) type = get_type_resource( f );
	if ( type==TYPE_UNKNOWN ) type = get_type_issuance( f );
	if ( type==TYPE_UNKNOWN ) type = TYPE_STD;
	return type;
}

static void
output_type( FILE *fp, int type, param *p )
{
	match_type tyout[] = {
		{ "STD",  TYPE_STD },
		{ "ABST", TYPE_ABSTRACT },
		{ "JOUR", TYPE_ARTICLE },
		{ "BOOK", TYPE_BOOK },
		{ "CASE", TYPE_CASE },
		{ "CHAP", TYPE_INBOOK },
		{ "CONF", TYPE_CONF },
		{ "ELEC", TYPE_ELEC },
		{ "HEAR", TYPE_HEAR },
		{ "MGZN", TYPE_MAGARTICLE },
		{ "NEWS", TYPE_NEWS },
		{ "MPCT", TYPE_MPCT },
		{ "PAMP", TYPE_PAMP },
		{ "PAT",  TYPE_PATENT },
		{ "PCOMM",TYPE_PCOMM },
		{ "COMP", TYPE_PROGRAM },
		{ "RPRT", TYPE_REPORT },
		{ "STAT", TYPE_STATUTE },
		{ "THES", TYPE_THESIS },
		{ "THES", TYPE_MASTERSTHESIS },
		{ "THES", TYPE_PHDTHESIS },
		{ "THES", TYPE_DIPLOMATHESIS },
		{ "THES", TYPE_DOCTORALTHESIS },
		{ "THES", TYPE_HABILITATIONTHESIS },
		{ "UNPB", TYPE_UNPUBLISHED }
	};
	int ntyout = sizeof( tyout ) / sizeof( tyout[0] );
	int i, found;

	fprintf( fp, "TY  - " );
	found = 0;
	for ( i=0; i<ntyout && !found ; ++i ) {
		if ( tyout[i].type == type ) {
			fprintf( fp, "%s", tyout[i].name );
			found = 1;
		}
	}
	/* Report internal error, default to TYPE_STD */
	if ( !found ) {
		if ( p->progname ) fprintf( stderr, "%s: ", p->progname );
		fprintf( stderr, "Internal Error: Cannot identify type %d\n",
			type );
		fprintf( fp, "STD" );
	}
	fprintf( fp, "\n" );
}

static void
output_person ( FILE *fp, char *p )
{
	int nseps = 0, nch;
	while ( *p ) {
		nch = 0;
		if ( nseps==1 ) fprintf( fp, "," );
		if ( nseps ) fprintf( fp, " " );
		while ( *p && *p!='|' ) {
			fprintf( fp, "%c", *p++ );
			nch++;
		}
		if ( *p=='|' ) p++;
		if ( nseps!=0 && nch==1 ) fprintf( fp, "." ); 
		nseps++;
	}
}

static void
output_people( FILE *fp, fields *f, char *tag, char *ristag, int level )
{
	vplist people;
	int i;
	vplist_init( &people );
	fields_findv_each( f, level, FIELDS_CHRP, &people, tag );
	for ( i=0; i<people.n; ++i ) {
		fprintf( fp, "%s  - ", ristag );
		output_person( fp, ( char * ) vplist_get( &people, i ) );
		fprintf( fp, "\n" );
	}
	vplist_free( &people );
}

static void
output_date( FILE *fp, fields *f )
{
	char *year  = fields_findv_firstof( f, LEVEL_ANY, FIELDS_CHRP,
			"YEAR", "PARTYEAR", NULL );
	char *month = fields_findv_firstof( f, LEVEL_ANY, FIELDS_CHRP,
			"MONTH", "PARTMONTH", NULL );
	char *day   = fields_findv_firstof( f, LEVEL_ANY, FIELDS_CHRP,
			"DAY", "PARTDAY", NULL );
	if ( year || month || day ) {
		fprintf( fp, "PY  - " );
		if ( year ) fprintf( fp, "%s", year );
		fprintf( fp, "/" );
		if ( month ) fprintf( fp, "%s", month );
		fprintf( fp, "/" );
		if ( day ) fprintf( fp, "%s", day );
		fprintf( fp, "\n" );
	}
}

static void
output_titlecore( FILE *fp, fields *f, char *ristag, int level,
	char *maintag, char *subtag )
{
	newstr *mainttl = fields_findv( f, level, FIELDS_STRP, maintag );
	newstr *subttl  = fields_findv( f, level, FIELDS_STRP, subtag );
	if ( mainttl ) {
		fprintf( fp, "%s  - %s", ristag, mainttl->data );
		if ( subttl ) {
			if ( mainttl->data[ mainttl->len - 1 ]!='?' )
				fprintf( fp, ": " );
			else fprintf( fp, " " );
			fprintf( fp, "%s", subttl->data );
		}
		fprintf( fp, "\n" );
	}
}

static void
output_title( FILE *fp, fields *f, char *ristag, int level )
{
	output_titlecore( fp, f, ristag, level, "TITLE", "SUBTITLE" );
}

static void
output_abbrtitle( FILE *fp, fields *f, char *ristag, int level )
{
	output_titlecore( fp, f, ristag, level, "SHORTTITLE", "SHORTSUBTITLE" );
}

static void
output_pages( FILE *fp, fields *f )
{
	char *sn = fields_findv( f, LEVEL_ANY, FIELDS_CHRP, "PAGESTART" );
	char *en = fields_findv( f, LEVEL_ANY, FIELDS_CHRP, "PAGEEND" );
	char *ar;

	if ( sn || en ) {
		if ( sn ) fprintf( fp, "SP  - %s\n", sn );
		if ( en ) fprintf( fp, "EP  - %s\n", en );
	} else {
		ar = fields_findv( f, LEVEL_ANY, FIELDS_CHRP, "ARTICLENUMBER" );
		if ( ar ) fprintf( fp, "SP  - %s\n", ar );
	}
}

static void
output_keywords( FILE *fp, fields *f )
{
	vplist vpl;
	int i;
	vplist_init( &vpl );
	fields_findv_each( f, LEVEL_ANY, FIELDS_CHRP, &vpl, "KEYWORD" );
	for ( i=0; i<vpl.n; ++i )
		fprintf( fp, "KW  - %s\n", ( char * ) vplist_get( &vpl, i ) );
	vplist_free( &vpl );
}

static void
output_pmid( FILE *fp, fields *f )
{
	newstr s;
	int i;
	newstr_init( &s );
	for ( i=0; i<fields_num( f ); ++i ) {
		if ( !fields_match_tag( f, i, "PMID" ) ) continue;
		pmid_to_url( f, i, "URL", &s );
		if ( s.len )
			fprintf( fp, "UR  - %s\n", s.data );
	}
	newstr_free( &s );
}

static void
output_arxiv( FILE *fp, fields *f )
{
	newstr s;
	int i;
	newstr_init( &s );
	for ( i=0; i<fields_num( f ); ++i ) {
		if ( !fields_match_tag( f, i, "ARXIV" ) ) continue;
		arxiv_to_url( f, i, "URL", &s );
		if ( s.len )
			fprintf( fp, "UR  - %s\n", s.data );
	}
	newstr_free( &s );
}

static void
output_jstor( FILE *fp, fields *f )
{
	newstr s;
	int i;
	newstr_init( &s );
	for ( i=0; i<fields_num( f ); ++i ) {
		if ( !fields_match_tag( f, i, "JSTOR" ) ) continue;
		jstor_to_url( f, i, "URL", &s );
		if ( s.len )
			fprintf( fp, "UR  - %s\n", s.data );
	}
	newstr_free( &s );
}

static void
output_thesishint( FILE *fp, int type )
{
	if ( type==TYPE_MASTERSTHESIS )
		fprintf( fp, "%s  - %s\n", "U1", "Masters thesis" );
	else if ( type==TYPE_PHDTHESIS )
		fprintf( fp, "%s  - %s\n", "U1", "Ph.D. thesis" );
	else if ( type==TYPE_DIPLOMATHESIS )
		fprintf( fp, "%s  - %s\n", "U1", "Diploma thesis" );
	else if ( type==TYPE_DOCTORALTHESIS )
		fprintf( fp, "%s  - %s\n", "U1", "Doctoral thesis" );
	else if ( type==TYPE_HABILITATIONTHESIS )
		fprintf( fp, "%s  - %s\n", "U1", "Habilitation thesis" );
}

static void
output_easy( FILE *fp, fields *f, char *tag, char *ristag, int level )
{
	char *value = fields_findv( f, level, FIELDS_CHRP, tag );
	if ( value ) fprintf( fp, "%s  - %s\n", ristag, value );
}

static void
output_easyall( FILE *fp, fields *f, char *tag, char *ristag, int level )
{
	vplist a;
	int i;
	vplist_init( &a );
	fields_findv_each( f, level, FIELDS_CHRP, &a, tag );
	for ( i=0; i<a.n; ++i )
		fprintf( fp, "%s  - %s\n", ristag, (char *) vplist_get( &a, i ) );
	vplist_free( &a );
}

void
risout_write( fields *f, FILE *fp, param *p, unsigned long refnum )
{
	int type;
	type = get_type( f );
	output_type( fp, type, p );
	output_people(  fp, f, "AUTHOR",      "AU", LEVEL_MAIN   );
	output_easyall( fp, f, "AUTHOR:CORP", "AU", LEVEL_MAIN   );
	output_easyall( fp, f, "AUTHOR:ASIS", "AU", LEVEL_MAIN   );
	output_people(  fp, f, "AUTHOR",      "A2", LEVEL_HOST   );
	output_easyall( fp, f, "AUTHOR:CORP", "A2", LEVEL_HOST   );
	output_easyall( fp, f, "AUTHOR:ASIS", "A2", LEVEL_HOST   );
	output_people(  fp, f, "AUTHOR",      "A3", LEVEL_SERIES );
	output_easyall( fp, f, "AUTHOR:CORP", "A3", LEVEL_SERIES );
	output_easyall( fp, f, "AUTHOR:ASIS", "A3", LEVEL_SERIES );
	output_people(  fp, f, "EDITOR",      "ED", LEVEL_ANY    );
	output_easyall( fp, f, "EDITOR:CORP", "ED", LEVEL_ANY    );
	output_easyall( fp, f, "EDITOR:ASIS", "ED", LEVEL_ANY    );
	output_date( fp, f );
	output_title( fp, f, "TI", 0 );
	output_abbrtitle( fp, f, "T2", -1 );
	if ( type==TYPE_ARTICLE || type==TYPE_MAGARTICLE ) {
		output_title( fp, f, "JO", 1 );
	}
	else output_title( fp, f, "BT", 1 );
	output_title( fp, f, "T3", 2 );
	output_pages( fp, f );
	output_easy( fp, f, "VOLUME",             "VL", LEVEL_ANY );
	output_easy( fp, f, "ISSUE",              "IS", LEVEL_ANY );
	output_easy( fp, f, "NUMBER",             "IS", LEVEL_ANY );
	output_easy( fp, f, "EDITION",            "ET", LEVEL_ANY );
	output_easy( fp, f, "NUMVOLUMES",         "NV", LEVEL_ANY );
	output_easy( fp, f, "AUTHORADDRESS",      "AD", LEVEL_ANY );
	output_easy( fp, f, "PUBLISHER",          "PB", LEVEL_ANY );
	output_easy( fp, f, "DEGREEGRANTOR",      "PB", LEVEL_ANY );
	output_easy( fp, f, "DEGREEGRANTOR:ASIS", "PB", LEVEL_ANY );
	output_easy( fp, f, "DEGREEGRANTOR:CORP", "PB", LEVEL_ANY );
	output_easy( fp, f, "ADDRESS",            "CY", LEVEL_ANY );
	output_keywords( fp, f );
	output_easy( fp, f, "ABSTRACT",           "AB", LEVEL_ANY );
	output_easy( fp, f, "CALLNUMBER",         "CN", LEVEL_ANY );
	output_easy( fp, f, "ISSN",               "SN", LEVEL_ANY );
	output_easy( fp, f, "ISBN",               "SN", LEVEL_ANY );
	output_easyall( fp, f, "URL",             "UR", LEVEL_ANY );
	output_easyall( fp, f, "DOI",             "DO", LEVEL_ANY );
	output_easyall( fp, f, "FILEATTACH",      "L1", LEVEL_ANY );
	output_easyall( fp, f, "FIGATTACH",       "L4", LEVEL_ANY );
	output_easy( fp, f, "CAPTION",            "CA", LEVEL_ANY );
	output_pmid( fp, f );
	output_arxiv( fp, f );
	output_jstor( fp, f );
	output_easy( fp, f, "LANGUAGE",           "LA", LEVEL_ANY );
	output_easy( fp, f, "NOTES",              "N1", LEVEL_ANY );
	output_easy( fp, f, "REFNUM",             "ID", LEVEL_ANY );
	output_thesishint( fp, type );
	fprintf( fp, "ER  - \n" );
	fflush( fp );
}

void
risout_writeheader( FILE *outptr, param *p )
{
	if ( p->utf8bom ) utf8_writebom( outptr );
}

