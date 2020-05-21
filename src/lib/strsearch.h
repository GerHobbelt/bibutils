/*
 * strsearch.h
 *
 * Copyright (c) Chris Putnam 1995-2019
 *
 * Source code released under the GPL version 2
 *
 */
#ifndef STRSEARCH_H
#define STRSEARCH_H

#if defined(WIN32) || defined(WIN64)
#include "../win32/config.h"
#endif

const char *strsearch (const char *haystack, const char *needle);

#endif

