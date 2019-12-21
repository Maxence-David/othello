EXEC = othello
SRCDIR = src
INCLUDEDIR = include
DOCDIR = doc
LIBDIR = lib
TESTDIR=tests
BINDIR = bin
CC = gcc
AR = ar
CREATE = mkdir

CFLAGS = -Wall -pedantic -g -I$(INCLUDEDIR)
LDFLAGS= -L$(LIBDIR) -lothello

all : $(BINDIR)/$(EXEC)

doc : $(DOCDIR)/rapport/rapport.pdf

$(DOCDIR)/rapport/rapport.pdf:
	cd $(DOCDIR)/rapport/; pdflatex -synctex=1 -interaction=nonstopmode rapport.tex; cd ../..



$(BINDIR)/$(EXEC) : $(SRCDIR)/majPlateau.o $(SRCDIR)/coupIA.o $(SRCDIR)/faireUnePartie.o $(SRCDIR)/placerCoup.o $(SRCDIR)/partieTerminee.o $(SRCDIR)/caractereEnEntier.o $(SRCDIR)/pion.o $(SRCDIR)/position.o $(SRCDIR)/plateau.o $(SRCDIR)/couleur.o $(SRCDIR)/coup.o $(SRCDIR)/coups.o 
	$(CC) -o $@  $(SRCDIR)/majPlateau.o $(SRCDIR)/coupIA.o $(SRCDIR)/faireUnePartie.o $(SRCDIR)/placerCoup.o $(SRCDIR)/partieTerminee.o $(SRCDIR)/caractereEnEntier.o $(SRCDIR)/pion.o $(SRCDIR)/position.o $(SRCDIR)/plateau.o $(SRCDIR)/couleur.o $(SRCDIR)/coup.o $(SRCDIR)/coups.o 

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*.a
	rm -rf $(SRCDIR)/*.o
	rm -rf $(TESTDIR)/*
	rm -rf $(DOCDIR)/rapport/*.pdf
