/*
 * entities.h
 *
 * Copyright (c) Chris Putnam 2003-2019
 *
 * Source code released under the GPL version 2
 *
 */
#ifndef ENTITIES_H
#define ENTITIES_H

#if defined(WIN32) || defined(WIN64)
#include "../win32/config.h"
#endif

extern unsigned int decode_entity( char *s, unsigned int *pi, 
		int *unicode, int *err );

#endif

