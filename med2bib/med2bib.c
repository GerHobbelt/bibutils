/*
 * medline to bibtex
 *
 */

#include <stdio.h>
#include <string.h>
#include "newstr.h"
#include "findrepl.h"

#define TRUE  1
#define FALSE 0
#define FIELD_OTHER    0
#define FIELD_AUTHORS  1
#define FIELD_TITLE    2
#define FIELD_SOURCE   3
#define FIELD_ABSTRACT 4

int abstractout = FALSE;

int whitespace (char ch)
{
  if (ch==' ' || ch=='\t' || ch=='\n' || ch=='\r') return TRUE;
  else return FALSE;
}

int endofline (char ch)
{
  if (ch=='\n' || ch=='\r') return TRUE;
  else return FALSE;
}

void output_abbrev (newstring *lastnamesptr, int numauthors, newstring *sourceptr)
{
  char *p;
  int pos;
  newstring abbrev;

  newstr_init(&abbrev);

  /** Get the first author's last name w/o spaces **/
    p = lastnamesptr[0].data;
    while (*p) {
       if (!whitespace(*p) && *p!='{' && *p!='}' ) newstr_addchar(&abbrev,*p);
       p++;
    }
    if (abbrev.data!=NULL) printf("%s",abbrev.data);
    else printf("REF");

  /** Output the last two digits of the year **/
    if (sourceptr!=NULL && sourceptr->data!=NULL) {
      p=strchr(sourceptr->data,'.');
      if (p!=NULL) { 
        p++;
        while (*p && whitespace(*p)) p++;
        pos=1;
        while (*p && !whitespace(*p) && pos<5) {
           if (pos>2) printf("%c",*p);
           p++;
           pos++;
        }
     }
  }
  newstr_clear(&abbrev);
}

void output_authors (newstring* lastnames, newstring* initials, int numauthors)
{
   int i;
   unsigned long pos;
   printf("AUTHOR=\"");
   for (i=0; i<numauthors; ++i) {
      if (i>0) printf("and ");
      if (initials[i].data!=NULL && initials[i].dim!=0) {
         for (pos=0; pos < strlen(initials[i].data); pos++)
            printf("%c. ",initials[i].data[pos]);
      }
      if (lastnames[i].data!=NULL && lastnames[i].dim!=0) {
         printf("%s",lastnames[i].data);
      }
      if (i!=numauthors-1) printf("\n");
   }
   printf("\"");
}


int generate_authors (newstring *authorsptr, newstring** lastnamesptr, newstring** firstnamesptr)
{
  char *p,*q;
  int est,i,nauthor;
  int nblocks, dimblocks=0;
  newstring wholename;
  newstring *blocks     = NULL;
  newstring *firstnames = NULL;
  newstring *lastnames  = NULL;

  if (authorsptr==NULL || authorsptr->data==NULL) return 0;

  /* Estimate the initial number of authors */
    est=1;
    p=authorsptr->data;
    while (*p) if (*p++==',') est++;

  /* Allocate arrays */
    lastnames  = (newstring*) malloc (sizeof(newstring)*est);
    firstnames = (newstring*) malloc (sizeof(newstring)*est);
    if (lastnames==NULL || firstnames==NULL) {
        if (lastnames!=NULL) free(lastnames);
        if (firstnames!=NULL) free(firstnames);
        lastnames = firstnames = NULL;
        return 0;
    }
    for (i=0; i<est; ++i) {
        newstr_init(&(lastnames[i]));
        newstr_init(&(firstnames[i]));
    }
    newstr_init(&wholename);

  /* For the entire list do... */
    p=authorsptr->data;
    nauthor=0;
    while (*p) {
       
       while (*p && *p!=',') newstr_addchar(&wholename,*p++);
       nblocks=0;
       q = wholename.data;
       while (*q) {
           while (*q && whitespace(*q)) q++;
           if (*q && !whitespace(*q)) nblocks ++;
           while (*q && !whitespace(*q)) q++;
       }
       if ( nblocks > dimblocks ) {
            newstring *newblocks;
            newblocks = (newstring*) realloc(blocks,sizeof(newstring)*nblocks);
            if (newblocks==NULL) {
               fprintf(stderr,"med2bib: cannot allocate memory in generate_authors().\n");
               exit(EXIT_FAILURE);
            }
            else {
               blocks = newblocks;
               for (i=dimblocks; i<nblocks; ++i) {
                   newstr_init(&(blocks[i]));
               }
               dimblocks = nblocks;
            }
       }

       for (i=0; i<nblocks; ++i) newstr_clear(&(blocks[i]));
       nblocks=0;
       q = wholename.data;
       while (*q) {
           while (*q && whitespace(*q)) q++;
           while (*q && !whitespace(*q)) {
              newstr_addchar(&(blocks[nblocks]),*q);
              q++;
           }
           while (*q && whitespace(*q)) q++;
           nblocks++;
       }

       /* Handle suffixes */
       if (strcmp(blocks[nblocks-1].data,"3rd")==0 ||
           strcmp(blocks[nblocks-1].data,"3d")==0  ||
           strcmp(blocks[nblocks-1].data,"Jr")==0  ||
           strcmp(blocks[nblocks-1].data,"Sr")==0  ||
           strcmp(blocks[nblocks-1].data,"III")==0 ||
           strcmp(blocks[nblocks-1].data,"II")==0 ) {
           newstring tmp;
           if ( nblocks-2 >= 0 ) {
              tmp=blocks[nblocks-1];
              blocks[nblocks-1]=blocks[nblocks-2];
              blocks[nblocks-2]=tmp;
           }
       }
       if (nblocks>2) newstr_addchar(&(lastnames[nauthor]),'{');
       for (i=0; i<nblocks-1; ++i) {
            newstr_strcat(&(lastnames[nauthor]),blocks[i].data);
            if (nblocks>2 && i<nblocks-2) newstr_addchar(&(lastnames[nauthor]),' ');
       }
       if (nblocks>2) newstr_addchar(&(lastnames[nauthor]),'}');
       if (nblocks>1) {
          newstr_strcat(&(firstnames[nauthor]),blocks[nblocks-1].data);
       }
      newstr_clear(&wholename);
      nauthor++;
      if (*p) p++;
  }

  for ( i=0; i<dimblocks; ++i ) newstr_clear(&(blocks[i]));
  free(blocks);

  *lastnamesptr = lastnames;
  *firstnamesptr = firstnames;
  return est;

}

void free_authors( newstring **lastnamesptr, newstring **firstnamesptr, int numauthors)
{
   int i;
   newstring *firstnames, *lastnames;

   firstnames = *firstnamesptr;
   lastnames  = *lastnamesptr;

   for ( i=0; i<numauthors; ++i ) {
      newstr_clear(&(lastnames[i]));
      newstr_clear(&(firstnames[i]));
   }
   free(*lastnamesptr);
   free(*firstnamesptr);
   *lastnamesptr = *firstnamesptr = NULL;
}

void output_title (newstring *titleptr)
{
  process_title(titleptr);
  printf("TITLE=\"%s\"",titleptr->data);
}

void output_source (newstring *sourceptr)
{
  char *p,*savep;
  int pos;
  newstring journal;
  newstring pgbegin,pgend;

  if ( sourceptr!=NULL && sourceptr->data!=NULL) {

    /** Output Journal **/
     printf("JOURNAL=\"");
     newstr_init(&journal);
     p = sourceptr->data;
     while (*p && whitespace(*p)) p++;
     while (*p && *p!='.') {
         if (!whitespace(*p)) {
           newstr_addchar(&journal,*p);
           p++;
         }
         else {
           newstr_addchar(&journal,' ');
           while (whitespace(*p)) p++;
         }
     }
     process_journal(&journal);
     if (journal.data!=NULL) printf("%s",journal.data);
     printf("\",\n");
     newstr_clear(&journal);
     savep=p;

    /** Output Year **/
     if (savep!=NULL) {
       printf("YEAR=\"");
       p = strchr(savep,'.');
       if (p!=NULL) {
         p++;
         while (*p && whitespace(*p)) p++;
         while (*p && !whitespace(*p) && *p!='(' && *p!=':' && *p!='.' && *p!=',' && *p!=';') {
           printf("%c",*p);
           p++;
         } 
       }
      printf("\",\n");
      savep=p;
     }

    /** Output Volume **/
    if (savep!=NULL) {
     printf("VOLUME=");
     p = strchr(savep,';');
     if (p!=NULL) {
       p++;
       while (*p && whitespace(*p)) p++;
       while (*p && !whitespace(*p) && *p!='(' && *p!=',' && *p!='.' && *p!=':') {
         printf("%c",*p);
         p++;
       }
     }
     printf(",\n");
   }

    /** Output Pages **/
if (savep!=NULL) {
     printf("PAGES=\"");
     newstr_init(&pgbegin);
     newstr_init(&pgend);
     p = strchr(savep,':');
     if (p!=NULL) {
       while (*p && (whitespace(*p) || *p==':')) p++;
       while (*p && !whitespace(*p) && *p!=',' && *p!='-' && *p!='.') { 
         newstr_addchar(&pgbegin,*p);
         p++;
       }
       if (pgbegin.data!=NULL && pgbegin.dim!=0) printf("%s",pgbegin.data);
       while (*p=='-' || whitespace(*p)) p++;
       while (*p && !whitespace(*p) && *p!=',' && *p!='.' && *p!=':') {
         newstr_addchar(&pgend,*p);
         p++;
       }
       if (pgend.data!=NULL && pgend.dim!=0) {
          printf("--");
          if (strlen(pgend.data)>=strlen(pgbegin.data)) printf("%s",pgend.data);
          else {
          for (pos=0; pos<(long)strlen(pgbegin.data)-(long)strlen(pgend.data); pos++)
             printf("%c",pgbegin.data[pos]);
            printf("%s",pgend.data);
          }
       }
     }
     printf("\"");
     newstr_clear (&pgbegin);
     newstr_clear (&pgend);
}
}
}

void output_abstract(newstring *abstractptr)
{
  char *p;
  printf(",\nABSTRACT=\"\n");
  p=abstractptr->data;
  while (*p) {
    if (*p!='\"') printf("%c",*p);
    p++;
  }
  printf("\"");
}

void output_fields (newstring *authorsptr, newstring *titleptr, 
                    newstring *sourceptr, newstring *abstractptr)
{
  newstring *lastnames, *initials;
  int numauthors;
  numauthors = generate_authors(authorsptr,&lastnames,&initials);
  printf("@ARTICLE(");
  output_abbrev(lastnames,numauthors,sourceptr);
  printf(",\n");
  output_authors(lastnames,initials,numauthors);
  printf(",\n");
  output_title(titleptr); 
  printf(",\n");
  output_source(sourceptr); 
  printf(")\n\n");
  free_authors(&lastnames,&initials,numauthors); 
}

void get_fields (FILE *fp)
{
  int field_id;
  int i, startfield;
  newstring authors,title,source,abstract;
  char buf[512];

  field_id = FIELD_OTHER;
  newstr_init(&authors);
  newstr_init(&title);
  newstr_init(&source);
  newstr_init(&abstract);
  while (!feof(fp)) {
    if (fgets(buf,sizeof(buf),fp)) {
      i = 0;
	while (i<sizeof(buf) && buf[i]!='\0') {

/*
printf("field_id= %d i=%d\n",field_id,i);
printf("BUF: '%s'\n",buf);
*/

	/* Keep parsing until we reach a number starting a line and then a ':' */
	if (field_id == FIELD_OTHER && buf[i]!='\0') {
		while (buf[i] && ( buf[i]>='0' && buf[i]<='9')) ++i;
		while (buf[i]!=':' && buf[i]!='\0') ++i;
/*printf("BUF: '%s'\n",&(buf[i]));*/
		if (buf[i]==':' && 
		   ((i>0) && (buf[i-1]>='0' && buf[i-1]<='9')) ) {
			i++;
			while (whitespace(buf[i])) ++i;
			field_id = FIELD_AUTHORS;
		}
		else i++;
	}

	if (field_id == FIELD_AUTHORS && buf[i]!='\0') {
		/* while (whitespace(buf[i])) ++i; */
		startfield = i;
		while (buf[i]!='\r' && buf[i]!='\n' && buf[i]!='\0') ++i;
		if (buf[i]=='\0') newstr_strcat(&authors,&(buf[startfield]));
		else {
			/* remove the newline and paste */
			buf[i] = '\0';
			if (buf[i+1]=='\r' || buf[i+1]=='\n') buf[i+1]=' ';
			/* if we've reached ".\n", we need to go on to next field */
			if (i>0 && buf[i-1]=='.') {
				buf[i-1]='\0';
				field_id=FIELD_TITLE;
		} 
			newstr_strcat(&authors,&(buf[startfield]));
/*
printf("buf: '%s'\n",&(buf[startfield]));
printf("Authors: '%s'\n",authors.data);
*/
			i++;
			if (field_id==FIELD_AUTHORS) newstr_addchar(&authors,' ');
			else while (whitespace(buf[i])) i++;
		}
	}

	if (field_id == FIELD_TITLE && buf[i]!='\0') {
		/* while (whitespace(buf[i])) ++i; */
		startfield = i;
		while ((buf[i]!='\r' && buf[i]!='\n') && buf[i]!='\0') ++i;
		if (buf[i]=='\0')  newstr_strcat(&title,&(buf[startfield]));
		else {
			/* remove the newline and paste */
			buf[i] = '\0'; 
			if (buf[i+1]=='\r' || buf[i+1]=='\n') buf[i+1]=' ';
			/* if we've reached ".\n", we need to go to the next field */
			if (i>0 && buf[i-1]=='.') {
				buf[i-1]='\0';
				field_id=FIELD_SOURCE;
			}
			newstr_strcat(&title,&(buf[startfield]));
/*
printf("buf: '%s'\n",&(buf[startfield]));
printf("Title: '%s'\n",title.data);
*/
			i++;
			if (field_id==FIELD_TITLE) newstr_addchar(&title,' ');
			else while (whitespace(buf[i])) ++i;
		}
	}


	if (field_id == FIELD_SOURCE && buf[i]!='\0') {
		/* while (whitespace(buf[i])) ++i; */
		startfield = i;
		while (buf[i]!='\r' && buf[i]!='\n' && buf[i]!='\0') ++i;
		if (buf[i]=='\0') newstr_strcat(&source,&(buf[startfield]));
		else {
			/* remove the newline and paste */
			buf[i] = '\0';
			if (buf[i+1]=='\r' || buf[i+1]=='\n') buf[i+1]=' ';
			/* if we've reached ".\n", we need to go to the next field */
			if (i>0 && buf[i-1]=='.') {
				buf[i-1]='\0';
				field_id=FIELD_OTHER;
			}
			newstr_strcat(&source,&(buf[startfield]));
			i++;
			if (field_id==FIELD_SOURCE) newstr_addchar(&title,' ');
			else while (whitespace(buf[i])) ++i;
			/* Now process this reference and reset all */
			if (field_id==FIELD_OTHER){
				output_fields(&authors,&title,&source,&abstract);
				fflush(stdout);
				newstr_clear(&authors);
				newstr_clear(&title);
				newstr_clear(&source);
				newstr_clear(&abstract);
			}
		}
	}
	}
    }
  }
}

int main(int argc, char *argv[])
{
  FILE *fp;
  int arg,argtemp,found;
  initialize_subs();

  /* Check to see if abstract should be displayed */
  arg=1;
  found=FALSE;
  while (arg<argc && !found) {
    if (strcmp(argv[arg],"-a")==0) {
     found=TRUE;
     abstractout=TRUE;
     for (argtemp=arg+1; argtemp<argc; argtemp++) argv[argtemp-1]=argv[argtemp];
     argc--;
    }
    arg++;
  } 

  if (argc==1) {
    get_fields(stdin);
  }
  else {
    for (arg=1; arg<argc; arg++) {
      fp=fopen(argv[arg],"r");
      if (fp==NULL) {
        fprintf(stderr,"Error.  Cannot open %s for reading.\n",argv[arg]);
      }
      else {
        get_fields(fp);
        fclose(fp);
      }
    }
  }
  return 0;
}
 
