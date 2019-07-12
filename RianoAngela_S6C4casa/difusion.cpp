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
    double dy=0.01;
    double dx=0.01;
    int nx=l/dx;
    double dt=(0.5*dx)/v;
    //arreglos
    double presente[nx]*[nx];
    double futuro[nx]*[nx];
    
    ofstream outfile;
    outfile.open("datos.dat");
    
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
        outfile<<"/n";
    }
    
    //for en el tiempo
    for (int t=1; t<=2500;t++)
    {
        //for en x
        for(int i=0;i<=nx-1;i++)
        {
            //for en y
            for (int k=0; k<=nx-1;i++)
            {
                futuro[i][k]=(((v*dt/dx*dx)*(presente[i-1][k]+presente[i+1][k]-2*presente[i][k]))+((v*dt/dy*dy)*(presente[i][k-1]+presente[i][k+1]-2*presente[i][k])))+presente[i][k];
            }
        }
        //for en el espacio para cambiar las variables
        for (int i=0;i<=nx;i++)
        {
            for (int k=0;k<=nx;k++)
            {
                 presente[i][k]=futuro[i][k]; 
            }
        }
        
        for(int i=0;i<=nx-1;i++)
        {
            //for en y
            for (int k=0; k<=nx-1;i++)
            {
                if (t==0 || t==100 || t==2500)
                {
                    outfile<<futuro[i][k]<<" ";
                }
            }
            outfile<<"/n";
        }
    }
    
    outfile.close();
    return 0;
}
