#ifndef __WIN32_BIBUTILS_CONFIG_H__
#define __WIN32_BIBUTILS_CONFIG_H__

#define  _CRT_SECURE_NO_WARNINGS		1

#pragma warning(disable:4996)


#define CURR_VERSION	"6.10"
#define CURR_DATE		"2020-03-23"

#include <string.h>

static inline int strcasecmp(const char* s1, const char* s2) {
	return stricmp(s1, s2);
}
static int strncasecmp(const char* s1, const char* s2, size_t len) {
	return strnicmp(s1, s2, len);
}

#endif
