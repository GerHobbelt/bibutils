/*
 * iso639_3.h
 */
#ifndef ISO639_3_H
#define ISO639_3_H

#if defined(WIN32) || defined(WIN64)
#include "../win32/config.h"
#endif

const char * iso639_3_from_code( const char *code );
const char * iso639_3_from_name( const char *name );

#endif
