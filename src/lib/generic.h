/* generic.h
 *
 * Copyright (c) Chris Putnam 2016-2019
 *
 * Source code released under GPL version 2
 *
 */
#ifndef GENERIC_H
#define GENERIC_H

#include "cross_platform_porting.h"
#include <stdio.h>
#include "bibutils.h"

typedef int (* generic_convert_fn)(fields* bibin, int n, const str* intag, str* invalue, int level, param* pm, const char* outtag, fields* bibout);

int generic_null    ( fields *bibin, int n, const str *intag, const str *invalue, int level, param *pm, const char *outtag, fields *bibout );
int generic_url     ( fields *bibin, int n, const str *intag, const str *invalue, int level, param *pm, const char *outtag, fields *bibout );
int generic_notes   ( fields *bibin, int n, const str *intag, const str *invalue, int level, param *pm, const char *outtag, fields *bibout );
int generic_pages   ( fields *bibin, int n, const str *intag, const str *invalue, int level, param *pm, const char *outtag, fields *bibout );
int generic_person  ( fields *bibin, int n, const str *intag, const str *invalue, int level, param *pm, const char *outtag, fields *bibout );
int generic_serialno( fields *bibin, int n, const str *intag, const str *invalue, int level, param *pm, const char *outtag, fields *bibout );
int generic_simple  ( fields *bibin, int n, const str *intag, const str *invalue, int level, param *pm, const char *outtag, fields *bibout );
int generic_skip    ( fields *bibin, int n, const str *intag, const str *invalue, int level, param *pm, const char *outtag, fields *bibout );
int generic_title   ( fields *bibin, int n, const str *intag, const str *invalue, int level, param *pm, const char *outtag, fields *bibout );
int generic_genre   ( fields *bibin, int n, const str *intag, const str *invalue, int level, param *pm, const char *outtag, fields *bibout );

void generic_writeheader( FILE *outptr, param *pm );

#endif
