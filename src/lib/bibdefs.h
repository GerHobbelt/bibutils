/*
 * bibdefs.h
 *
 * Copyright (c) Chris Putnam 2005-2020
 *
 * Source code released under GPL version 2
 *
 */
#ifndef BIBDEFS_H
#define BIBDEFS_H

#if defined(WIN32) || defined(WIN64)
#include "../win32/config.h"
#endif

#define BIBL_OK           (0)
#define BIBL_ERR_BADINPUT (-1)
#define BIBL_ERR_MEMERR   (-2)
#define BIBL_ERR_CANTOPEN (-3)

#endif
