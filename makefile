EXEC = othello
SRCDIR = src
INCLUDEDIR = include
DOCDIR = doc
LIBDIR = lib
SRCTESTDIR=srctest
TESTDIR=test
BINDIR = bin
CC = gcc
AR = ar
CREATE = mkdir

CFLAGS = -Wall -pedantic -g -I$(INCLUDEDIR) 
LDFLAGS= -L$(LIBDIR) -lothello

all : const $(BINDIR)/$(EXEC) $(DOCDIR)/rapport/rapport.pdf $(DOCDIR)/html/index.html $(DOCDIR)/latex/refman.pdf $(TESTDIR)/test_affichagePlateau $(TESTDIR)/test_caractereEnEntier $(TESTDIR)/test_majPlateau $(TESTDIR)/test_obtenirCouleurGagnant $(TESTDIR)/test_partieTerminee $(TESTDIR)/testCouleur $(TESTDIR)/testCoup $(TESTDIR)/testCoups $(TESTDIR)/testPion $(TESTDIR)/testPlateau $(TESTDIR)/testPosition

prg : const $(BINDIR)/$(EXEC)

const :
	@ if ! [ -d $(BINDIR) ]; then \
		echo "Création du dossier $(BINDIR)"; \
		$(CREATE) $(BINDIR); \
	fi
	@ if ! [ -d $(LIBDIR) ]; then \
		echo "Création du dossier $(LIBDIR)"; \
		$(CREATE) $(LIBDIR); \
	fi
	@ if ! [ -d $(TESTDIR) ]; then \
		echo "Création du dossier $(TESTDIR)"; \
		$(CREATE) $(TESTDIR); \
	fi

doc : $(DOCDIR)/rapport/rapport.pdf $(DOCDIR)/html/index.html $(DOCDIR)/latex/refman.pdf

tests : $(TESTDIR)/test_affichagePlateau $(TESTDIR)/test_caractereEnEntier $(TESTDIR)/test_majPlateau $(TESTDIR)/test_obtenirCouleurGagnant $(TESTDIR)/test_partieTerminee $(TESTDIR)/testCouleur $(TESTDIR)/testCoup $(TESTDIR)/testCoups $(TESTDIR)/testPion $(TESTDIR)/testPlateau $(TESTDIR)/testPosition

$(TESTDIR)/% : $(SRCTESTDIR)/%.o $(LIBDIR)/libothello.a
	$(CC) -o $@ $< $(LDFLAGS) -lcunit

$(LIBDIR)/libothello.a: $(SRCDIR)/majPlateau.o $(SRCDIR)/coupIA.o $(SRCDIR)/faireUnePartie.o $(SRCDIR)/placerCoup.o $(SRCDIR)/partieTerminee.o $(SRCDIR)/affichagePlateau.o $(SRCDIR)/caractereEnEntier.o $(SRCDIR)/pion.o $(SRCDIR)/position.o $(SRCDIR)/plateau.o $(SRCDIR)/couleur.o $(SRCDIR)/coup.o $(SRCDIR)/coups.o $(SRCDIR)/obtenirCouleurGagnant.o
	ar -r $@ $^

$(DOCDIR)/html/index.html:
	doxygen

$(DOCDIR)/latex/refman.pdf: $(DOCDIR)/latex/refman.tex
	cd $(DOCDIR)/latex/; make; cd ../..

$(DOCDIR)/latex/refman.tex:
	doxygen

$(DOCDIR)/rapport/rapport.pdf:
	cd $(DOCDIR)/rapport/; pdflatex -synctex=1 -interaction=nonstopmode rapport.tex; cd ../..

$(BINDIR)/$(EXEC) : $(SRCDIR)/majPlateau.o $(SRCDIR)/coupIA.o $(SRCDIR)/faireUnePartie.o $(SRCDIR)/placerCoup.o $(SRCDIR)/partieTerminee.o $(SRCDIR)/affichagePlateau.o $(SRCDIR)/caractereEnEntier.o $(SRCDIR)/pion.o $(SRCDIR)/position.o $(SRCDIR)/plateau.o $(SRCDIR)/couleur.o $(SRCDIR)/coup.o $(SRCDIR)/coups.o $(SRCDIR)/obtenirCouleurGagnant.o $(SRCDIR)/main.o 
	$(CC) -o $@  $(SRCDIR)/majPlateau.o $(SRCDIR)/coupIA.o $(SRCDIR)/faireUnePartie.o $(SRCDIR)/placerCoup.o $(SRCDIR)/partieTerminee.o $(SRCDIR)/affichagePlateau.o $(SRCDIR)/caractereEnEntier.o $(SRCDIR)/pion.o $(SRCDIR)/position.o $(SRCDIR)/plateau.o $(SRCDIR)/couleur.o $(SRCDIR)/coup.o $(SRCDIR)/coups.o $(SRCDIR)/obtenirCouleurGagnant.o $(SRCDIR)/main.o 

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(SRCTESTDIR)/%.o: $(SRCTESTDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BINDIR)
	rm -rf $(LIBDIR)/*.a
	rm -rf $(SRCDIR)/*.o
	rm -rf $(SRCTESTDIR)/*.o
	rm -rf $(TESTDIR)
	rm -rf $(DOCDIR)/rapport/*.pdf
	rm -rf $(DOCDIR)/html
	rm -rf $(DOCDIR)/latex
