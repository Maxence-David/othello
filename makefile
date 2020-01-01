EXEC = othello
SRCDIR = src
INCLUDEDIR = include
DOCDIR = doc
LIBDIR = lib
TESTDIR=test
BINDIR = bin
CC = gcc
AR = ar
CREATE = mkdir

CFLAGS = -Wall -pedantic -g -I$(INCLUDEDIR)
LDFLAGS= -L$(LIBDIR) -lothello

all : const $(BINDIR)/$(EXEC)

const :
	@ if ! [ -d $(BINDIR) ]; then \
		echo "Création du dossier $(BINDIR)"; \
		$(CREATE) $(BINDIR); \
	fi

doc : $(DOCDIR)/rapport/rapport.pdf

test : $(TESTDIR)/$(EXEC)

$(TESTDIR)/$(EXEC) : $(TESTDIR)/test_affichagePlateau.o $(TESTDIR)/test_caractereEnEntier.o $(TESTDIR)/test_partieTerminee.o $(TESTDIR)/test_obtenirCouleurGagnant.o $(TESTDIR)/test_majPlateau.o $(TESTDIR)/testCouleur.o $(TESTDIR)/testCoup.o $(TESTDIR)/testPion.o $(TESTDIR)/testPlateau.o $(TESTDIR)/testPostition.o

$(DOCDIR)/rapport/rapport.pdf:
	cd $(DOCDIR)/rapport/; pdflatex -synctex=1 -interaction=nonstopmode rapport.tex; cd ../..

$(BINDIR)/$(EXEC) : $(SRCDIR)/majPlateau.o $(SRCDIR)/coupIA.o $(SRCDIR)/faireUnePartie.o $(SRCDIR)/placerCoup.o $(SRCDIR)/partieTerminee.o $(SRCDIR)/affichagePlateau.o $(SRCDIR)/caractereEnEntier.o $(SRCDIR)/pion.o $(SRCDIR)/position.o $(SRCDIR)/plateau.o $(SRCDIR)/couleur.o $(SRCDIR)/coup.o $(SRCDIR)/coups.o $(SRCDIR)/obtenirCouleurGagnant.o $(SRCDIR)/main.o 
	$(CC) -o $@  $(SRCDIR)/majPlateau.o $(SRCDIR)/coupIA.o $(SRCDIR)/faireUnePartie.o $(SRCDIR)/placerCoup.o $(SRCDIR)/partieTerminee.o $(SRCDIR)/affichagePlateau.o $(SRCDIR)/caractereEnEntier.o $(SRCDIR)/pion.o $(SRCDIR)/position.o $(SRCDIR)/plateau.o $(SRCDIR)/couleur.o $(SRCDIR)/coup.o $(SRCDIR)/coups.o $(SRCDIR)/obtenirCouleurGagnant.o $(SRCDIR)/main.o 

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(TESTDIR)/%.o : $(TESTDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BINDIR)
	rm -rf $(LIBDIR)/*.a
	rm -rf $(SRCDIR)/*.o
	rm -rf $(TESTDIR)/*.o
	rm -rf $(DOCDIR)/rapport/*.pdf
