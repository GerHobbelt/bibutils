/*
 * wordbib2xml.c
 * 
 * Copyright (c) Chris Putnam 2009-2021
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

#include "monolithic_examples.h"

static const char help1[] =  "Converts a Word2007 Bibliography XML file into MODS XML\n\n";
static const char help2[] = "word2007bib_file";

static const char progname[] = "wordbib2xml";

#if defined(BUILD_MONOLITHIC)
#define main     bibutils_wordbib2xml_main
#endif

int main(int argc, const char** argv)
{
	param p;
	wordin_initparams( &p, progname );
	modsout_initparams( &p, progname );
	tomods_processargs( &argc, argv, &p, help1, help2 );
	bibprog( argc, argv, &p );
	bibl_freeparams( &p );
	return EXIT_SUCCESS;
}
