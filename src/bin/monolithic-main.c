#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef _MSC_VER
#include <io.h>
#else
#include <unistd.h>
#endif
#include <errno.h>

#include "monolithic_examples.h"


#if defined(BUILD_MONOLITHIC)
#define main     bibutils_monolithic_main
#endif


typedef int tool_f(int argc, const char** argv);

static int help(int argc, const char** argv);
static int quit(int argc, const char** argv);

static struct cmd_info
{
	const char* cmd;
	tool_f* f;
} commands[] = {
	{ "bib2xml", bibutils_bib2xml_main },
	{ "bibdiff", bibutils_bibdiff_main },
	{ "biblatex2xml", bibutils_biblatex2xml_main },
	{ "copac2xml", bibutils_copac2xml_main },
	{ "ebi2xml", bibutils_ebi2xml_main },
	{ "end2xml", bibutils_end2xml_main },
	{ "endx2xml", bibutils_endx2xml_main },
	{ "hash_bu", bibutils_hash_bu_main },
	{ "hash_marc", bibutils_hash_marc_main },
	{ "isi2xml", bibutils_isi2xml_main },
	{ "med2xml", bibutils_med2xml_main },
	{ "modsclean", bibutils_modsclean_main },
	{ "nbib2xml", bibutils_nbib2xml_main },
	{ "ris2xml", bibutils_ris2xml_main },
	{ "wordbib2xml", bibutils_wordbib2xml_main },
	{ "xml2ads", bibutils_xml2ads_main },
	{ "xml2bib", bibutils_xml2bib_main },
	{ "xml2biblatex", bibutils_xml2biblatex_main },
	{ "xml2end", bibutils_xml2end_main },
	{ "xml2isi", bibutils_xml2isi_main },
	{ "xml2nbib", bibutils_xml2nbib_main },
	{ "xml2ris", bibutils_xml2ris_main },
	{ "xml2wordbib", bibutils_xml2wordbib_main },

	{ "buauth_test", bibutils_buauth_test_main },
	{ "doi_test", bibutils_doi_test_main },
	{ "entities_test", bibutils_entities_test_main },
	{ "fields_test", bibutils_fields_test_main },
	{ "intlist_test", bibutils_intlist_test_main },
	{ "marcauth_test", bibutils_marcauth_test_main },
	{ "slist_test", bibutils_slist_test_main },
	{ "str_test", bibutils_str_test_main },
	{ "test", bibutils_test_main },
	{ "utf8_test", bibutils_utf8_test_main },
	{ "vplist_test", bibutils_vplist_test_main },

	{ "?", help },
	{ "h", help },
	{ "help", help },
	{ "q", quit },
	{ "quit", quit },
};

static const char* xoptarg; /* Global argument pointer. */
static int xoptind = 0; /* Global argv index. */
static int xgetopt(int argc, const char** argv, const char* optstring)
{
	static const char* scan = NULL; /* Private scan pointer. */

	char c;
	const char* place;

	xoptarg = NULL;

	if (!scan || *scan == '\0') {
		if (xoptind == 0)
			xoptind++;

		if (xoptind >= argc || argv[xoptind][0] != '-' || argv[xoptind][1] == '\0')
			return EOF;
		if (argv[xoptind][1] == '-' && argv[xoptind][2] == '\0') {
			xoptind++;
			return EOF;
		}

		scan = argv[xoptind] + 1;
		xoptind++;
	}

	c = *scan++;
	place = strchr(optstring, c);

	if (!place || c == ':') {
		fprintf(stderr, "%s: unknown option -%c\n", argv[0], c);
		return '?';
	}

	place++;
	if (*place == ':') {
		if (*scan != '\0') {
			xoptarg = scan;
			scan = NULL;
		}
		else if (xoptind < argc) {
			xoptarg = argv[xoptind];
			xoptind++;
		}
		else {
			fprintf(stderr, "%s: option requires argument -%c\n", argv[0], c);
			return ':';
		}
	}

	return c;
}

#ifdef HAVE_READLINE
#include <readline/readline.h>
#include <readline/history.h>
#else
void using_history(void) { }
void add_history(const char* string) { }
void rl_bind_key(int key, void (*fun)(void)) { }
void rl_insert(void) { }
char* readline(const char* prompt)
{
	static char line[500], * p;
	size_t n;
	fputs(prompt, stdout);
	p = fgets(line, sizeof line, stdin);
	if (p) {
		n = strlen(line);
		if (n > 0 && line[n - 1] == '\n')
			line[--n] = 0;
		p = (char*)malloc(n + 1);
		memcpy(p, line, n + 1);
		return p;
	}
	return NULL;
}
#endif

#define PS1 "> "


static int parse(const char* source)
{
	for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
	{
		struct cmd_info el = commands[i];
		size_t cmd_len = strlen(el.cmd);
		char sentinel = 0;

		if (strlen(source) >= cmd_len)
			sentinel = source[cmd_len];

		if (strncmp(source, el.cmd, cmd_len) == 0 && (sentinel == 0 || isspace(sentinel)))
		{
			int argc_count;
			const char** argv_list = (const char**)calloc(strlen(source) / 2 + 2, sizeof(char*)); // worst-case heuristic for the argv[] array size itself
			char* argv_strbuf = (char*)malloc(strlen(source) + 2);
			const char* p = source + cmd_len;
			while (isspace(*p))
				p++;
			strcpy(argv_strbuf, p);

			argc_count = 0;
			argv_list[argc_count++] = el.cmd;  // argv[0] == command

			p = strtok(argv_strbuf, " \t\r\n");
			while (p != NULL)
			{
				argv_list[argc_count++] = p;
				p = strtok(NULL, " \t\r\n");
			}
			argv_list[argc_count] = NULL;

			int rv = el.f(argc_count, argv_list);
			free((void *)argv_list);
			free(argv_strbuf);
			fprintf(stderr, "--> exit code: %d\n", rv);
			return rv;
		}
	}
	return 0;
}

static char* read_stdin(void)
{
	size_t n = 0;
	size_t t = 512;
	char* s = NULL;

	for (;;) {
		char* ss = (char*)realloc(s, t);
		if (!ss) {
			free(s);
			fprintf(stderr, "cannot allocate storage for stdin contents\n");
			return NULL;
		}
		s = ss;
		n += fread(s + n, 1, t - n - 1, stdin);
		if (n < t - 1)
			break;
		t *= 2;
	}

	if (ferror(stdin)) {
		free(s);
		fprintf(stderr, "error reading stdin\n");
		return NULL;
	}

	s[n] = 0;
	return s;
}

static void trim(char* s)
{
	if (!s)
		return;

	char* d = s;
	while (*s && isspace(*s))
	{
		s++;
	}
	char* e = s + strlen(s) - 1;
	while (e >= s && isspace(*e))
	{
		e--;
	}
	if (e >= s)
	{
		size_t l = e - s + 1;
		if (s > d)
			memmove(s, d, l);
		s[l] = 0;
	}
	else
	{
		*d = 0;
	}
}

static int help(int argc, const char** argv)
{
	fprintf(stderr, "Commands:\n");
	for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
	{
		struct cmd_info el = commands[i];
		fprintf(stderr, "  %s\n", el.cmd);
	}
	fprintf(stderr, "\n\nOr type Ctrl-C to quit.\n");

	return 0;
}


static int quit(int argc, const char** argv)
{
	fprintf(stderr, "Exiting by user demand...\n");

	return 999;
}


static void usage(void)
{
	fprintf(stderr, "Usage: bibutils [options] [command]\n");
	fprintf(stderr, "\t-i: Enter interactive prompt after running code.\n");
	exit(1);
}

int main(int argc, const char** argv)
{
	char* input;
	int status = 0;
	int interactive = 0;
	int c;

	while ((c = xgetopt(argc, argv, "i")) != -1) {
		switch (c) {
		default: usage(); break;
		case 'i': interactive = 1; break;
		}
	}

	if (xoptind == argc) {
		interactive = 1;
	}
	else {
		int si = xoptind;
		size_t l = 0;

		for (int i = si; i < argc; i++)
			l += strlen(argv[i]) + 1;
		l += 2;
		input = (char*)malloc(l);
		*input = 0;

		for (int i = si; i < argc; i++)
		{
			snprintf(input + strlen(input), l - strlen(input), "%s ", argv[i]);
		}
		trim(input);
		if (!input || !*input)
			status = 1;
		else
			status = parse(input);
	}

	if (interactive) {
		if (_isatty(0)) {
			using_history();
			rl_bind_key('\t', rl_insert);
			input = readline(PS1);
			while (input) {
				trim(input);
				status = parse(input);
				if (status == 999)
					break;
				if (*input)
					add_history(input);
				free(input);
				input = readline(PS1);
			}
			putchar('\n');
		}
		else {
			input = read_stdin();
			trim(input);
			if (!input || !*input)
				status = 1;
			else
				status = parse(input);
			free(input);
		}
	}

	return status;
}

