/*
 * med2xml.c
 * 
 * Copyright (c) Chris Putnam 2004-5
 *
 * Source code and program released under the GPL
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "bibutils.h"
#include "bibprogs.h"

char progname[] = "med2xml";
char help1[] =  "Converts a Medline XML file into MODS XML\n\n";
char help2[] = "medline_file";

list asis, corps;

int
main( int argc, char *argv[] )
{
	FILE *fp;
	param p;
	bibl b;
	int err, i;

	list_init( &asis );
	list_init( &corps );

	bibl_init( &b );
	bibl_initparams( &p, BIBL_MEDLINEIN, BIBL_MODSOUT );
	tomods_processargs( &argc, argv, &p, progname, help1, help2 );
	if ( argc<2 ) {
		err = bibl_read( &b, stdin, "stdin", BIBL_MEDLINEIN, & p );
		if ( err ) bibl_reporterr( err );
	} else {
		for ( i=1; i<argc; ++i ) {
			fp = fopen( argv[i], "r" );
			if ( fp ) {
				err = bibl_read( &b, fp, argv[i], BIBL_MEDLINEIN, &p );
				if ( err ) bibl_reporterr( err );
				fclose( fp );
			}
		}
	}
	bibl_write( &b, stdout, BIBL_MODSOUT, &p );
	fflush( stdout );
	fprintf( stderr, "%s: Processed %ld references.\n", progname, b.nrefs );
	bibl_free( &b );
	return EXIT_SUCCESS;
}
