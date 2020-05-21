/*
 * gb18030.h
 *
 * Copyright (c) Chris Putnam 2008-2019
 *
 * Source code released under the GPL version 2
 *
 */
#ifndef GB18030_H
#define GB18030_H

#if defined(WIN32) || defined(WIN64)
#include "../win32/config.h"
#endif

extern int gb18030_encode( unsigned int unicode, unsigned char out[4] );
extern unsigned int gb18030_decode( char *s, unsigned int *pi );

#endif
