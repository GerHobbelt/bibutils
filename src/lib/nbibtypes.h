/*
 * nbibtypes.h
 *
 * Copyright (c) Chris Putnam 2003-2019
 *
 * Source code released under the GPL version 2
 *
 */
#ifndef NBIBTYPES_H
#define NBIBTYPES_H

#if defined(WIN32) || defined(WIN64)
#include "../win32/config.h"
#endif
#include "reftypes.h"

extern const variants nbib_all[];
extern int nbib_nall;

#endif
