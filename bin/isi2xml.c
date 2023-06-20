/*
 * isi2xml.c
 *
 * Copyright (c) Chris Putnam 2004-5
 *
 * Program and source code released under the GPL
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "bibutils.h"
#include "bibprogs.h"

char progname[] = "isi2xml";
char help1[] = "Converts a ISI reference file into MODS XML\n\n";
char help2[] = "isi_file";

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
	bibl_initparams( &p, BIBL_ISIIN, BIBL_MODSOUT );
	tomods_processargs( &argc, argv, &p, progname, help1, help2 );
	if ( argc<2 ) {
		err = bibl_read( &b, stdin, "stdin", BIBL_ISIIN, &p );
		if ( err ) bibl_reporterr( err );
	} else {
		for ( i=1; i<argc; ++i ) {
			fp = fopen( argv[i], "r" );
			if ( fp ) {
				err = bibl_read(&b,fp,argv[i],BIBL_ISIIN,&p);
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

