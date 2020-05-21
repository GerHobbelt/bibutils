/*
 * bib2xml.c
 *
 * Copyright (c) Chris Putnam 2003-2020
 *
 * Program and source code released under the GPL version 2
 *
 */
#include "cross_platform_porting.h"
#include <stdio.h>
#include <stdlib.h>
#include "bibutils.h"
#include "bibformats.h"
#include "tomods.h"
#include "bibprog.h"

const char progname[] = "bib2xml";

const char help1[] = "Converts a Bibtex reference file into MODS XML\n\n";
const char help2[] = "bibtex_file";

int
main( int argc, char *argv[] )
{
	param p;
	bibtexin_initparams( &p, progname );
	modsout_initparams( &p, progname );
	tomods_processargs( &argc, argv, &p, help1, help2 );
	bibprog( argc, argv, &p );
	bibl_freeparams( &p );
	return EXIT_SUCCESS;
}
