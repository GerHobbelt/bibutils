#
# bibutils converters MAKEFILE
#

CFLAGS     = -I ../lib
LIBDIR     = -L../lib/.libs -L../lib
PROGS      = bib2xml biblatex2xml copac2xml end2xml endx2xml isi2xml med2xml \
             ris2xml \
             xml2ads xml2bib xml2end xml2isi xml2ris xml2wordbib modsclean

all: $(PROGS)

args.o : args.c
	$(CC) $^ -DCURR_VERSION="\"$(VERSION)\"" -DCURR_DATE="\"$(DATE)\"" $(CFLAGS) -c -o $@


bib2xml : bib2xml.o bibprog.o tomods.o args.o 
	$(CC) $^ $(LIBDIR) -lbibutils -o $@

biblatex2xml : biblatex2xml.o bibprog.o tomods.o args.o 
	$(CC) $^ $(LIBDIR) -lbibutils -o $@

copac2xml : copac2xml.o bibprog.o tomods.o args.o  
	$(CC) $^ $(LIBDIR) -lbibutils -o $@

end2xml : end2xml.o bibprog.o tomods.o args.o 
	$(CC) $^ $(LIBDIR) -lbibutils -o $@

endx2xml : endx2xml.o bibprog.o tomods.o args.o 
	$(CC) $^ $(LIBDIR) -lbibutils -o $@

isi2xml : isi2xml.o bibprog.o tomods.o args.o 
	$(CC) $^ $(LIBDIR) -lbibutils -o $@

med2xml : med2xml.o bibprog.o tomods.o args.o 
	$(CC) $^ $(LIBDIR) -lbibutils -o $@

ris2xml : ris2xml.o bibprog.o tomods.o args.o 
	$(CC) $^ $(LIBDIR) -lbibutils -o $@

xml2ads : xml2ads.o bibprog.o args.o 
	$(CC) $^ $(LIBDIR) -lbibutils -o $@

xml2bib : xml2bib.o bibprog.o args.o 
	$(CC) $^ $(LIBDIR) -lbibutils -o $@

xml2end : xml2end.o bibprog.o args.o 
	$(CC) $^ $(LIBDIR) -lbibutils -o $@

xml2isi : xml2isi.o bibprog.o args.o 
	$(CC) $^ $(LIBDIR) -lbibutils -o $@

xml2ris : xml2ris.o bibprog.o args.o 
	$(CC) $^ $(LIBDIR) -lbibutils -o $@

xml2wordbib : xml2wordbib.o bibprog.o args.o 
	$(CC) $^ $(LIBDIR) -lbibutils -o $@

modsclean : modsclean.o bibprog.o tomods.o args.o 
	$(CC) $^ $(LIBDIR) -lbibutils -o $@

test:

clean:
	rm -f *.o core 

realclean:
	rm -f *.o core $(PROGS)
