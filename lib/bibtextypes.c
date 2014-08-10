/*
 * bibtypes.c
 *
 * Copyright (c) Chris Putnam 2003-2014
 *
 * Program and source code released under the GPL version 2
 *
 */
#include <stdio.h>
#include "fields.h"
#include "reftypes.h"

/* Entry types from the IEEEtran Bibtex Style + others as observed */

/*
 * Journal Article
 */
static lookups article[] = {
	{ "author",       "AUTHOR",    PERSON, LEVEL_MAIN },
	{ "translator",   "TRANSLATOR",PERSON, LEVEL_MAIN },
	{ "title",        "TITLE",     TITLE,  LEVEL_MAIN },
	{ "year",         "PARTYEAR",  SIMPLE, LEVEL_MAIN },
	{ "month",        "PARTMONTH", SIMPLE, LEVEL_MAIN },
	{ "day",          "PARTDAY",   SIMPLE, LEVEL_MAIN },
	{ "volume",       "VOLUME",    SIMPLE, LEVEL_MAIN },
	{ "pages",        "PAGES",     PAGES,  LEVEL_MAIN },
	{ "number",       "ISSUE",     SIMPLE, LEVEL_MAIN },
	{ "issue",        "ISSUE",     SIMPLE, LEVEL_MAIN },
	{ "journal",      "TITLE",     TITLE,  LEVEL_HOST },
	{ "publisher",    "PUBLISHER", SIMPLE, LEVEL_HOST },
	{ "address",      "ADDRESS",   SIMPLE, LEVEL_HOST },
	{ "issn",         "ISSN",      SIMPLE, LEVEL_HOST },
	{ "abstract",     "ABSTRACT",  SIMPLE, LEVEL_MAIN },
	{ "contents",     "CONTENTS",  SIMPLE, LEVEL_MAIN },
	{ "language",     "LANGUAGE",  SIMPLE, LEVEL_MAIN },
	{ "note",         "NOTES",     BT_NOTE, LEVEL_MAIN },
	{ "annote",       "ANNOTE",    SIMPLE, LEVEL_MAIN },
	{ "location",     "LOCATION",  SIMPLE, LEVEL_MAIN },
	{ "ftp",          "",      BT_URL, LEVEL_MAIN },
	{ "url",          "",      BT_URL, LEVEL_MAIN },
	{ "pdf",          "FILEATTACH",SIMPLE, LEVEL_MAIN },
	{ "sentelink",    "FILEATTACH",BT_SENTE, LEVEL_MAIN },
	{ "file",         "FILEATTACH",LINKEDFILE,   LEVEL_MAIN },
	{ "howpublished", "",       HOWPUBLISHED, LEVEL_MAIN },
	{ "doi",          "DOI",       SIMPLE, LEVEL_MAIN },
	{ "key",          "BIBKEY",       SIMPLE, LEVEL_MAIN },
	{ "refnum",       "REFNUM",    SIMPLE, LEVEL_MAIN },
	{ "crossref",     "CROSSREF",  SIMPLE, LEVEL_MAIN },
	{ "keywords",     "KEYWORD",   KEYWORD, LEVEL_MAIN },
	{ "",             "INTERNAL_TYPE|ARTICLE",           ALWAYS, LEVEL_MAIN },
	{ "",             "ISSUANCE|continuing",     ALWAYS, LEVEL_HOST },
	{ "",             "RESOURCE|text",           ALWAYS, LEVEL_MAIN },
	{ "",             "NGENRE|journal article",  ALWAYS, LEVEL_MAIN },
	{ "",             "GENRE|periodical",        ALWAYS, LEVEL_HOST },
	{ "",             "NGENRE|academic journal", ALWAYS, LEVEL_HOST }
};

/* Book */

static lookups book[] = {
	{ "author",       "AUTHOR",    PERSON, LEVEL_MAIN },
	{ "translator",   "TRANSLATOR",PERSON, LEVEL_MAIN },
	{ "title",        "TITLE",     TITLE,  LEVEL_MAIN },
	{ "booktitle",    "TITLE",     TITLE,  LEVEL_MAIN },
	{ "series",       "TITLE",     TITLE,  LEVEL_HOST },
	{ "publisher",    "PUBLISHER", SIMPLE, LEVEL_MAIN },
	{ "organization", "ORGANIZER:CORP", BT_ORG, LEVEL_MAIN },
	{ "address",      "ADDRESS",   SIMPLE, LEVEL_MAIN },
	{ "editor",       "EDITOR",    PERSON, LEVEL_MAIN },
	{ "year",         "YEAR",      SIMPLE, LEVEL_MAIN },
	{ "month",        "MONTH",     SIMPLE, LEVEL_MAIN },
	{ "day",          "DAY",       SIMPLE, LEVEL_MAIN },
	{ "volume",       "VOLUME",    SIMPLE, LEVEL_MAIN },
	{ "number",       "NUMBER",    SIMPLE, LEVEL_MAIN },
	{ "isbn",         "ISBN",      SIMPLE, LEVEL_MAIN },
	{ "lccn",         "LCCN",      SIMPLE, LEVEL_MAIN },
	{ "edition",      "EDITION",   SIMPLE, LEVEL_MAIN },
	{ "abstract",     "ABSTRACT",  SIMPLE, LEVEL_MAIN },
	{ "contents",     "CONTENTS",  SIMPLE, LEVEL_MAIN },
	{ "language",     "LANGUAGE",  SIMPLE, LEVEL_MAIN },
	{ "location",     "LOCATION",  SIMPLE, LEVEL_MAIN },
	{ "note",         "NOTES",     BT_NOTE, LEVEL_MAIN },
	{ "annote",       "ANNOTE",    SIMPLE, LEVEL_MAIN },
	{ "type",         "GENRE",     SIMPLE, LEVEL_MAIN },
	{ "key",          "BIBKEY",    SIMPLE, LEVEL_MAIN },
	{ "ftp",          "",       BT_URL, LEVEL_MAIN },
	{ "url",          "",       BT_URL, LEVEL_MAIN },
	{ "pdf",          "FILEATTACH",SIMPLE, LEVEL_MAIN },
	{ "sentelink",    "FILEATTACH",BT_SENTE, LEVEL_MAIN },
	{ "file",         "FILEATTACH",LINKEDFILE,   LEVEL_MAIN },
	{ "address",      "ADDRESS",   SIMPLE, LEVEL_MAIN },
	{ "howpublished", "",       HOWPUBLISHED, LEVEL_MAIN },
	{ "doi",          "DOI",       SIMPLE, LEVEL_MAIN },
	{ "refnum",       "REFNUM",    SIMPLE, LEVEL_MAIN },
	{ "crossref",     "CROSSREF",  SIMPLE, LEVEL_MAIN },
	{ "keywords",     "KEYWORD",   KEYWORD, LEVEL_MAIN },
	{ "refnum",       "REFNUM",    SIMPLE, LEVEL_MAIN },
	{ "",             "INTERNAL_TYPE|BOOK",   ALWAYS, LEVEL_MAIN },
	{ "",             "RESOURCE|text",        ALWAYS, LEVEL_MAIN },
	{ "",             "ISSUANCE|monographic", ALWAYS, LEVEL_MAIN },
	{ "",             "GENRE|book",           ALWAYS, LEVEL_MAIN }
};

/* Technical reports */

static lookups report[] = {
	{ "author",       "AUTHOR",       PERSON, LEVEL_MAIN },
	{ "translator",   "TRANSLATOR",PERSON, LEVEL_MAIN },
	{ "title",        "TITLE",        TITLE,  LEVEL_MAIN },
	{ "booktitle",    "TITLE",        TITLE,  LEVEL_MAIN },
	{ "series",       "TITLE",        TITLE,  LEVEL_HOST },
	{ "editor",       "EDITOR",       PERSON, LEVEL_MAIN },
	{ "publisher",    "PUBLISHER",    SIMPLE, LEVEL_MAIN },
	{ "institution",  "PUBLISHER",    SIMPLE, LEVEL_MAIN },
	{ "address",      "ADDRESS",      SIMPLE, LEVEL_MAIN },
	{ "year",         "YEAR",         SIMPLE, LEVEL_MAIN },
	{ "month",        "MONTH",        SIMPLE, LEVEL_MAIN },
	{ "day",          "DAY",          SIMPLE, LEVEL_MAIN },
	{ "number",       "NUMBER",       SIMPLE, LEVEL_MAIN },
	{ "isbn",         "ISBN",         SIMPLE, LEVEL_MAIN },
	{ "lccn",         "LCCN",         SIMPLE, LEVEL_MAIN },
	{ "abstract",     "ABSTRACT",     SIMPLE, LEVEL_MAIN },
	{ "contents",     "CONTENTS",     SIMPLE, LEVEL_MAIN },
	{ "language",     "LANGUAGE",     SIMPLE, LEVEL_MAIN },
	{ "location",     "LOCATION",     SIMPLE, LEVEL_MAIN },
	{ "note",         "NOTES",        BT_NOTE, LEVEL_MAIN },
	{ "annote",       "ANNOTE",    SIMPLE, LEVEL_MAIN },
	{ "key",          "BIBKEY",          SIMPLE, LEVEL_MAIN },
	{ "doi",          "DOI",          SIMPLE, LEVEL_MAIN },
	{ "ftp",          "",          BT_URL, LEVEL_MAIN },
	{ "url",          "",          BT_URL, LEVEL_MAIN },
	{ "pdf",          "FILEATTACH",SIMPLE, LEVEL_MAIN },
	{ "sentelink",    "FILEATTACH",BT_SENTE, LEVEL_MAIN },
	{ "file",         "FILEATTACH",LINKEDFILE,   LEVEL_MAIN },
	{ "howpublished", "",          HOWPUBLISHED, LEVEL_MAIN },
	{ "refnum",    "REFNUM",          SIMPLE, LEVEL_MAIN },
	{ "crossref",     "CROSSREF",  SIMPLE, LEVEL_MAIN },
	{ "type",      "GENRE",            SIMPLE, LEVEL_MAIN },
	{ "keywords",     "KEYWORD",   KEYWORD, LEVEL_MAIN },
	{ "",         "INTERNAL_TYPE|REPORT", ALWAYS, LEVEL_MAIN },
	{ "",         "RESOURCE|text",        ALWAYS, LEVEL_MAIN },
	{ "",         "GENRE|report",         ALWAYS, LEVEL_MAIN }
};

static lookups manual[] = {
	{ "author",    "AUTHOR",    PERSON, LEVEL_MAIN },
	{ "translator",   "TRANSLATOR",PERSON, LEVEL_MAIN },
	{ "title",     "TITLE",     TITLE,  LEVEL_MAIN },
	{ "booktitle", "TITLE",     TITLE,  LEVEL_MAIN },
	{ "editor",    "EDITOR",    PERSON, LEVEL_MAIN },
	{ "publisher", "PUBLISHER", SIMPLE, LEVEL_MAIN },
	{ "organization", "ORGANIZER:CORP", BT_ORG, LEVEL_MAIN },
	{ "address",   "ADDRESS",   SIMPLE, LEVEL_MAIN },
	{ "year",      "YEAR",      SIMPLE, LEVEL_MAIN },
	{ "month",     "MONTH",     SIMPLE, LEVEL_MAIN },
	{ "day",       "DAY",       SIMPLE, LEVEL_MAIN },
	{ "isbn",      "ISBN",      SIMPLE, LEVEL_MAIN },
	{ "lccn",      "LCCN",      SIMPLE, LEVEL_MAIN },
	{ "edition",   "EDITION",   SIMPLE, LEVEL_MAIN },
	{ "abstract",  "ABSTRACT",  SIMPLE, LEVEL_MAIN },
	{ "contents",  "CONTENTS",  SIMPLE, LEVEL_MAIN },
	{ "location",     "LOCATION",     SIMPLE, LEVEL_MAIN },
	{ "note",         "NOTES",        BT_NOTE, LEVEL_MAIN },
	{ "annote",       "ANNOTE",    SIMPLE, LEVEL_MAIN },
	{ "key",          "BIBKEY",          SIMPLE, LEVEL_MAIN },
	{ "doi",       "DOI",       SIMPLE, LEVEL_MAIN },
	{ "ftp",       "",       BT_URL, LEVEL_MAIN },
	{ "url",       "",       BT_URL, LEVEL_MAIN },
	{ "pdf",          "FILEATTACH",SIMPLE, LEVEL_MAIN },
	{ "sentelink",    "FILEATTACH",BT_SENTE, LEVEL_MAIN },
	{ "file",         "FILEATTACH",LINKEDFILE,   LEVEL_MAIN },
	{ "howpublished", "",    HOWPUBLISHED, LEVEL_MAIN },
	{ "language",     "LANGUAGE",  SIMPLE, LEVEL_MAIN },
	{ "refnum",    "REFNUM",    SIMPLE, LEVEL_MAIN },
	{ "crossref",     "CROSSREF",  SIMPLE, LEVEL_MAIN },
	{ "keywords",     "KEYWORD",   KEYWORD, LEVEL_MAIN },
	{ "",         "INTERNAL_TYPE|REPORT", ALWAYS, LEVEL_MAIN },
	{ "",         "RESOURCE|text",        ALWAYS, LEVEL_MAIN },
	{ "",         "GENRE|instruction",    ALWAYS, LEVEL_MAIN }
};

/* Part of a book (e.g. chapter or section) */

static lookups inbook[] = {
	{ "author",    "AUTHOR",    PERSON, LEVEL_MAIN },
	{ "translator",   "TRANSLATOR",PERSON, LEVEL_MAIN },
	{ "editor",    "EDITOR",    PERSON, LEVEL_HOST },
	{ "chapter",   "CHAPTER",   SIMPLE, LEVEL_MAIN },
	{ "title",     "TITLE",     TITLE,  LEVEL_HOST },
	{ "booktitle", "TITLE",     TITLE,  LEVEL_HOST },
	{ "series",    "TITLE",     TITLE,  LEVEL_SERIES },
	{ "publisher", "PUBLISHER", SIMPLE, LEVEL_HOST },
	{ "address",   "ADDRESS",   SIMPLE, LEVEL_HOST },
	{ "year",      "YEAR",      SIMPLE, LEVEL_HOST },
	{ "month",     "MONTH",     SIMPLE, LEVEL_HOST },
	{ "day",       "DAY",       SIMPLE, LEVEL_HOST },
	{ "volume",    "VOLUME",    SIMPLE, LEVEL_SERIES },
	{ "number",    "NUMBER",    SIMPLE, LEVEL_SERIES },
	{ "pages",     "PAGES",     PAGES,  LEVEL_HOST },
	{ "isbn",      "ISBN",      SIMPLE, LEVEL_HOST },
	{ "lccn",      "LCCN",      SIMPLE, LEVEL_HOST },
	{ "edition",   "EDITION",   SIMPLE, LEVEL_HOST },
	{ "abstract",  "ABSTRACT",  SIMPLE, LEVEL_MAIN },
	{ "contents",  "CONTENTS",  SIMPLE, LEVEL_HOST },
	{ "language",     "LANGUAGE",     SIMPLE, LEVEL_MAIN },
	{ "location",     "LOCATION",     SIMPLE, LEVEL_HOST },
	{ "doi",       "DOI",       SIMPLE, LEVEL_MAIN },
	{ "ftp",       "",       BT_URL, LEVEL_MAIN },
	{ "url",       "",       BT_URL, LEVEL_MAIN },
	{ "pdf",          "FILEATTACH",SIMPLE, LEVEL_MAIN },
	{ "sentelink",    "FILEATTACH",BT_SENTE, LEVEL_MAIN },
	{ "file",         "FILEATTACH",LINKEDFILE,   LEVEL_MAIN },
	{ "howpublished", "",    HOWPUBLISHED, LEVEL_MAIN },
	{ "refnum",    "REFNUM",    SIMPLE, LEVEL_MAIN },
	{ "crossref",     "CROSSREF",  SIMPLE, LEVEL_MAIN },
	{ "type",      "GENRE",      SIMPLE, LEVEL_MAIN },
	{ "note",         "NOTES",        BT_NOTE, LEVEL_MAIN },
	{ "annote",       "ANNOTE",    SIMPLE, LEVEL_MAIN },
	{ "key",          "BIBKEY",          SIMPLE, LEVEL_MAIN },
	{ "keywords",     "KEYWORD",   KEYWORD, LEVEL_MAIN },
	{ "",         "INTERNAL_TYPE|INBOOK", ALWAYS, LEVEL_MAIN },
	{ "",         "RESOURCE|text",        ALWAYS, LEVEL_MAIN },
	{ "",         "ISSUANCE|monographic", ALWAYS, LEVEL_HOST },
	{ "",         "NGENRE|book chapter",  ALWAYS, LEVEL_MAIN },
	{ "",         "GENRE|book",           ALWAYS, LEVEL_HOST }
};

/* References of papers in conference proceedings */

static lookups inproceedings[] = {
	{ "author",    "AUTHOR",    PERSON, LEVEL_MAIN },
	{ "translator",   "TRANSLATOR",PERSON, LEVEL_MAIN },
	{ "editor",    "EDITOR",    PERSON, LEVEL_HOST },
	{ "title",     "TITLE",     TITLE,  LEVEL_MAIN },
	{ "booktitle", "TITLE",     TITLE,  LEVEL_HOST },
	{ "series",    "TITLE",     TITLE,  LEVEL_SERIES },
	{ "chapter",   "CHAPTER",   SIMPLE, LEVEL_MAIN },
	{ "publisher", "PUBLISHER", SIMPLE, LEVEL_HOST },
	{ "organization", "ORGANIZER:CORP", BT_ORG, LEVEL_HOST },
	{ "address",   "ADDRESS",   SIMPLE, LEVEL_HOST },
	{ "year",      "PARTYEAR",  SIMPLE, LEVEL_MAIN },
	{ "month",     "PARTMONTH", SIMPLE, LEVEL_MAIN },
	{ "day",       "PARTDAY",   SIMPLE, LEVEL_MAIN },
	{ "volume",    "VOLUME",    SIMPLE, LEVEL_MAIN },
	{ "number",    "NUMBER",    SIMPLE, LEVEL_MAIN },
	{ "pages",     "PAGES",     PAGES,  LEVEL_MAIN },
	{ "isbn",      "ISBN",      SIMPLE, LEVEL_HOST },
	{ "lccn",      "LCCN",      SIMPLE, LEVEL_HOST },
	{ "abstract",  "ABSTRACT",  SIMPLE, LEVEL_MAIN },
	{ "contents",  "CONTENTS",  SIMPLE, LEVEL_HOST },
	{ "language",     "LANGUAGE",     SIMPLE, LEVEL_MAIN },
	{ "paper",     "PAPER",     SIMPLE, LEVEL_MAIN },
	{ "location",     "LOCATION",     SIMPLE, LEVEL_HOST },
	{ "doi",       "DOI",       SIMPLE, LEVEL_MAIN },
	{ "ftp",       "",       BT_URL, LEVEL_MAIN },
	{ "url",       "",       BT_URL, LEVEL_MAIN },
	{ "pdf",          "FILEATTACH",SIMPLE, LEVEL_MAIN },
	{ "sentelink",    "FILEATTACH",BT_SENTE, LEVEL_MAIN },
	{ "file",         "FILEATTACH",LINKEDFILE,   LEVEL_MAIN },
	{ "type",      "GENRE",      SIMPLE, LEVEL_MAIN },
	{ "note",         "NOTES",        BT_NOTE, LEVEL_MAIN },
	{ "annote",       "ANNOTE",    SIMPLE, LEVEL_MAIN },
	{ "key",          "BIBKEY",          SIMPLE, LEVEL_MAIN },
	{ "howpublished", "",    HOWPUBLISHED, LEVEL_MAIN },
	{ "refnum",    "REFNUM",    SIMPLE, LEVEL_MAIN },
	{ "crossref",     "CROSSREF",  SIMPLE, LEVEL_MAIN },
	{ "keywords",     "KEYWORD",   KEYWORD, LEVEL_MAIN },
	{ "",         "INTERNAL_TYPE|INPROCEEDINGS",  ALWAYS, LEVEL_MAIN },
	{ "",         "RESOURCE|text",                ALWAYS, LEVEL_MAIN },
	{ "",         "GENRE|conference publication", ALWAYS, LEVEL_HOST }
};

/* Used for a section of a book with its own title */

static lookups incollection[] = {
	{ "author",    "AUTHOR",    PERSON, LEVEL_MAIN },
	{ "translator",   "TRANSLATOR",PERSON, LEVEL_MAIN },
	{ "editor",    "EDITOR",    PERSON, LEVEL_HOST },
	{ "title",     "TITLE",     TITLE,  LEVEL_MAIN },
	{ "chapter",   "CHAPTER",   SIMPLE, LEVEL_MAIN },
	{ "booktitle", "TITLE",     TITLE,  LEVEL_HOST },
	{ "series",    "TITLE",     TITLE,  LEVEL_SERIES },
	{ "publisher", "PUBLISHER", SIMPLE, LEVEL_HOST },
	{ "address",   "ADDRESS",   SIMPLE, LEVEL_HOST },
	{ "year",      "YEAR",      SIMPLE, LEVEL_HOST },
	{ "month",     "MONTH",     SIMPLE, LEVEL_HOST },
	{ "day",       "DAY",       SIMPLE, LEVEL_HOST },
	{ "volume",    "VOLUME",    SIMPLE, LEVEL_MAIN },
	{ "number",    "NUMBER",    SIMPLE, LEVEL_MAIN },
	{ "pages",     "PAGES",     PAGES,  LEVEL_MAIN },
	{ "isbn",      "ISBN",      SIMPLE, LEVEL_HOST },
	{ "lccn",      "LCCN",      SIMPLE, LEVEL_HOST },
	{ "edition",   "EDITION",   SIMPLE, LEVEL_HOST },
	{ "abstract",  "ABSTRACT",  SIMPLE, LEVEL_MAIN },
	{ "contents",  "CONTENTS",  SIMPLE, LEVEL_HOST },
	{ "language",     "LANGUAGE",     SIMPLE, LEVEL_MAIN },
	{ "type",      "GENRE",      SIMPLE, LEVEL_MAIN },
	{ "note",         "NOTES",        BT_NOTE, LEVEL_MAIN },
	{ "annote",       "ANNOTE",    SIMPLE, LEVEL_MAIN },
	{ "key",          "BIBKEY",          SIMPLE, LEVEL_MAIN },
	{ "doi",       "DOI",       SIMPLE, LEVEL_MAIN },
	{ "ftp",       "",       BT_URL, LEVEL_MAIN },
	{ "url",       "",       BT_URL, LEVEL_MAIN },
	{ "pdf",          "FILEATTACH",SIMPLE, LEVEL_MAIN },
	{ "sentelink",    "FILEATTACH",BT_SENTE, LEVEL_MAIN },
	{ "file",         "FILEATTACH",LINKEDFILE,   LEVEL_MAIN },
	{ "location",     "LOCATION",     SIMPLE, LEVEL_HOST },
	{ "howpublished", "",    HOWPUBLISHED, LEVEL_MAIN },
	{ "refnum",    "REFNUM",    SIMPLE, LEVEL_MAIN },
	{ "crossref",     "CROSSREF",  SIMPLE, LEVEL_MAIN },
	{ "keywords",     "KEYWORD",   KEYWORD, LEVEL_MAIN },
	{ "",         "INTERNAL_TYPE|INCOLLECTION", ALWAYS, LEVEL_MAIN },
	{ "",         "RESOURCE|text",              ALWAYS, LEVEL_MAIN },
	{ "",         "ISSUANCE|monographic",       ALWAYS, LEVEL_MAIN },
	{ "",         "GENRE|collection",           ALWAYS, LEVEL_HOST }
};

/* Proceedings */

static lookups proceedings[] = {
	{ "author",    "AUTHOR",    PERSON, LEVEL_MAIN },
	{ "translator",   "TRANSLATOR",PERSON, LEVEL_MAIN },
	{ "editor",    "EDITOR",    PERSON, LEVEL_MAIN },
	{ "title",     "TITLE",     TITLE,  LEVEL_MAIN },
	{ "booktitle", "TITLE",     TITLE,  LEVEL_MAIN },
	{ "series",    "TITLE",     TITLE,  LEVEL_HOST },
	{ "publisher", "PUBLISHER", SIMPLE, LEVEL_MAIN },
	{ "organization", "ORGANIZER:CORP", BT_ORG, LEVEL_MAIN },
	{ "address",   "ADDRESS",   SIMPLE, LEVEL_MAIN },
	{ "year",      "YEAR",      SIMPLE, LEVEL_MAIN },
	{ "month",     "MONTH",     SIMPLE, LEVEL_MAIN },
	{ "day",       "DAY",       SIMPLE, LEVEL_MAIN },
	{ "volume",    "VOLUME",    SIMPLE, LEVEL_MAIN },
	{ "number",    "NUMBER",    SIMPLE, LEVEL_MAIN },
	{ "pages",     "PAGES",     PAGES,  LEVEL_MAIN },
	{ "isbn",      "ISBN",      SIMPLE, LEVEL_MAIN },
	{ "lccn",      "LCCN",      SIMPLE, LEVEL_MAIN },
	{ "abstract",  "ABSTRACT",  SIMPLE, LEVEL_MAIN },
	{ "contents",  "CONTENTS",  SIMPLE, LEVEL_MAIN },
	{ "doi",       "DOI",       SIMPLE, LEVEL_MAIN },
	{ "ftp",       "",       BT_URL, LEVEL_MAIN },
	{ "url",       "",       BT_URL, LEVEL_MAIN },
	{ "pdf",          "FILEATTACH",SIMPLE, LEVEL_MAIN },
	{ "sentelink",    "FILEATTACH",BT_SENTE, LEVEL_MAIN },
	{ "file",         "FILEATTACH",LINKEDFILE,   LEVEL_MAIN },
	{ "language",     "LANGUAGE",     SIMPLE, LEVEL_MAIN },
	{ "howpublished", "",    HOWPUBLISHED, LEVEL_MAIN },
	{ "location",     "LOCATION",     SIMPLE, LEVEL_MAIN },
	{ "note",         "NOTES",        BT_NOTE, LEVEL_MAIN },
	{ "annote",       "ANNOTE",    SIMPLE, LEVEL_MAIN },
	{ "key",          "BIBKEY",          SIMPLE, LEVEL_MAIN },
	{ "refnum",    "REFNUM",    SIMPLE, LEVEL_MAIN },
	{ "crossref",     "CROSSREF",  SIMPLE, LEVEL_MAIN },
	{ "keywords",     "KEYWORD",   KEYWORD, LEVEL_MAIN },
	{ "",         "INTERNAL_TYPE|PROCEEDINGS",    ALWAYS, LEVEL_MAIN },
	{ "",         "RESOURCE|text",                ALWAYS, LEVEL_MAIN },
	{ "",         "GENRE|conference publication", ALWAYS, LEVEL_MAIN }
};

static lookups phds[] = {
	{ "author",    "AUTHOR",    PERSON, LEVEL_MAIN },
	{ "translator",   "TRANSLATOR",PERSON, LEVEL_MAIN },
	{ "title",     "TITLE",     TITLE,  LEVEL_MAIN },
	{ "year",      "YEAR",      SIMPLE, LEVEL_MAIN },
	{ "month",     "MONTH",     SIMPLE, LEVEL_MAIN },
	{ "day",       "DAY",       SIMPLE, LEVEL_MAIN },
	{ "school",    "DEGREEGRANTOR:ASIS",SIMPLE, LEVEL_MAIN },
	{ "address",   "ADDRESS",   SIMPLE, LEVEL_MAIN },
	{ "abstract",  "ABSTRACT",  SIMPLE, LEVEL_MAIN },
	{ "contents",  "CONTENTS",  SIMPLE, LEVEL_MAIN },
	{ "doi",       "DOI",       SIMPLE, LEVEL_MAIN },
	{ "ftp",       "",       BT_URL, LEVEL_MAIN },
	{ "url",       "",       BT_URL, LEVEL_MAIN },
	{ "pdf",          "FILEATTACH",SIMPLE, LEVEL_MAIN },
	{ "sentelink",    "FILEATTACH",BT_SENTE, LEVEL_MAIN },
	{ "file",         "FILEATTACH",LINKEDFILE,   LEVEL_MAIN },
	{ "howpublished", "" ,   HOWPUBLISHED, LEVEL_MAIN },
	{ "language",     "LANGUAGE",     SIMPLE, LEVEL_MAIN },
	{ "location",     "LOCATION",     SIMPLE, LEVEL_MAIN },
	{ "note",         "NOTES",        BT_NOTE, LEVEL_MAIN },
	{ "annote",       "ANNOTE",    SIMPLE, LEVEL_MAIN },
	{ "key",          "BIBKEY",          SIMPLE, LEVEL_MAIN },
	{ "type",         "GENRE",         SIMPLE, LEVEL_MAIN },
	{ "refnum",    "REFNUM",    SIMPLE, LEVEL_MAIN },
	{ "crossref",     "CROSSREF",  SIMPLE, LEVEL_MAIN },
	{ "keywords",     "KEYWORD",   KEYWORD, LEVEL_MAIN },
	{ "",         "INTERNAL_TYPE|THESIS", ALWAYS,  LEVEL_MAIN },
	{ "",         "RESOURCE|text",        ALWAYS,  LEVEL_MAIN },
	{ "",         "GENRE|thesis",         ALWAYS,  LEVEL_MAIN },
	{ "",         "NGENRE|Ph.D. thesis",  DEFAULT, LEVEL_MAIN }
};

static lookups masters[] = {
	{ "author",    "AUTHOR",    PERSON, LEVEL_MAIN },
	{ "translator",   "TRANSLATOR",PERSON, LEVEL_MAIN },
	{ "title",     "TITLE",     TITLE,  LEVEL_MAIN },
	{ "year",      "YEAR",      SIMPLE, LEVEL_MAIN },
	{ "month",     "MONTH",     SIMPLE, LEVEL_MAIN },
	{ "day",       "DAY",       SIMPLE, LEVEL_MAIN },
	{ "school",    "DEGREEGRANTOR:ASIS",SIMPLE, LEVEL_MAIN },
	{ "address",   "ADDRESS",   SIMPLE, LEVEL_MAIN },
	{ "abstract",  "ABSTRACT",  SIMPLE, LEVEL_MAIN },
	{ "contents",  "CONTENTS",  SIMPLE, LEVEL_MAIN },
	{ "doi",       "DOI",       SIMPLE, LEVEL_MAIN },
	{ "ftp",       "",       BT_URL, LEVEL_MAIN },
	{ "url",       "",       BT_URL, LEVEL_MAIN },
	{ "pdf",          "FILEATTACH",SIMPLE, LEVEL_MAIN },
	{ "sentelink",    "FILEATTACH",BT_SENTE, LEVEL_MAIN },
	{ "file",         "FILEATTACH",LINKEDFILE,   LEVEL_MAIN },
	{ "language",     "LANGUAGE",     SIMPLE, LEVEL_MAIN },
	{ "location",     "LOCATION",     SIMPLE, LEVEL_MAIN },
	{ "note",         "NOTES",        BT_NOTE, LEVEL_MAIN },
	{ "annote",       "ANNOTE",    SIMPLE, LEVEL_MAIN },
	{ "key",          "BIBKEY",          SIMPLE, LEVEL_MAIN },
	{ "type",         "GENRE",         SIMPLE, LEVEL_MAIN },
	{ "howpublished", "",    HOWPUBLISHED, LEVEL_MAIN },
	{ "refnum",    "REFNUM",    SIMPLE, LEVEL_MAIN },
	{ "crossref",     "CROSSREF",  SIMPLE, LEVEL_MAIN },
	{ "keywords",     "KEYWORD",   KEYWORD, LEVEL_MAIN },
	{ "",         "INTERNAL_TYPE|THESIS",  ALWAYS,  LEVEL_MAIN },
	{ "",         "RESOURCE|text",         ALWAYS,  LEVEL_MAIN },
	{ "",         "GENRE|thesis",          ALWAYS,  LEVEL_MAIN },
	{ "",         "NGENRE|Masters thesis", DEFAULT, LEVEL_MAIN }
};

/* Unpublished */

static lookups unpublished[] = {
	{ "author",    "AUTHOR",    PERSON, LEVEL_MAIN },
	{ "translator",   "TRANSLATOR",PERSON, LEVEL_MAIN },
	{ "title",     "TITLE",     TITLE,  LEVEL_MAIN },
	{ "booktitle", "TITLE",     TITLE,  LEVEL_MAIN },
	{ "publisher", "PUBLISHER", SIMPLE, LEVEL_MAIN },
	{ "address",   "ADDRESS",   SIMPLE, LEVEL_MAIN },
	{ "editor",    "EDITOR",    PERSON, LEVEL_MAIN },
	{ "year",      "YEAR",      SIMPLE, LEVEL_MAIN },
	{ "month",     "MONTH",     SIMPLE, LEVEL_MAIN },
	{ "day",       "DAY",       SIMPLE, LEVEL_MAIN },
	{ "abstract",  "ABSTRACT",  SIMPLE, LEVEL_MAIN },
	{ "contents",  "CONTENTS",  SIMPLE, LEVEL_MAIN },
	{ "doi",       "DOI",       SIMPLE, LEVEL_MAIN },
	{ "ftp",       "",       BT_URL, LEVEL_MAIN },
	{ "url",       "",       BT_URL, LEVEL_MAIN },
	{ "pdf",          "FILEATTACH",SIMPLE, LEVEL_MAIN },
	{ "sentelink",    "FILEATTACH",BT_SENTE, LEVEL_MAIN },
	{ "file",         "FILEATTACH",LINKEDFILE,   LEVEL_MAIN },
	{ "language",     "LANGUAGE",     SIMPLE, LEVEL_MAIN },
	{ "howpublished", "",    HOWPUBLISHED, LEVEL_MAIN },
	{ "location",     "LOCATION",     SIMPLE, LEVEL_MAIN },
	{ "note",         "NOTES",        BT_NOTE, LEVEL_MAIN },
	{ "annote",       "ANNOTE",    SIMPLE, LEVEL_MAIN },
	{ "key",          "BIBKEY",          SIMPLE, LEVEL_MAIN },
	{ "refnum",    "REFNUM",    SIMPLE, LEVEL_MAIN },
	{ "crossref",     "CROSSREF",  SIMPLE, LEVEL_MAIN },
	{ "keywords",     "KEYWORD",   KEYWORD, LEVEL_MAIN },
	{ "",         "INTERNAL_TYPE|BOOK", ALWAYS, LEVEL_MAIN },
	{ "",         "RESOURCE|text",      ALWAYS, LEVEL_MAIN },
	{ "",         "GENRE|unpublished",  ALWAYS, LEVEL_MAIN }
};

/*
 * For Published Standards
 */
static lookups standard[] = {
	{ "author",    "AUTHOR",    PERSON, LEVEL_MAIN },
	{ "translator",   "TRANSLATOR",PERSON, LEVEL_MAIN },
	{ "organization", "ORGANIZER:CORP", BT_ORG, LEVEL_MAIN },
	{ "institution", "AUTHOR:CORP", SIMPLE, LEVEL_MAIN },
	{ "title",     "TITLE",     TITLE,  LEVEL_MAIN },
	{ "booktitle", "TITLE",     TITLE,  LEVEL_MAIN },
	{ "publisher", "PUBLISHER", SIMPLE, LEVEL_MAIN },
	{ "address",   "ADDRESS",   SIMPLE, LEVEL_MAIN },
	{ "editor",    "EDITOR",    PERSON, LEVEL_MAIN },
	{ "year",      "YEAR",      SIMPLE, LEVEL_MAIN },
	{ "month",     "MONTH",     SIMPLE, LEVEL_MAIN },
	{ "day",       "DAY",       SIMPLE, LEVEL_MAIN },
	{ "isbn",      "ISBN",      SIMPLE, LEVEL_MAIN },
	{ "lccn",      "LCCN",      SIMPLE, LEVEL_MAIN },
	{ "abstract",  "ABSTRACT",  SIMPLE, LEVEL_MAIN },
	{ "contents",  "CONTENTS",  SIMPLE, LEVEL_MAIN },
	{ "doi",       "DOI",       SIMPLE, LEVEL_MAIN },
	{ "ftp",       "",      BT_URL, LEVEL_MAIN },
	{ "url",       "",      BT_URL, LEVEL_MAIN },
	{ "pdf",          "FILEATTACH",SIMPLE, LEVEL_MAIN },
	{ "sentelink",    "FILEATTACH",BT_SENTE, LEVEL_MAIN },
	{ "file",         "FILEATTACH",LINKEDFILE,   LEVEL_MAIN },
	{ "howpublished", "",    HOWPUBLISHED, LEVEL_MAIN },
	{ "language",     "LANGUAGE",     SIMPLE, LEVEL_MAIN },
	{ "refnum",    "REFNUM",    SIMPLE, LEVEL_MAIN },
	{ "type",      "GENRE",      SIMPLE, LEVEL_MAIN },
	{ "number",    "NUMBER",      TITLE,  LEVEL_MAIN },
	{ "revision",  "REVISION",    TITLE,  LEVEL_MAIN },
	{ "location",     "LOCATION",     SIMPLE, LEVEL_MAIN },
	{ "note",         "NOTES",        BT_NOTE, LEVEL_MAIN },
	{ "annote",       "ANNOTE",    SIMPLE, LEVEL_MAIN },
	{ "key",          "BIBKEY",          SIMPLE, LEVEL_MAIN },
	{ "keywords",     "KEYWORD",   KEYWORD, LEVEL_MAIN },
	{ "crossref",     "CROSSREF",  SIMPLE, LEVEL_MAIN },
	{ "",         "RESOURCE|text",          ALWAYS, LEVEL_MAIN },
	{ "",         "INTERNAL_TYPE|STANDARD", ALWAYS, LEVEL_MAIN }
};

/*
 * For Journals and Magazines
 */
static lookups periodical[] = {
	{ "title",        "TITLE",       TITLE,  LEVEL_MAIN },
	{ "translator",   "TRANSLATOR",PERSON, LEVEL_MAIN },
	{ "series",       "TITLE",       TITLE,  LEVEL_HOST },
	{ "publisher",    "PUBLISHER",   SIMPLE, LEVEL_MAIN },
	{ "address",      "ADDRESS",     SIMPLE, LEVEL_MAIN },
	{ "editor",       "EDITOR",      PERSON, LEVEL_MAIN },
	{ "year",         "YEAR",        SIMPLE, LEVEL_MAIN },
	{ "month",        "MONTH",       SIMPLE, LEVEL_MAIN },
	{ "day",          "DAY",         SIMPLE, LEVEL_MAIN },
	{ "issn",         "ISSN",        SIMPLE, LEVEL_MAIN },
	{ "abstract",     "ABSTRACT",    SIMPLE, LEVEL_MAIN },
	{ "volume",       "VOLUME",      TITLE,  LEVEL_MAIN },
	{ "number",       "NUMBER",      TITLE,  LEVEL_MAIN },
	{ "contents",     "CONTENTS",    SIMPLE, LEVEL_MAIN },
	{ "doi",          "DOI",         SIMPLE, LEVEL_MAIN },
	{ "ftp",          "",        BT_URL, LEVEL_MAIN },
	{ "url",          "",        BT_URL, LEVEL_MAIN },
	{ "pdf",          "FILEATTACH",SIMPLE, LEVEL_MAIN },
	{ "sentelink",    "FILEATTACH",BT_SENTE, LEVEL_MAIN },
	{ "file",         "FILEATTACH",LINKEDFILE,   LEVEL_MAIN },
	{ "howpublished", "",         HOWPUBLISHED, LEVEL_MAIN },
	{ "refnum",       "REFNUM",      SIMPLE, LEVEL_MAIN },
	{ "language",     "LANGUAGE",    SIMPLE, LEVEL_MAIN },
	{ "note",         "NOTES",       BT_NOTE, LEVEL_MAIN },
	{ "annote",       "ANNOTE",    SIMPLE, LEVEL_MAIN },
	{ "organization", "ORGANIZER:CORP", BT_ORG, LEVEL_MAIN },
	{ "crossref",     "CROSSREF",  SIMPLE, LEVEL_MAIN },
	{ "keywords",     "KEYWORD",   KEYWORD, LEVEL_MAIN },
	{ "",            "RESOURCE|text",    ALWAYS, LEVEL_MAIN },
	{ "",            "GENRE|periodical", ALWAYS, LEVEL_MAIN }
};

/*
 * For Patent
 */
static lookups patent[] = {
	{ "author",    "AUTHOR",    PERSON, LEVEL_MAIN },
	{ "translator",   "TRANSLATOR",PERSON, LEVEL_MAIN },
	{ "assignee",  "ASSIGNEE",  PERSON, LEVEL_MAIN },
	{ "title",     "TITLE",     TITLE,  LEVEL_MAIN },
	{ "publisher", "PUBLISHER", SIMPLE, LEVEL_MAIN },
	{ "address",   "ADDRESS",   SIMPLE, LEVEL_MAIN },
	{ "editor",    "EDITOR",    PERSON, LEVEL_MAIN },
	{ "year",      "YEAR",      SIMPLE, LEVEL_MAIN }, /* date granted */
	{ "month",     "MONTH",     SIMPLE, LEVEL_MAIN },
	{ "day",       "DAY",       SIMPLE, LEVEL_MAIN },
	{ "yearfiled", "YEAR",      SIMPLE, LEVEL_MAIN }, /* date filed */
	{ "monthfiled","MONTH",     SIMPLE, LEVEL_MAIN },
	{ "dayfiled",  "DAY",       SIMPLE, LEVEL_MAIN },
	{ "abstract",  "ABSTRACT",  SIMPLE, LEVEL_MAIN },
	{ "contents",  "CONTENTS",  SIMPLE, LEVEL_MAIN },
	{ "language",  "LANGUAGE",  SIMPLE, LEVEL_MAIN },
	{ "location",  "LOCATION",  SIMPLE, LEVEL_MAIN },
	{ "nationality", "NATIONALITY", SIMPLE, LEVEL_MAIN },
	{ "note",      "NOTES",     BT_NOTE, LEVEL_MAIN },
	{ "annote",       "ANNOTE",    SIMPLE, LEVEL_MAIN },
	{ "key",       "BIBKEY",       SIMPLE, LEVEL_MAIN },
	{ "doi",       "DOI",       SIMPLE, LEVEL_MAIN },
	{ "ftp",       "",      BT_URL, LEVEL_MAIN },
	{ "url",       "",      BT_URL, LEVEL_MAIN },
	{ "pdf",          "FILEATTACH",SIMPLE, LEVEL_MAIN },
	{ "sentelink",    "FILEATTACH",BT_SENTE, LEVEL_MAIN },
	{ "file",         "FILEATTACH",LINKEDFILE,   LEVEL_MAIN },
	{ "howpublished", "",    HOWPUBLISHED, LEVEL_MAIN },
	{ "type",       "GENRE",     SIMPLE, LEVEL_MAIN },
	{ "refnum",    "REFNUM",    SIMPLE, LEVEL_MAIN },
	{ "crossref",     "CROSSREF",  SIMPLE, LEVEL_MAIN },
	{ "keywords",     "KEYWORD",   KEYWORD, LEVEL_MAIN },
	{ "",         "RESOURCE|text",        ALWAYS, LEVEL_MAIN },
	{ "",         "INTERNAL_TYPE|PATENT", ALWAYS, LEVEL_MAIN },
	{ "",         "GENRE|patent",         ALWAYS, LEVEL_MAIN },
};

/*
 * Electronic Source
 */
static lookups electronic[] = {
	{ "author",    "AUTHOR",    PERSON, LEVEL_MAIN },
	{ "translator",   "TRANSLATOR",PERSON, LEVEL_MAIN },
	{ "organization", "ORGANIZER:CORP", BT_ORG, LEVEL_MAIN },
	{ "title",     "TITLE",     TITLE,  LEVEL_MAIN },
	{ "booktitle", "TITLE",     TITLE,  LEVEL_MAIN },
	{ "publisher", "PUBLISHER", SIMPLE, LEVEL_MAIN },
	{ "address",   "ADDRESS",   SIMPLE, LEVEL_MAIN },
	{ "editor",    "EDITOR",    PERSON, LEVEL_MAIN },
	{ "year",      "YEAR",      SIMPLE, LEVEL_MAIN },
	{ "month",     "MONTH",     SIMPLE, LEVEL_MAIN },
	{ "day",       "DAY",       SIMPLE, LEVEL_MAIN },
	{ "abstract",  "ABSTRACT",  SIMPLE, LEVEL_MAIN },
	{ "volume",    "VOLUME",    SIMPLE, LEVEL_MAIN },
	{ "contents",  "CONTENTS",  SIMPLE, LEVEL_MAIN },
	{ "doi",       "DOI",       SIMPLE, LEVEL_MAIN },
	{ "ftp",       "",      BT_URL, LEVEL_MAIN },
	{ "url",       "",      BT_URL, LEVEL_MAIN },
	{ "pdf",          "FILEATTACH",SIMPLE, LEVEL_MAIN },
	{ "sentelink",    "FILEATTACH",BT_SENTE, LEVEL_MAIN },
	{ "file",         "FILEATTACH",LINKEDFILE,   LEVEL_MAIN },
	{ "howpublished", "",    HOWPUBLISHED, LEVEL_MAIN },
	{ "refnum",    "REFNUM",    SIMPLE, LEVEL_MAIN },
	{ "crossref",     "CROSSREF",  SIMPLE, LEVEL_MAIN },
	{ "location",  "LOCATION",  SIMPLE, LEVEL_MAIN },
	{ "note",      "NOTES",     BT_NOTE, LEVEL_MAIN },
	{ "annote",       "ANNOTE",    SIMPLE, LEVEL_MAIN },
	{ "key",       "BIBKEY",       SIMPLE, LEVEL_MAIN },
	{ "language",  "LANGUAGE",  SIMPLE, LEVEL_MAIN },
	{ "keywords",     "KEYWORD",   KEYWORD, LEVEL_MAIN },
        { "",         "RESOURCE|software, multimedia", ALWAYS, LEVEL_MAIN },
	{ "",         "GENRE|electronic",              ALWAYS, LEVEL_MAIN },
};

static lookups misc[] = {
	{ "author",    "AUTHOR",    PERSON, LEVEL_MAIN },
	{ "translator",   "TRANSLATOR",PERSON, LEVEL_MAIN },
	{ "title",     "TITLE",     TITLE,  LEVEL_MAIN },
	{ "booktitle", "TITLE",     TITLE,  LEVEL_MAIN },
	{ "publisher", "PUBLISHER", SIMPLE, LEVEL_MAIN },
	{ "organization", "ORGANIZER:CORP", BT_ORG, LEVEL_MAIN },
	{ "pages",     "PAGES",     PAGES,  LEVEL_MAIN },
	{ "address",   "ADDRESS",   SIMPLE, LEVEL_MAIN },
	{ "editor",    "EDITOR",    PERSON, LEVEL_MAIN },
	{ "year",      "YEAR",      SIMPLE, LEVEL_MAIN },
	{ "month",     "MONTH",     SIMPLE, LEVEL_MAIN },
	{ "day",       "DAY",       SIMPLE, LEVEL_MAIN },
	{ "abstract",  "ABSTRACT",  SIMPLE, LEVEL_MAIN },
	{ "contents",  "CONTENTS",  SIMPLE, LEVEL_MAIN },
	{ "doi",       "DOI",       SIMPLE, LEVEL_MAIN },
	{ "ftp",       "",      BT_URL, LEVEL_MAIN },
	{ "url",       "",      BT_URL, LEVEL_MAIN },
	{ "pdf",       "FILEATTACH",   SIMPLE, LEVEL_MAIN },
	{ "sentelink", "FILEATTACH",BT_SENTE, LEVEL_MAIN },
	{ "file",      "FILEATTACH",LINKEDFILE,   LEVEL_MAIN },
	{ "howpublished", "",    HOWPUBLISHED, LEVEL_MAIN },
	{ "refnum",    "REFNUM",       SIMPLE, LEVEL_MAIN },
	{ "crossref",  "CROSSREF",     SIMPLE, LEVEL_MAIN },
	{ "location",  "LOCATION",     SIMPLE, LEVEL_MAIN },
	{ "note",      "NOTES",        BT_NOTE, LEVEL_MAIN },
	{ "annote",    "ANNOTE",       SIMPLE, LEVEL_MAIN },
	{ "key",       "BIBKEY",       SIMPLE, LEVEL_MAIN },
	{ "language",  "LANGUAGE",     SIMPLE, LEVEL_MAIN },
	{ "keywords",  "KEYWORD",      KEYWORD, LEVEL_MAIN },
	{ "",          "INTERNAL_TYPE|MISC",       ALWAYS, LEVEL_MAIN },
};

#define ORIG(a) ( &(a[0]) )
#define SIZE(a) ( sizeof( a ) / sizeof( lookups ) )
#define REFTYPE(a,b) { a, ORIG(b), SIZE(b) }

variants bibtex_all[] = {
	REFTYPE( "article", article ),
	REFTYPE( "booklet", book ),
	REFTYPE( "book", book ),
	REFTYPE( "electronic", electronic ),
	REFTYPE( "inbook", inbook ),
	REFTYPE( "incollection", incollection ),
	REFTYPE( "inconference", inproceedings ),
	REFTYPE( "conference", inproceedings ),
	REFTYPE( "inproceedings", inproceedings ),
	REFTYPE( "manual", manual ),
	REFTYPE( "mastersthesis", masters ),
	REFTYPE( "misc", misc ),
	REFTYPE( "online", misc ),
	REFTYPE( "patent", patent ),
	REFTYPE( "phdthesis", phds ),
	REFTYPE( "periodical", periodical ),
	REFTYPE( "proceedings", proceedings ),
	REFTYPE( "standard", standard ),
	REFTYPE( "techreport", report ),
	REFTYPE( "unpublished", unpublished ),
};

int bibtex_nall = sizeof( bibtex_all ) / sizeof( variants );
