/*
 * isitypes.h
 *
 * Copyright (c) Chris Putnam 2003-2019
 *
 * Source code released under the GPL version 2
 *
 */
#ifndef ISITYPES_H
#define ISITYPES_H

#if defined(WIN32) || defined(WIN64)
#include "../win32/config.h"
#endif
#include "reftypes.h"

extern const variants isi_all[];
extern int isi_nall;

#endif
