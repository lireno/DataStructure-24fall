run:
	g++ -g -o test_BST test_BST.cpp
	./test_BST

report:
	xelatex report.tex
	bibtex report
	xelatex report.tex
	xelatex report.tex
	rm -f *.aux *.log *.out *.toc *.bbl *.blg *.blx.bib *.run.xml *.synctex.gz *.bib

all: reprot run

clean:
	rm -f test_BST
	rm -f *.aux *.log *.out *.pdf *.toc *.bbl *.blg *.blx.bib *.run.xml *.synctex.gz *.bib