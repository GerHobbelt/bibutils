/*
 * cross_platform_porting.h
 *
 * Copyright (c) Chris Putnam 2003-2019
 *
 * Source code released under the GPL version 2
 *
 */
#ifndef CROSS_PLATFORM_PORTING_H
#define CROSS_PLATFORM_PORTING_H

#if defined(WIN32) || defined(WIN64)
#include "../win32/config.h"
#endif

#define CURR_VERSION	"6.10"
#define CURR_DATE		"2020-03-23"

#define countof(array)					( sizeof(array) / sizeof(array[0]) )


#endif
