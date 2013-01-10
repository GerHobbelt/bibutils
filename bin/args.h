/*
 * args.h
 *
 * Copyright (c) Chris Putnam 2012-2013
 *
 * Program and source code released under the GPL version 2
 *
 */
#ifndef ARGS_H
#define ARGS_H

extern void args_tellversion( char *progname );
extern int args_match( char *check, char *shortarg, char *longarg );
extern void process_charsets( int *argc, char *argv[], param *p,
	int use_input, int use_output );

#endif
