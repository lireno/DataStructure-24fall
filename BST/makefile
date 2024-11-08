run:
	g++ -o2 -std=c++11 -o test test.cpp
	./test

report:
	xelatex report6.tex
	# xelatex report.tex
	# bibtex report
	# xelatex report.tex
	# xelatex report.tex
	rm -f *.aux *.log *.out *.toc *.bbl *.blg *.blx.bib *.run.xml *.synctex.gz *.bib

all: reprot run

clean:
	rm -f main test
	rm -f *.aux *.log *.out *.pdf *.toc *.bbl *.blg *.blx.bib *.run.xml *.synctex.gz *.bib