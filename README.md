About
-----

[hs-bibutils] is library with Haskell bindings to Chris Putnam's
[bibutils], a library that interconverts between various bibliography
formats using a common MODS-format XML intermediate.

[hs-bibutils] can be used with [pandoc-citeproc] to read and use various
bibliographic database formats for processing and automatically formatting
citations and references according to a [CSL] style.

[pandoc-citeproc] adds to [pandoc], the famous [Haskell] text processing
tool, a Bibtex like citation and bibliographic formatting and generation
facility.

[CSL] is an XML language for specifying citation and bibliographic
formatting, similar in principle to BibTeX `.bst` files or the binary
style files in commercial products like Endnote or Reference Manager.

Documentation
-------------

The [Haddock] generated documentation is available here:

<https://hackage.haskell.org/package/hs-bibutils/docs/Text-Bibutils.html>

Bug Reports
-----------

To submit bug reports you can use the [hs-bibutils] bug tracking
system available at the following address:

<https://github.com/wilx/hs-bibutils/issues>

Credits
-------

Thanks to [Chris Putnam] for his help.

Author
------

Andrea Rossato

`andrea.rossato at unitn dot it`

Maintainer
----------

Václav Haisman

`vhaisman at gmail dot com`

Links to Related Projects
----------------

Bibutils
:    <https://sourceforge.net/p/bibutils/home/Bibutils/>

Pandoc
:    <https://pandoc.org/>

Pandoc-Citeproc
:    <https://github.com/jgm/pandoc-citeproc>

Citeproc-hs:
:    <http://istitutocolli.org/repos/citeproc-hs/>

CSL
:    <http://xbiblio.sourceforge.net/csl/>

Legal
-----

This software is released under the GNU GPL. See LICENSE for more
details.

This is an early, "alpha" release. It carries no warranties of any kind.

Copyright © 2008 – 2010 Andrea Rossato

[hs-bibutils]: https://github.com/wilx/hs-bibutils
[bibutils]: https://sourceforge.net/p/bibutils/home/Bibutils/
[Hackage]: http://hackage.haskell.org/cgi-bin/hackage-scripts/package/hs-bibutils
[citeproc-hs]: http://istitutocolli.org/repos/citeproc-hs/
[CSL]: http://citationstyles.org/
[pandoc]: http://pandoc.org/
[pandoc-citeproc]: https://github.com/jgm/pandoc-citeproc
[Zotero]: http://www.zotero.org
[MODS]: http://www.loc.gov/mods/
[Bruce D'Arcus]: http://community.muohio.edu/blogs/darcusb/
[John MacFarlane]: http://johnmacfarlane.net/
[Chris Putnam]: http://www.scripps.edu/~cdputnam/
[Haskell]:  http://www.haskell.org/
[Haddock]:  http://www.haskell.org/haddock/



=====================================================================================

=====================================================================================

=====================================================================================




The bibutils program set interconverts between various bibliography formats using a common MODS-format XML intermediate. For example, one can convert RIS-format files to Bibtex by doing two transformations: RIS->MODS->Bibtex. By using a common intermediate for N formats, only 2N programs are required and not N²-N. These programs operate on the command line and are styled after standard UNIX-like filters.

I primarily use these tools at the command line, but they are suitable for scripting and have been incorporated into a number of different bibliographic projects.

The Library of Congress's Metadata Object Description Schema (MODS) XML format is described here. I've written a short introduction to using MODS that might be useful.

## Programs:

Program Description
bib2xml convert BibTeX to MODS XML intermediate
biblatex2xml    convert BibLaTeX to MODS XML intermediate
bibdiff compare two bibliographies after reading into the bibutils internal format
copac2xml   convert COPAC format references to MODS XML intermediate
end2xml convert EndNote (Refer format) to MODS XML intermediate
endx2xml    convert EndNote XML to MODS XML intermediate
isi2xml convert ISI web of science to MODS XML intermediate
med2xml convert Pubmed XML references to MODS XML intermediate
modsclean   a MODS to MODS converter for testing puposes mostly
nbib2xml    convert Pubmed/National Library of Medicine nbib format to MODS XML intermedidate
ris2xml convert RIS format to MODS XML intermediate
xml2ads convert MODS XML intermediate into Smithsonian Astrophysical Observatory (SAO)/National Aeronautics and Space Administration (NASA) Astrophyics Data System or ADS reference format (converter submitted by Richard Mathar)
xml2bib convert MODS XML intermediate into BibTeX
xml2biblatex    convert MODS XML intermediate into BibLaTeX
xml2end convert MODS XML intermediate into format for EndNote
xml2isi convert MODS XML intermediate to ISI format
xml2nbib    convert MODS XML intermediate to Pubmed/National Library of Medicine nbib format
xml2ris convert MODS XML intermediate into RIS format
xml2wordbib convert MODS XML intermediate into Word 2007 bibliography format


## Development History:

Version 6. Library changes forced change of major version.

Version 5. User visible changes change default input and output character set to UTF-8 Unicode and ability to write MODS XML in multiple character sets.

Version 4. User visible changes are alteration of library API.

Version 3

Version 2


##  Frequently Asked Questions:

The programs don't run for me. What am I doing wrong? If you send me this question, I would immediately have to ask for more information. So do us both a favor and provide more information. The follow items address specific problems:

"command not found" The message "command not found" on Linux/UNIX/MacOSX systems indicates that the commands cannot be found. This could mean that the programs are not flagged as being executable (run "chmod ugo+x xml2bib" for the appropriate binaries) or the executables are not in your current path (and have to be specified directly like ./xml2bib). A quick web search on chmod or path variables should provide many detailed resources.

I'm running MacOSX and I just get a terminal when I double-click on the programs. Simply put, this is not the way to run the programs. You want to run the terminal first and then issue the commands at the command line. It should be under Applications->Utilities->Terminal on most MacOSX systems I've seen. If you just double-click the program, the terminal corresponds to the input to the tool. Not so useful. Some links to get you started running the terminal in a standard UNIX-like fashion are at TerminalBasics.pdf, macdevcenter.com, and ee.surrey.ac.uk.

This stuff is great, how can I help? OK, I actually don't get this question so often, though I have gotten very useful help through people who have willingly sent useful bug reports and sample problematic data to allow me to test these programs. I willingly accept bug reports, patches, new filters, suggestions on program improvements or better documentation and the like. All I can say is that users (or programmers) who contact me with these sorts of things are far more likely to get their itches scratched.

I am interested in bug reports and problems in conversions. Feel free to e-mail me if you run into these issues. The absolute best bug reports provide error messages from the operating systems and/or input and outputs that detail the problems. Please remember that I'm not looking over your shoulder and I cannot read your mind to figure out what you are doing--"It doesn't work." isn't a bug report I can help you with.

## License

All versions of bibutils are relased under the GNU Public License (GPL) version 2. In a nutshell, feel free to download, run, and modify these programs as required. If you re-release these, you need to release the modified version of the source. (And I'd appreciate patches as well...if you care enough to make the change, then I'd like to see what you're adding or fixing.)
