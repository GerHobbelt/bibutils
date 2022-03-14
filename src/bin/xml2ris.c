/*
 * xml2ris.c
 *
 * Copyright (c) Chris Putnam 2003-2021
 *
 * Program and source code released under the GPL version 2
 *
 */
#include "cross_platform_porting.h"
#include <stdio.h>
#include <stdlib.h>
#include "bibutils.h"
#include "bibformats.h"
#include "args.h"
#include "bibprog.h"

#include "monolithic_examples.h"

static const char progname[] = "xml2ris";

#if defined(BUILD_MONOLITHIC)
#define main     bibutils_xml2ris_main
#endif

static void
help( const char *name )
{
	args_tellversion( name );
	fprintf(stderr,"Converts an XML intermediate reference file into RIS format\n\n");

	fprintf(stderr,"usage: %s xml_file > ris_file\n\n", name);
        fprintf(stderr,"  xml_file can be replaced with file list or omitted to use as a filter\n\n");

	fprintf(stderr,"  -h, --help     display this help\n");
	fprintf(stderr,"  -v, --version  display version\n\n");
	fprintf(stderr,"  -nb, --no-bom  do not write Byte Order Mark in UTF8 output\n");
	fprintf(stderr,"  -s, --single-refperfile one reference per output file\n");
	fprintf(stderr,"  -i, --input-encoding  interpret the input with specified character set\n" );
	fprintf(stderr,"                        (use w/o argument for current list)\n" );
	fprintf(stderr,"  -o, --output-encoding write the output with specified character set\n" );
	fprintf(stderr,"                        (use w/o argument for current list)\n" );
	fprintf(stderr,"  --verbose      for verbose output\n");
	fprintf(stderr,"  --debug        for debug output\n");

	fprintf(stderr,"Citation codes (ID  - ) generated from <REFNUM> tag.   See \n");
	fprintf(stderr,"http://sourceforge.net/p/bibutils/home/Bibutils for more details\n\n");
}

static void
process_args( int *argc, char *argv[], param *p )
{
	int i, j, subtract;
	i = 1;
	while ( i < *argc ) {
		subtract = 0;
		if ( args_match( argv[i], "-h", "--help" ) ) {
			help( p->progname );
			exit( EXIT_SUCCESS );
		} else if ( args_match( argv[i], "-v", "--version" ) ) {
			args_tellversion( p->progname );
			exit( EXIT_SUCCESS );
		} else if ( args_match( argv[i], "-s", "--single-refperfile")){
			p->singlerefperfile = 1;
			subtract = 1;
		} else if ( args_match( argv[i], "-nb", "--no-bom" ) ) {
			p->utf8bom = 0;
			subtract = 1;
		} else if ( args_match( argv[i], "--verbose", "" ) ) {
			p->verbose = 1;
			subtract = 1;
		} else if ( args_match( argv[i], "--debug", "" ) ) {
			p->verbose = 3;
			subtract = 1;
		}
		if ( subtract ) {
			for ( j=i+subtract; j<*argc; ++j )
				argv[j-subtract] = argv[j];
			*argc -= subtract;
		} else {
			if ( argv[i][0]=='-' ) fprintf( stderr, "Warning: Did not recognize potential command-line argument %s\n", argv[i] );
			i++;
		}
	}
}

int main(int argc, const char** argv)
{
	param p;
	modsin_initparams( &p, progname );
	risout_initparams( &p, progname );
	process_charsets( &argc, argv, &p );
	process_args( &argc, argv, &p );
	bibprog( argc, argv, &p );
	bibl_freeparams( &p );
	return EXIT_SUCCESS;
}
