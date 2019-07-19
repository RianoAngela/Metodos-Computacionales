all: Plots_hw2.py Fourier.py
    python Plots_hw2.py Fourier.py
    
Plots_hw2.py : ODEs.cpp euler_0.005.dat euler_0.001.dat euler_0.0001.dat rk_0.005.dat rk_0.001.dat rk_0.0001.dat leap_0.005.dat leap_0.001.dat leap_0.0001.dat
    g++ EDOs.cpp
    
    

    
