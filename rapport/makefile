
all : rapport/rapport.pdf rapport/rapport.pdf

rapport/rapport.pdf:
	pdflatex -synctex=1 -interaction=nonstopmode rapport.tex;
	pdflatex -synctex=1 -interaction=nonstopmode rapport.tex;

clean : 
	rm -rf *.pdf
	rm -rf *.aux
	rm -rf *.log
	rm -rf *.toc