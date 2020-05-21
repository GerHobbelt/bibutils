/*
 * bibtypes.h
 *
 * Copyright (c) Chris Putnam 2003-2019
 *
 * Source code released under the GPL version 2
 *
 */
#ifndef BIBTYPES_H
#define BIBTYPES_H

#if defined(WIN32) || defined(WIN64)
#include "../win32/config.h"
#endif
#include "reftypes.h"

extern const variants bibtex_all[];
extern int bibtex_nall;

#endif
