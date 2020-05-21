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

#include "cross_platform_porting.h"

extern unsigned int latex2char( const char *s, unsigned int *pos, int *unicode );
extern void uni2latex( unsigned int ch, char buf[], int buf_size );


#endif

