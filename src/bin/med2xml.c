/*
 * med2xml.c
 * 
 * Copyright (c) Chris Putnam 2004-2020
 *
 * Program and source code released under the GPL version 2
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "bibutils.h"
#include "bibformats.h"
#include "tomods.h"
#include "bibprog.h"

const char help1[] =  "Converts a Medline XML file into MODS XML\n\n";
const char help2[] = "medline_file";

const char progname[] = "med2xml";

int
main( int argc, char *argv[] )
{
	param p;
	medin_initparams( &p, progname );
	modsout_initparams( &p, progname );
	tomods_processargs( &argc, argv, &p, help1, help2 );
	bibprog( argc, argv, &p );
	bibl_freeparams( &p );
	return EXIT_SUCCESS;
}
