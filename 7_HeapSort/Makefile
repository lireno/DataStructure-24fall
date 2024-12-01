run:
	g++ -O2 -std=c++17 -o test test.cpp
	./test

report:
	xelatex report.tex
	xelatex report.tex
	# bibtex report
	# xelatex report.tex
	# xelatex report.tex
	rm -f *.aux *.log *.out *.toc *.bbl *.blg *.blx.bib *.run.xml *.synctex.gz *.bib

all: report run

clean:
	rm -f test
	rm -f *.aux *.log *.out *.pdf *.toc *.bbl *.blg *.blx.bib *.run.xml *.synctex.gz *.bib
