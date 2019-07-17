Resultados.pdf : Resultados_hw2.tex
    pdflatex Resultados_hw2.tex
    
Resultados_hw2.tex : Plots_hw2.py 
    python Plots_hw2.py Fourier.py
    
Plots_hw2.py : leapfrog.dat euler.dat rungekutta.dat
    cpp EDOs.cpp
    
