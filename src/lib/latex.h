/*
 * latex.h
 *
 * Copyright (c) Chris Putnam 2004-2019
 *
 * Source code released under the GPL version 2
 *
 */
#ifndef LATEX_H
#define LATEX_H

#if defined(WIN32) || defined(WIN64)
#include "../win32/config.h"
#endif

extern unsigned int latex2char( char *s, unsigned int *pos, int *unicode );
extern void uni2latex( unsigned int ch, char buf[], int buf_size );


#endif

