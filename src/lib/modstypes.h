/*
 * modstypes.h
 *
 * Copyright (c) Chris Putnam 2008-2019
 *
 * Source code released under the GPL version 2
 *
 */
#ifndef MODSTYPES_H
#define MODSTYPES_H

#include "cross_platform_porting.h"

typedef struct convert {
	const char *mods;     /* old */
	const char *internal; /* new */
	int pos;
	int code;
} convert;

extern const convert identifier_types[];
extern int nidentifier_types;

extern const char *mods_find_attrib( const char *internal_name, const convert *data, int ndata );
extern const char *mods_find_internal( const char *mods_name, const convert *data, int ndata );

#endif
