/*
 * utf8_test.c
 *
 * Copyright (c) 2012-2018
 *
 * Source code released under the GPL version 2
 *
 */
#include <stdio.h>
#include <stdlib.h>
#ifdef BUNDLE_BIBUTILS_TESTS
#include "bibutils_tests.h"
#endif


static const char progname[] = "bibutils_test";

int
main( int argc, char *argv[] )
{
	int failed = 0;
#ifndef BUNDLE_BIBUTILS_TESTS
	printf("FAIL: the bibutils unit tests have not been included in this test.");
	failed += 1;				
#else
	failed += utf8_test();
	failed += str_test();
	failed += intlist_test();
	failed += slist_test();
	failed += vplist_test();
	failed += entities_test();
	failed += doi_test();
#endif
	if ( !failed ) {
		printf( "%s: PASSED\n", progname );
		return EXIT_SUCCESS;
	} else {
		printf( "%s: FAILED\n", progname );
		return EXIT_FAILURE;
	}
}

