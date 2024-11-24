run:
	g++ -o main main.cpp
	./main

report:
	xelatex report.tex
	bibtex report
	xelatex report.tex
	xelatex report.tex
	rm -f *.aux *.log *.out *.toc *.bbl *.blg *.blx.bib *.run.xml *.synctex.gz *.bib

all: run

test: test.cpp
	g++ -g -O0 -o test test.cpp
	gdb test

clean:
	rm -f main test
	rm -f *.aux *.log *.out *.pdf *.toc *.bbl *.blg *.blx.bib *.run.xml *.synctex.gz *.bib