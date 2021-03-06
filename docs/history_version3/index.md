## 3.43

11/24/2008

BIB2XML

*   Fix recognition of em-dash by placing it before en-dash in conversion  
    list.
*   Add -nl or --no-latex to prevent conversion of latex character  
    combinations

MODSOUT

*   Ensure that bibutils handles records with empty MODS attributes

## 3.42

10/31/2008

MODSOUT

*   Change default to UTF8 unicode characters written directly (not  
    via XML entities) and writing BOM. Add command-line switch  
    \-x or --xml-entities to write XML entities instead to BIB2XML  
    END2XML ENDX2XML MED2XML RIS2XML, etc.

XML2ADS

*   Fix unicode output to add Byte Order Mark by default
*   Add -nb or --no-bom switch to turn off Byte Order Mark for unicode if  
    the user doesn't want it

XML2BIB

*   For users who want the bibtex file format, but not the latex encryption  
    of characters, add -nl or --no-latex to command-line switches
*   Fix unicode output to add Byte Order Mark by default
*   Add -nb or --no-bom switch to turn off Byte Order Mark for unicode if  
    the user doesn't want it

XML2END

*   Fix unicode output to add Byte Order Mark by default
*   Add -nb or --no-bom switch to turn off Byte Order Mark for unicode if  
    the user doesn't want it

XML2ISI

*   Fix unicode output to add Byte Order Mark by default
*   Add -nb or --no-bom switch to turn off Byte Order Mark for unicode if  
    the user doesn't want it

XML2RIS

*   Fix unicode output to add Byte Order Mark by default
*   Add -nb or --no-bom switch to turn off Byte Order Mark for unicode if  
    the user doesn't want it

XML2WORD2007

*   Add -nb or --no-bom switch to turn off Byte Order Mark for unicode if  
    the user doesn't want it
*   Fix the recognition of incollection items as book sections.

## 3.41

6/16/2008

BUILD

*   Fix bug in makedeb.csh
*   Fix site-specific compiler definition for SunOS5 target.
*   Add Linux x86\_64 target for configuration.

MODSIN

*   Fix NULL pointer dereference for "detail" elements lacking a type  
    attribute. (Noticed and hunted down by Thomas Fischer.)

RIS2XML

*   Fix bug where "AB - " with a newline before the abstract was  
    not recognized as an abstracted. (Reported by Thomas Braun  
    and Richard Mathar.)

XML2ADS

*   Updates from Richard Mathar fixing R-tag output, merging keywords,  
    fixing date, adding title, and replacing double dash.
*   Update journals to current list from:  
    [http://adsabs.harvard.edu/abs\_doc/journals1.html](http://adsabs.harvard.edu/abs_doc/journals1.html)

XML2BIB

*   Fix character priority so unicode/utf8 takes precedence over latex  
    (Patch from Luc Pardon)

## 3.40

2/10/2008

MODSIN

*   Fix crash where placeTerm tag doesn't have attribute (Thanks to  
    Martin-Michael Schoenbeck for identifying the problem and submitting  
    an initial patch).
*   Properly handle the 'mods:' namespace (Thanks to Martin-Michael  
    Schoenbeck for identifying the problem and submitting an  
    initial patch).
*   Fix bug where multiple roleTerms confused role assignment.

RIS2XML

*   Oxford journal RIS output is now putting DOI information in the N1  
    field; recognize this (Thanks to Richard Mathar for letting me know).

XML2ADS

*   New converter for the ADS format submitted by Richard Mathar.

XML2BIB

*   Bias the program to output issue/number tags as 'number' first  
    and use 'issue' only in cases where both issue and number have  
    been defined.
*   Add '-sk' '--strictkey' option that only outputs alphanumeric  
    characters in the bibtex reference names (this is overly strict,  
    but may be useful in some cases to automatically avoid problems  
    with other bibtex parsers)

XML2END

*   Fix missing return for articles with article numbers rather than  
    page numbers

XML2WORDBIB

*   Rename "xml2word" to avoid confusion with other programs that work  
    on Word documents, not Word bibliographies

## 3.39

10/24/2007

NAME MANGLING

*   Fix crash caused by specifically malformed name field

## 3.38

10/10/2007

BIB2XML

*   Fix crash when bibtex citation key is blank (introduced in 3.37)

END2XML

*   Fix handling of total pages
*   Fix handling of conference name

ENDX2XML

*   Fix handling of total pages
*   Fix handling of conference name
*   Fix bug where reference would skip if the starting record tag was  
    split by the input buffer

## 3.37

8/20/2007

MODSOUT

*   fix bug where terminating > symbol is missing in <identifier type="serialnumber"> output</identifier>

## 3.36

8/19/2007

CHARSET CONVERSION

*   add recognition of apostrophe HTML entity

LIBRARY HANDLING

*   resolve duplicates of citation keys by adding a-z

BIB2XML

*   properly handle bibtex files output by endnote that don't have field keys
*   add support for Diploma, Doctoral, and Habilitation theses (German)

ENDX2XML

*   properly handle whitespace in style tags
*   add support for Diploma, Doctoral, and Habilitation theses (German)

RIS2XML

*   support computer program "COMP" type
*   support patent "PAT" type
*   support unpublished "UNPB" type
*   add support for Diploma, Doctoral, and Habilitation theses (German)

XML2BIB

*   output newspaper articles as @ARTICLE as well
*   output series titles as "series" for book chapter, inproceedings, theses  
    types
*   add support for Diploma, Doctoral, and Habilitation theses (German)

XML2END

*   support magazine article type
*   support patent type
*   support computer program type
*   add support for Diploma, Doctoral, and Habilitation theses (German)

XML2ISI

*   be more aggressive about outputting the date

XML2RIS

*   support magazine article type
*   support abstract/summary type
*   support patent type
*   support computer program type
*   support unpublished "UNPB" type
*   add support for Diploma, Doctoral, and Habilitation theses (German)

## 3.35

7/30/2007

BIB2XML

*   support translator field

COPAC2XML

*   fix bug where garbage input can lead to infinite loop

ENDX2XML

*   fix bug where multiple style tags caused data to be lost

ISI2XML

*   use authors listed with "AF" instead of "AU" when present as they  
    are a "better" annotated list
*   fix bug where garbage input can lead to infinite loop (patch thanks  
    to Fred Howell)
*   add type S for book in series
*   fix bug where NR number of references was being recognized as  
    journal number

RIS2XML

*   add support for RIS magazine article "MGZN"
*   add support for RIS abstract "ABST"
*   add support for reading thesis hint in "user 1" tag "U1"

XML2BIB

*   output article number as page number if page numbers aren't found
*   support translator field
*   make preferred form of \\text markups have curly brackets

XML2END

*   output article number as page number if page numbers aren't found

XML2RIS

*   output article number as page number if page numbers aren't found
*   fix recognition of thesis type
*   output "U1 - Masters thesis" or "U1 - Ph.D. thesis" as a hint  
    for Refbase of the thesis type

XML2WORD

*   output article number as page number if page numbers aren't found

## 3.34

6/7/2007

ENDX2XML

*   fix bug that prevent dates from being read in

## 3.33

5/23/2007

MED2XML

*   fix stupid change that caused core dumps

## 3.32

5/21/2007

CHARSET CONVERSION

*   fix bug where UTF-8/Unicode input is ignored for BibTeX files

MODSIN

*   Recognize both <extent unit="page"> and <extent unit="pages"></extent></extent>

NEWSTR

*   Fix compilation on 64 bit processors

BIB2XML

*   Strip latex \\url{} tags from input data

XML2BIB

*   Add recognition of --verbose and --debug

XML2END

*   Add recognition of --verbose and --debug

XML2ISI

*   Add recognition of --verbose and --debug

XML2RIS

*   Add recognition of --verbose and --debug

XML2WORD

*   Add recognition of command line switches

## 3.31

4/1/2007

BIBTEXIN

*   Fix typo in genre for "incollection" to "monographic"
*   Remove text markups like \\textit{} and \\textbf{}
*   Replace text markups like "\\textonesuperior" with appropriate Unicode  
    characters
*   Have electronic types set MODS resource "software, multimedia"

BIBTEXOUT

*   Modify warning message for "xml2bib: cannot identify type" to  
    tell user that it's defaulting to @Misc so people stop reporting  
    this information to me
*   Add electronic type recognition and output

ENDIN

*   Have electronic types set MODS genre "electronic"
*   Add '%S' Series title to Book type
*   Add recognition of Unicode UTF8 byte order information

ENDXMLIN

*   Ensure that the "label" field ends up in the MODS output as  
    reference ID
*   Pass through "short-title" information

MODSOUT

*   Fix typo so MARC-authority genre types are "marcgt", not "marc"
*   Output ACCESSNUM to MODS

RISIN

*   Add thesis type
*   Add report type

RISOUT

*   Map "collection" and "incollection" from bibtex to "book" and "inbook"
*   Add thesis type
*   Add report type

ENDOUT

*   Map "collection" and "incollection" from bibtex to "book" and "inbook"

## 3.30

3/17/2007

XML2WORD

*   Write first version of the program

## 3.29

3/12/2007

ENDIN

*   Fix addition of extraneous tag for electronic types; add  
    proper MODS resource tag

ENDX2XML

*   Fix problems parsing in XML files without newlines

## 3.28

3/10/2007

BIBTEXIN

*   Fix problems parsing files that have non-bibtex lines in them
*   Add c with a hacek support to latex characters (thanks to  
    George Smith for the information)
*   Add enspace, emspace, and thinspace support to latex  
    characters (patch from John Spray; thanks!)

ENDX2XML

*   Write first version of the program

ISIIN

*   Add support for DOI tag "DI"

NAME MANGLING

*   Fix bug in handling multibyte Unicode characters

XMLIN

*   Fix bug where single quoted XML attributes were not recognized  
    (Patch due to Jason Lerch)

XML2ISI

*   Write first version of the program

## 3.27

06/22/2006

BIBTEXIN

*   Fix scrambling of title/booktitle for bibtex cross-references  
    involving "incollection" and "inproceeding" types

## 3.26

06/21/2006

MODSIN

*   Add reading in pubmed/medline/pii identifiers

RISOUT

*   Output pubmed identifiers as UR - PM:###### (Thanks to Mark Runyan)

## 3.25

06/14/06

BUILD PROCESS

*   Add NetBSD, FreeBSD, and Cygwin to recognized architectures

MODSOUT

*   Convert patent assignee to the MARC term "patent holder" (modified from  
    patch by Ralf Ahlbrink)
*   Add role types "organizer of meeting", "inventor", "degree grantor"  
    (modified from patch by Ralf Ahlbrink)

NAME MANGLING

*   Fix possible interactions between pre-defined corporate types  
    and user-defined as-is and corporate types

ISI2XML

*   Add support for "article number" (AR) field that some journals are  
    now using instead of page numbers

MED2XML

*   Fix date parsing for entries that have a "medline format date" rather  
    than a date broken down into XML fields
*   Fix bug that doesn't output proper end pages if first and last pages  
    are the same length (thanks to Andreas Hartmetz for finding and patching  
    the bug)

## 3.24

02/21/2006

CHARSET CONVERSION

*   fix bug where requests for UTF-8 encoded output were ignored

MED2XML

*   default input to UTF-8 encoded unicode, as it ought to be
*   extract a few more items (like pubmed/medline/pii ID's, MeSH  
    headings)...most currently only make it into MODS output

XML

*   fix potential core dump from empty xml attributes values

XML2BIB

*   for better compatibility with Emacs, default the bibtex tags to  
    lower case (based on patch from Stefan Schmitt)
*   new switch -U, --uppercase to switch to old all uppercase tag behavior

## 3.23

1/02/2006

Changes in this release are thanks to patch and bug report by Jeremy Malcolm.

BIB2XML

*   Add support for volume in [@electronic](https://sourceforge.net/u/electronic/) reference type

END2XML

*   Add support for volume in electronic reference type

RIS2XML

*   Add support for TY - ELEC reference type

XML2RIS

*   Add support for TY - ELEC reference type
*   Fix bug where GENRE, but not NGENRE data was being parsed for reference  
    type

## 3.22

12/09/2005

MODSIN

*   fix off-by one bug that can cause references to be skipped

XML

*   fix potential coredump on error path in xml\_findend()

## 3.21

11/02/2005

CHARSET CONVERSION

*   add latex version of degree sign, micro sign
*   numerous fixes to charset handling
*   add -i,--input-encoding and -o, --output-encoding parameters for the  
    programs xml2bib, xml2end, xml2ris
*   allow modsin and medin modules to read the character set specified by  
    the xml descriptors
*   set priority so that the character set has the priority:  
    program defaults < xml file specified < user specified

LIBRARY

*   fix bug where static prototype appears to be illegal and prevents  
    compilation on MacOSX "Tiger"
*   finally add error reporting messages for library errors

BIB2XML

*   add support for cross referencing

## 3.20

10/06/2005

END2XML

*   fix type of court reporter

NAME PROCESSING

*   recognize names in the form Author, HQ or HQ Author and split up  
    the initials

BUILD PROCESS

*   switch build to a ./configure; make; make install commands (but do  
    it without autoconf)
*   add debian package options to Linux and MacOSX as a trial

MODSOUT

*   start fixing position of items like volume, issue, pages for entries  
    now that MODS v3.1 allows part tags at the main level

## 3.19

09/14/2005

BIB2XML

*   add issuance of monographic to book types: book, inbook, incollection
*   fix bug where fields protected by braces or quotations would still  
    be subjected to string substitutions
*   fix bug where string substitutions could be applied multiple times;  
    bibtex has special concatenation with string substitution rules
*   add latin capital/lowercase c with acute to latex conversion
*   add some letters with caron (hacek) specifications

END2XML

*   add issuance of monographic to book types: book, edited book, chapter
*   move publisher to host level in journal article and add to magazine  
    article

ISI2XML

*   add issuance of monographic to book types: book, chapter

RIS2XML

*   add issuance of monographic to book types: book, inbook

XML2BIB

*   The protected latex forms of characters, e.g. {\\'A}, are preferred  
    to non-protected, e.g. \\'A or \\'{A}. So fixup lookup table  
    so the preferred forms are output.

XML2RIS

*   better detection of book types via issuance of monographic

SERIALNUMBER

*   split out common serial number processing code

MODSIN

*   fix bug where unicode character set in was not the default

MODSOUT

*   ensure that ambiguous serial numbers are output
*   fix bug where -un/-u flags weren't being respected

## 3.18

07/11/2005

BIB2XML

*   accommodate all entries from the IEEEtrans bibtex style and other requests  
    for missing common fields
*   to article reference type add key, location, language, note, keywords
*   to book reference type add key, location, language, note, series,  
    volume, number, lccn, keywords
*   to techreport reference type add key, location, language, note, institution,  
    number, type, lccn, keywords
*   to inbook reference type add key, location, language, note, lccn, keywords
*   to incollection reference type add key, location, language, note, number,  
    chapter, type, lccn
*   to booklet reference type add key, location, note, series, volume, number  
    organization, language, lccn
*   to manual reference type add key, location, note, language, organization,  
    lccn, keywords
*   to inproceedings/incollection type add key, location, note, language,  
    series, number, organization, paper, type, lccn, keywords
*   to proceedings type add key, location, note, language, series, number,  
    organization, lccn, keywords
*   to mastersthesis type add key, location, note, language, type, keywords
*   to phdthesis type add key, location, note, languate, type, keywords
*   to misc type add key, location, note, language, organization, keywords
*   add unpublished type
*   add electronic type
*   add patent type
*   add periodical type
*   add standard type

XML2BIB

*   fix recognition of collection/incollection types
*   add handling of location information

XML2END

*   output all note fields

MODSIN

*   add physical location to tags read in
*   fix memory leak in modsin\_location()
*   fix bug in modsin\_descriptionr()
*   keep type="school" information in place entries

MODSOUT

*   handle key field from bibtex

## 3.17

BIB2XML

*   add series information to incollection type
*   add edition input to types
*   protect URL, DOI, REFNUM fields from being detexified
*   support URLs in "howpublished" tags
*   support \\url{} in addition to \\urllink{}
*   inbook reference types should use chapter+title, not title+booktitle
*   incollection reference types should use booktitle+title
*   fix bug where spaces in string replacements cause the replacements to  
    be misunderstood

COPAC2XML

*   fix but in name mangling and insertion of editors in author fields

ISI2XML

*   fix bug in outputing times cited to note field

RIS2XML

*   add reading user U1-U5 and miscellaneous M1-M3 fields; convert to "notes"  
    so they'll be output at least

MODSIN

*   put in the core of handling physicalDescription tags
*   fix bug where files with mods ending and starting on the same line were  
    mangled

MODSOUT

*   fix place term output and edition output
*   output all URL information

XML2BIB

*   add edition output
*   protect REFNUM fields from being texified
*   better error messages for misidentified TYPE
*   recognize Masters and Ph.D. thesis types
*   inbook reference types should use chapter+title, not title+booktitle
*   incollection reference types should use booktitle+title
*   fix recognition of genre magazine as ARTICLE

XML2END

*   fix bug in recognizing the thesis type

## 3.16

4/10/2005

GLOBAL CHANGES

*   rename progs directory to bin
*   fix warnings from SunOS compile

BIB2XML

*   add masters thesis type
*   change Ph.D. thesis and Masters thesis to add non-MARC genres  
    "Ph.D. thesis" and "Masters thesis" to distinguish

END2XML

*   fix bug where endin\_readf() can return 0 even if reference is obtained

XML2BIB

*   don't texify special characters in URLs and DOIs

## 3.15

3/17/2005

GLOBAL CHANGES

*   Convert all programs to use the bibutils library with bibl\_read() and  
    bibl\_write() with appropriate modes. Massive conversion to a bibutils  
    library.
*   Add -o or --output-encoding to xml2bib, xml2end, xml2ris
*   Add -s or --single-refperfile to xml2bib, xml2end, xml2ris
*   Handle all character conversion issues nicely in the library. Set default  
    to Latin-1 (ISO 8859-1), same as web browsers.
*   Move around files to lib/, prog/, and test/ directories; fix top level make
*   Change name of struct newstring to struct newstr for consistency
*   Change cleanf() to take entire bibliographies and not just references in  
    preparation for cross-referencing handling in bib2xml

BIB2XML

*   Do a nice job of translating latex codes to Unicode
*   Bump version number to 3.12

COPAC2XML

*   Bump version number to 1.2

END2XML

*   Bump version number to 3.13

ISI2XML

*   Move times cited field to notes
*   Bump version number to 2.5

MED2XML

*   Bump version number to 2.3

RIS2XML

*   Bump version number to 2.11

MODSIN

*   add URL support to identifier type="uri"

XML2BIB

*   Make sure illegal bibtex isn't outputted (including quotes when brackets  
    aren't requested), and do a nice job of Unicode to latex.
*   Allow any non-space and non-tab to be output as bibtex key identifiers
*   Add URL support
*   Bump version number to 2.6

XML2END

*   fix output of ISSN/ISBN/URL/etc.
*   Bump version number to 2.3

XML2RIS

*   add number/issue output
*   Bump version number to 2.3

MODSCLEAN

*   Bump version number to 1.1

## 3.14

2/09/2005

GLOBAL CHANGES FOR THE TOMODS CONVERTERS

*   The current programs add an underscore and the reference count to the  
    reference id by default. This is changed so that it only occurs when  
    requested using the new -a or --add-refcount flags.
*   Fixed bug where the reference count wasn't used when outputting individual  
    files for each reference. This is, of course, dependent on the -a  
    or --add-refcount flags.
*   change --verbose flag to only output warnings
*   add --debug flag for full output useful in hunting down problems
*   Major rewrite of the converters:  
    Common framework is in lib/tomods.c  
    Variables and unique function pointers defined by struct convert\_rules  
    Must define readf() to read a single reference from a file  
    Must define processf() to convert raw input into tag/data/level in a  
    field using native tags  
    Define cleanf() or set to NULL to define function to clean up data  
    such as LaTeX codes  
    Must define convertf() to convert native tag/data/level elements into  
    those appropriate for MODS XML output.

BIB2XML

*   add URL to list of recognized bibtex entries
*   bump version number to 3.11

COPAC2XML

*   bump version number to 1.1

END2XML

*   fix bug in magazine article that misplaced article title
*   fix bug that lost track of reference type information
*   bump version number to 3.12

ISI2XML

*   parse multiple keywords placed under same tag
*   bump version number to 2.4

MED2XML

*   bump version number to 2.2

RIS2XML

*   bump version number to 2.10

## 3.13

12/15/2004

COPAC2XML

*   write first version of program

ISI2XML

*   fix bugs in handling multi-author references
*   bump version number to 2.3

END2XML

*   clean up some left over references to RIS
*   fix incrementing in waslast\_tag()
*   bump version number to 3.11

## 3.12

11/22/2004

BIB2XML

*   add support for FTP = {\\urllink{http://online.ref.com}}
*   add support for TITLE = {\\href{http://online.ref.com}Real Title}
*   add conversion for latex encodings character into unicode; also fixes some  
    processing bugs due to names with a diaresis
*   add support for reading in digital object identifier (doi)
*   add unpublished type (and "new" genre type in MODS)
*   add proceedings type
*   add misc type
*   bump version number to 3.10

END2XML

*   switch order of "Book" and "Book Section" now that the Refer-format  
    handling introduced a bug that caused both to be recognized as Book
*   bump version number to 3.10

MED2XML

*   silence compile warnings
*   pass digital object identifier (doi) information to MODS
*   bump version number to 2.1

XML2BIB

*   fix command line parsing
*   pass digital object identifier (doi) output to bibtex
*   add unpublished and misc types to output
*   bump version number to 2.5

XML2END

*   fix help message
*   bump version number to 2.2

MAKEFILE

*   fix typo in "make install" target
*   repair loss of med2xml in makefile

## 3.11

9/29/2004

BIB2XML

*   re-write bibtex parser to handle references with missing or empty  
    reference ids
*   use common title mangling
*   support table of contents
*   bump version number to 3.9

END2XML

*   use common title mangling
*   bump version number to 3.9

ISI2XML

*   use common title mangling
*   bump version number to 2.2

RIS2XML

*   use common title mangling
*   bump version number to 2.9

MODSCLEAN

*   verson 1.0 of the program

XML2BIB

*   fix bug where -fc/--final-comma isn't removed from argument list
*   merge corporate and non-corporate authors/editors into same bibtex line
*   support table of contents data
*   fix distinction between PROCEEDINGS and INPROCEEDINGS data types
*   bump version number to 2.4

MODSIN

*   make role="creator" equivalent to role="author" to handle LOC input
*   support table of contents data

MODSOUT

*   support table of contents data

TITLE

*   merge all copies of title mangling into library

XML

*   properly handle XML comments in files

## 3.10

9/23/2004

BIB2XML

*   add explicit fflushes to try and help python deadlocks
*   bump version number to 3.8

END2XML

*   add explicit fflushes to try and help python deadlocks
*   fix typo in "Conference Proceedings" type
*   bump version number to 3.8

ISI2XML

*   handle processing of names with and without commas properly
*   bump version number to 2.1

MED2XML

*   write MODS version of converter
*   set version to 2.0

RIS2XML

*   handle processing of names with and without commas properly
*   bump version number to 2.8

XML2BIB

*   output author/year combo when REFNUM is not already defined
*   add keyword, abstract, note to output
*   bump version number to 2.3

MODSIN

*   fix merging of placeTerm when both by code and by text are present

MODSOUT

*   add explicit fflushes to try and help python deadlocks

NAME

*   merge all functions for name mangling into library

## 3.9

09/01/2004

BIB2XML

*   convert "." to ". " in names so that names like G.P. Smith don't lose  
    information
*   bump version number to 3.7

END2XML

*   modify parser so that refer-style bibliographies are handled naturally
*   convert "." to ". " in names so that names like G.P. Smith don't lose  
    information
*   bump version number to 3.7

ISI2XML

*   write new MODS version
*   bump version number to 2.0

RIS2XML

*   use newstr\_trimendingws
*   convert "." to ". " in names so that names like G.P. Smith don't lose  
    information
*   bump version number to 2.7

XML2BIB

*   add corporate authors/editors to output
*   bump version number to 2.2

XML2RIS

*   add corporate authors/editors to output
*   bump version number to 2.2

MODSIN

*   convert numeric month to name
*   handle multiple roles per person
*   prevent unnecessary decents through the XML tree structure
*   fix core dump in modsin\_detailr due to copy/paste bug
*   fix role processing in corporation names

MODSOUT

*   some code cleanups
*   if a reference ID cannot be found, first try to output one based  
    on the first author and four-digit year and refnum, eg. Jones2000\_123,  
    and then default to a ref#### ID

NEWSTR

*   add newstr\_trimendingws

XML

*   fix identification of tags like <title> that scrambled the XML <br> hierarchy</li> </ul> <h2 id="38">3.8</h2> <p>07/29/2004</p> <p>XML2BIB</p> <ul> <li>fix bug in command line parsing</li> <li>fix bug where ending commas are missing</li> <li>add periods after abbreviated given names</li> <li>bump version number to 2.1</li> </ul> <p>XML2END</p> <ul> <li>add periods after abbreviated given names</li> <li>bump version number to 2.1</li> </ul> <p>XML2RIS</p> <ul> <li>add periods after abbreviated given names</li> <li>bump version number to 2.1</li> </ul> <p>MODSIN</p> <ul> <li>handle pages either as details or extents</li> </ul> <p>MODSOUT</p> <ul> <li>fix bug where empty names were output</li> <li>if given names are abbreviations, e.g. "A. B. Jones", drop periods</li> <li>write out single pages as details, not extents</li> </ul> <h2 id="37">3.7</h2> <p>07/27/2004</p> <p>BIB2XML</p> <ul> <li>fix bug where multi-line authors w/o trailing spaces were merged</li> <li>add publisher and address fields to book and report types</li> <li>add/fix genre output to many reference types</li> <li>add support for given name separation for MODSOUT</li> <li>add issue field to article type</li> <li>bump version number to 3.6</li> </ul> <p>END2XML</p> <ul> <li>add support for given name separation for MODSOUT</li> <li>add/fix genre output to many reference types</li> <li>fix core dump on empty input</li> <li>bump version number to 3.6</li> </ul> <p>RIS2XML</p> <ul> <li>add support for given name separation for MODSOUT</li> <li>handle case where last reference in file is missing end tag</li> <li>add/fix genre/typeOfResource output to many reference types</li> <li>bump version number to 2.6</li> </ul> <p>XML2BIB</p> <ul> <li>write first MODS version of the program</li> <li>bump version number to 2.0</li> </ul> <p>XML2RIS</p> <ul> <li>write first MODS version of the program</li> <li>bump version number to 2.0</li> </ul> <p>FIELDS</p> <ul> <li>add function fields\_maxlevel()</li> </ul> <p>MODSOUT</p> <ul> <li>add support for separating each part of the given name to a separate<br> namePart construct</li> <li>write out given names before family name</li> <li>ensure that both start and end elements are written when page<br> extents are output</li> </ul> <p>NEWSTRING</p> <ul> <li>add newstr\_toupper(), newstr\_prepend() functions</li> </ul> <h2 id="36">3.6</h2> <p>06/1/2004</p> <p>BIB2XML</p> <ul> <li>bump version number to 3.5</li> </ul> <p>END2XML</p> <ul> <li>bump version number to 3.5</li> </ul> <p>RIS2XML</p> <ul> <li>clean up reference parsing loop as per end2xml from bibutils v 2.16</li> <li>fix missing break statement in process\_cite that put titles into dates</li> <li>move abstracts marked by "N2" into the main record, not host</li> <li>bump version number to 2.5</li> </ul> <p>MODSOUT</p> <ul> <li>move part element of relatedItems to the very last element outputted<br> (needs to be after identifier and .xsd would suggest that it should be<br> the last item)</li> </ul> <h2 id="35">3.5</h2> <p>05/28/2004</p> <p>BIB2XML</p> <ul> <li>clean up name processing</li> <li>add corporation recognition for names</li> <li>add -c, --corporation-file to input corporation names</li> <li>add genre type periodical to journal articles</li> <li>bump version number 3.4</li> </ul> <p>END2XML</p> <ul> <li>add genre type periodical to journal articles</li> <li>add genre type periodical to magazines</li> <li>add genre type thesis to thesis</li> <li>fix read\_refs() to not require leading %0 as per version 2.16</li> <li>use fields\_init()</li> <li>clean up name processing</li> <li>add -c, --corporation-file to input corporation names</li> <li>bump version number 2.5</li> </ul> <p>RIS2XML</p> <ul> <li>add genre type periodical to journal articles</li> <li>clean up name processing</li> <li>add corporation recognition for names</li> <li>add -c, --corporation-file to input corporation names</li> <li>bump version number 2.4</li> </ul> <p>MODSOUT</p> <ul> <li>separate genre output into own function, have it automatically detect<br> genre terms under the "marc authority", make sure genre type is properly<br> unicode formated, allow multiple genres to be output per level of <br> reference</li> <li>separate typeofResource output into own function, and have it make sure<br> that output matches the legal values, generate error if it doesn't</li> <li>handle corporation name output</li> </ul> <h2 id="34">3.4</h2> <p>01/31/2004</p> <p>BIB2XML</p> <ul> <li>add "?" as title/subtitle separator like ":"</li> <li>bump version to 3.3</li> </ul> <p>END2XML</p> <ul> <li>add "?" as title/subtitle separator like ":"</li> <li>bump version to 2.4</li> </ul> <p>RIS2XML</p> <ul> <li>do some reference type/tag additions</li> <li>fix bug where titles weren't being put in output</li> <li>add "?" as title/subtitle separator like ":"</li> <li>bump version to 2.3</li> </ul> <p>MODSOUT</p> <ul> <li>fix shorttitle output so that if long version has subtitle,<br> shorttitle is always output...otherwise only output if<br> shorttitle is different than long title</li> </ul> <h2 id="33">3.3</h2> <p>01/24/04</p> <p>END2XML</p> <ul> <li>correct typeOfResource "software" to "software, multimedia"</li> <li>have shorttitles terminate at colons</li> <li>bump version to 2.3</li> </ul> <p>MODOUTS</p> <ul> <li>allow single and double quotes to be placed directly in output</li> </ul> <h2 id="32">3.2</h2> <p>1/22/2004</p> <p>BIB2XML</p> <ul> <li>add -un/--unicode-no-bom option for writing unicode w/o adding the<br> byte order mark at the beginning of the file</li> <li>assign dates in part and in dateIssued by reference type</li> <li>bump version to 3.2</li> </ul> <p>END2XML</p> <ul> <li>add -un/--unicode-no-bom option for writing unicode w/o adding the<br> byte order mark at the beginning of the file</li> <li>fix LEVEL\_HOST/LEVEL\_MAIN mismatches for reference types</li> <li>assign dates in part and in dateIssued by reference type</li> <li>bump version to 2.2</li> </ul> <p>RIS2XML</p> <ul> <li>add -un/--unicode-no-bom option for writing unicode w/o adding the<br> byte order mark at the beginning of the file</li> <li>assign dates in part and in dateIssued by reference type</li> <li>bump version to 2.2</li> </ul> <p>MODSOUT</p> <ul> <li>convert to proper UTF-8 output</li> <li>put "ref" in front of all numeric ID cite key for compliance with<br> MODS DTD "rules"</li> <li>protect mods ID from output illegal characters and IDs that start<br> with non-alphanumerics</li> <li>fix over-zealousness of fields\_find()</li> <li>distinguish between dates that fall in <part> and those<br> in <dateIsssued></li> </ul> <h2 id="31">3.1</h2> <p>1/21/2004</p> <p>BIB2XML</p> <ul> <li>add -d/--drop-key option</li> <li>bump version to 3.1</li> </ul> <p>END2XML</p> <ul> <li>add -d/--drop-key option</li> <li>fix loss of year output for newspaper article type</li> <li>fix moving picture/moving image issue for film type</li> <li>bump version to 2.1</li> </ul> <p>RIS2XML</p> <ul> <li>add -d/--drop-key option</li> <li>bump version to 2.1</li> </ul> <p>MODSOUT</p> <ul> <li>fix bug where part is output in main level</li> <li>add mods ID for cite key, controllable by -d/--drop-key</li> </ul> <h2 id="30">3.0</h2> <p>1/20/2004</p> <p>BIB2XML</p> <ul> <li>new version 3.0</li> </ul> <p>END2XML</p> <ul> <li>new version 2.0</li> </ul> <p>RIS2XML</p> <ul> <li>new version 2.0</li> </ul></title>
