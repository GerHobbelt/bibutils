#ifndef __WIN32_BIBUTILS_CONFIG_H__
#define __WIN32_BIBUTILS_CONFIG_H__

#undef HAVE_DESIGNATED_INITIALIZER_GNU_EXTENSION

#define countof(array)					( sizeof(array) / sizeof(array[0]) )

#define SET_ARRAY_DEFAULT_VALUE(array, default_value)			\
	{															\
		for (int ii = 0; ii < countof(array); ii++) {			\
			if ((array)[ii] == 0) {								\
				(array)[ii] = (default_value);					\
			}													\
		}														\
	}



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
