run:
	g++ -g -o main main.cpp
	./main

report:
	xelatex report.tex
	bibtex report
	xelatex report.tex
	xelatex report.tex
	rm -f *.aux *.log *.out *.toc *.bbl *.blg *.blx.bib *.run.xml *.synctex.gz *.bib

all: reprot run

clean:
	rm -f main
	rm -f *.aux *.log *.out *.pdf *.toc *.bbl *.blg *.blx.bib *.run.xml *.synctex.gz *.bib