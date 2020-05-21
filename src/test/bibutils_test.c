/*
 * utf8_test.c
 *
 * Copyright (c) 2012-2018
 *
 * Source code released under the GPL version 2
 *
 */
#if defined(WIN32) || defined(WIN64)
#include "../win32/config.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#ifdef BUNDLE_BIBUTILS_TESTS
#include "bibutils_tests.h"
#endif
#ifdef HAVE_DIRENT_H
#include <dirent.h>
#else
// ripped from https://github.com/tronkko/dirent
#include "../win32/include/dirent.h"
#endif
#include "bibutils.h"
#include "bibformats.h"
#include "tomods.h"
#include "bibprog.h"

#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif


static const char progname[] = "bibutils_test";

static int process_input_file(const char* filepath, const char* filepath_subtree_part, struct dirent* ent)
{
    // ignore hidden dot files:
    if (ent->d_name[0] == '.') return EXIT_SUCCESS;

    const char* ext = strrchr(ent->d_name, '.');
    if (strcasecmp(ext, ".bib") == 0) {
        param p;
        bibtexin_initparams(&p, progname);
        modsout_initparams(&p, progname);
        tomods_processargs(&argc, argv, &p, NULL, NULL);
        bibprog(argc, argv, &p);
        bibl_freeparams(&p);
        return EXIT_SUCCESS;
    }
    else if (strcasecmp(ext, ".biblatex") == 0) {
        param p;
        biblatexin_initparams(&p, progname);
        modsout_initparams(&p, progname);
        tomods_processargs(&argc, argv, &p, NULL, NULL);
        bibprog(argc, argv, &p);
        bibl_freeparams(&p);
        return EXIT_SUCCESS;
    }

    printf("Don't know how to process '%s' input file: %s", ext + 1, filepath);
    return EXIT_FAILURE;
}

static int scan_dirtree(const char* base, const char *subtree_part)
{
    struct dirent** files;
    int i;
    int n;
    int rv = 0;

    /* Scan files in directory */
    n = scandir(base, &files, NULL, alphasort);
    if (n >= 0) {
        /* Loop through file names */
        for (i = 0; i < n; i++) {
            struct dirent* ent;

            /* Get pointer to file entry */
            ent = files[i];

            char filepath[MAX(PATH_MAX + 1, 2048)];
            sprintf_s(filepath, countof(filepath), "%s%s%s", base, (strchr("/\\", base[strlen(base) - 1]) ? "" : "/"), ent->d_name);
            const char* filepath_subtree_part = filepath + (subtree_part ? subtree_part - base : strlen(base) + (strchr("/\\", base[strlen(base) - 1]) ? 0 : 1));

            /* Output file name */
            switch (ent->d_type) {
            case DT_REG:
                printf("%s\n", filepath_subtree_part);
                rv += process_input_file(filepath, filepath_subtree_part, ent);
                continue;

            case DT_DIR:
                if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) continue;
                printf("%s/\n", filepath_subtree_part);
                rv += scan_dirtree(filepath, filepath_subtree_part);
                continue;

            case DT_LNK:
                printf("%s@\n", filepath_subtree_part);
                continue;

            default:
                printf("%s*\n", filepath_subtree_part);
                continue;
            }
        }

        /* Release file names */
        for (i = 0; i < n; i++) {
            free(files[i]);
        }
        free(files);
        return rv;
    }
    else {
        char errbuf[4096];
        strerror_s(errbuf, countof(errbuf), errno);
        fprintf(stderr, "Cannot open %s (%s)\n", base, errbuf);
        return EXIT_FAILURE;
    }
}

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

    if (argc < 2) {
        printf("FAILED: Must specify base directory to test files as commandline argument.");
        failed += 1;
    }
    else {
        failed += scan_dirtree(argv[1], NULL);
    }

	if ( !failed ) {
		printf( "%s: PASSED\n", progname );
		return EXIT_SUCCESS;
	} else {
		printf( "%s: FAILED\n", progname );
		return EXIT_FAILURE;
	}
}

