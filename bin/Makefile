#
# bibutils converters MAKEFILE
#

CFLAGS     = -I ../lib
LDFLAGS	   = -L../lib/.libs -lbibutils
LIBDIR     = -L../lib
PROGS      = bib2xml biblatex2xml copac2xml end2xml endx2xml isi2xml med2xml \
             ris2xml ebi2xml wordbib2xml \
             xml2ads xml2bib xml2end xml2isi xml2ris xml2wordbib modsclean

all: $(PROGS)

args.o : args.c
	$(CC) $^ -DCURR_VERSION="\"$(VERSION)\"" -DCURR_DATE="\"$(DATE)\"" $(CFLAGS) -c -o $@

bib2xml : bib2xml.o bibprog.o tomods.o args.o
#	$(CC) $^ -o $@

biblatex2xml : biblatex2xml.o bibprog.o tomods.o args.o
#	$(CC) $^ -o $@

copac2xml : copac2xml.o bibprog.o tomods.o args.o 
#	$(CC) $^ -o $@

ebi2xml : ebi2xml.o bibprog.o tomods.o args.o
#	$(CC) $^ -o $@

end2xml : end2xml.o bibprog.o tomods.o args.o
#	$(CC) $^ -o $@

endx2xml : endx2xml.o bibprog.o tomods.o args.o
#	$(CC) $^ -o $@

isi2xml : isi2xml.o bibprog.o tomods.o args.o
#	$(CC) $^ -o $@

med2xml : med2xml.o bibprog.o tomods.o args.o
#	$(CC) $^ -o $@

wordbib2xml : wordbib2xml.o bibprog.o tomods.o args.o
#	$(CC) $^ -o $@

ris2xml : ris2xml.o bibprog.o tomods.o args.o
#	$(CC) $^ -o $@

xml2ads : xml2ads.o bibprog.o args.o
#	$(CC) $^ -o $@

xml2bib : xml2bib.o bibprog.o args.o
#	$(CC) $^ -o $@

xml2end : xml2end.o bibprog.o args.o
#	$(CC) $^ -o $@

xml2isi : xml2isi.o bibprog.o args.o
#	$(CC) $^ -o $@

xml2ris : xml2ris.o bibprog.o args.o
#	$(CC) $^ -o $@

xml2wordbib : xml2wordbib.o bibprog.o args.o
#	$(CC) $^ -o $@

modsclean : modsclean.o bibprog.o tomods.o args.o
#	$(CC) $^ -o $@

test:

clean:
	rm -f *.o core

realclean:
	rm -f *.o core $(PROGS)
