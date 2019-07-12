#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    double l=1.0;
    double v=0.0001;
    double T=50.0;
    double tmax=2500;
    //condiciones de estabilidad
    double dx=0.01;
    int nx=l/dx;
    double dt=(0.25*dx)/v;
    double estab=(v*dt)/(dx*dx);
    //arreglos
    double presente[nx][nx];
    double futuro[nx][nx];
    
    ofstream outfile;
    outfile.open("datosT0.dat");
    
    //condiciones iniciales para fronteras fijas
    for (int i=0; i<nx;i++)
    {
        for (int k=0; k<nx;k++)
        {
            if (i>=20 && i<=40 && k>=40 && k<=60 )
            {
                presente[i][k]=100;
            }
            else 
            {
                presente[i][k]=T;
            }
            outfile<<presente[i][k]<<" ";
        } 
        outfile<<"\n";
    }
    outfile.close();
    
    outfile.open("datosT100.dat");
    //for en el tiempo
    int contador=0;
    for (int t=1; t<=2500;t++)
    {
        contador=contador+1;
        for(int i=1;i<nx;i++)
        {
            for (int k=1;k<nx;k++)
            {
                futuro[i][k]=((estab*(presente[i+1][k]+presente[i-1][k]-2*presente[i][k]))+(estab*(presente[i][k+1]+presente[i][k-1]-2* presente[i][k])))+presente[i][k];    
            }
        }
        
        //for en el espacio para cambiar las variables
        for (int i=1;i<nx;i++)
        {
            for (int k=1;k<nx;k++)
            {
                 presente[i][k]=futuro[i][k]; 
            }
        }
        
        if (contador==100)
        {
            for(int i=0;i<=nx;i++)
            {
                for (int k=0; k<=nx;k++)
                {
                    outfile<<presente[i][k]<<" ";
                }
                outfile<<"\n";
            }
        }
    }
    outfile.close();
    return 0;
}