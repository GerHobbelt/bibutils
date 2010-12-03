/*
 * med2xml.c
 * 
 * Copyright (c) Chris Putnam 2004-2010
 *
 * Source code and program released under the GPL
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "bibutils.h"
#include "medin.h"
#include "modsout.h"
#include "tomods.h"
#include "bibprog.h"

char help1[] =  "Converts a Medline XML file into MODS XML\n\n";
char help2[] = "medline_file";

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
