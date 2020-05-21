/*
 * iso639-2 language codes
 */
#ifndef ISO639_2_H
#define ISO639_2_H

#if defined(WIN32) || defined(WIN64)
#include "../win32/config.h"
#endif

const char * iso639_2_from_code(const char *code );
const char * iso639_2_from_language(const char *lang );

#endif
