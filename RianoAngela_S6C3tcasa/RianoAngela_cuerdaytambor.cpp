#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    int c=300;
    double A0=0.01;
    double l=1.0;
    double tmax=0.1;
    double t=0.0;
    
    //Condicion de establidad
    double dx=0.005;
    double dt=(dx*0.5)/(c*c);
    
    //Arreglos
    int nx=l/dx;
    double pasado1[nx];
    double presente1[nx];
    double futuro1[nx];
    
    double pasado2[nx];
    double presente2[nx];
    double futuro2[nx];
    
    double pasado3[nx];
    double presente3[nx];
    double futuro3[nx];
    
    double pi = asin(1.0)*2.0;
    double A=A0*sin((3.0*c*tmax*pi)/l);
    
    ofstream outfile;
    outfile.open("datos.dat");
    
    ///CASO 1
    //Condiciones iniciales con fronteras fijas
    for (int i=0;i<=nx;i++)
    {  
        if (i==nx/2)
        {
            pasado1[i]=A0;
        }
        if (i==0 && i==nx)
        {
            pasado1[i]=0;
        }
        if (i<nx/2)
        {
            pasado1[i]=i*dx*(A0/(l/2));
        }
        if (i>nx/2)
        {
            pasado1[i]=(-i*dx*(A0/(l/2)))+(2*A0);
        } 
    }
    //paso 1
    for (int i=1;i<nx-1;i++)
    {
        presente1[i]=(1.0/2.0)*((((c*c*dt*dt)/dx*dx)*(pasado1[i-1]+pasado1[i+1]-(2*pasado1[i])))+(2*pasado1[i]));
    }
    //for en el tiempo
    for (int t=2;t<=300;t++)
    {
        int contador=0;
        //for en el espacio
        for (int e=0; e<=nx;e++)
        {     
            futuro1[e]=(((c*c*2*dt*dt*2)/dx*dx*2)*(presente1[e+1]+presente1[e-1]-2*presente1[e]))-pasado1[e]+2*presente1[e];
            contador=contador+1; 
            
        } 
        //for en el espacio para cambiar las variables
        for (int es=0;es<=nx;es++)
        {
            pasado1[es]=presente1[es];
            presente1[es]=futuro1[es];   
        }
        
    }
    
    outfile << "/n" << endl;
    
    ///CASO 2
    //condiciones iniciales con una frontera fija y la otra libre
    for (int i=0;i<=nx;i++)
    {  
        if (i==nx/2)
        {
            pasado2[i]=A0;
        }
        if (i==0)
        {
            pasado2[i]=0;
        }
        if (i==nx)
        {
            pasado2[i]=pasado2[i-1];
        }
        if (i<nx/2)
        {
            pasado2[i]=i*dx*(A0/(l/2));;
        }
        if (i>nx/2)
        {
            pasado2[i]=(-i*dx*(A0/(l/2)))+(2*A0);
        } 
    }
    //paso 1
    for (int i=1;i<nx-1;i++)
    {
        presente2[i]=(1.0/2.0)*((((c*c*dt*dt)/dx*dx)*(pasado2[i-1]+pasado2[i+1]-(2*pasado2[i])))+(2*pasado2[i]));
    }
    //for en el tiempo
    for (int t=2;t<=300;t++)
    {
        int contador=0;
        //for en el espacio
        for (int e=0; e<=nx;e++)
        {     
            futuro2[e]=(((c*c*dt*dt)/dx*dx)*(presente2[e+1]+presente2[e-1]-2*presente2[e]))-pasado2[e]+2*presente2[e];
            contador++; 
        } 
        //for en el espacio para cambiar las variables
        for (int es=0;es<=nx;es++)
        {
            pasado2[es]=presente2[es];
            presente2[es]=futuro2[es];   
        }
        
    }
    outfile << "/n" << endl;
    
    ///CASO 3
    //condiciones iniciales para una frontera fija y la otra periodica 
    for (int i=0;i<=nx;i++)
    {  
        if (i==0)
        {
            pasado3[i]=A;
        }
        else 
        {
            pasado3[i]=0;
        }
    }
    
    //paso 1
    for (int i=1;i<nx-1;i++)
    {
        presente3[i]=(1.0/2.0)*((((c*c*dt*dt)/dx*dx)*(pasado3[i-1]+pasado3[i+1]-(2*pasado3[i])))+(2*pasado3[i]));
    }
    //for en el tiempo
    for (int t=2;t<=300;t++)
    {
        int contador=0;
        //for en el espacio
        for (int e=0; e<=nx;e++)
        {     
            futuro3[e]=(((c*c*dt*dt)/dx*dx)*(presente3[e+1]+presente3[e-1]-2*presente3[e]))-pasado3[e]+2*presente3[e];
            contador++; 
        } 
        //for en el espacio para cambiar las variables
        for (int es=0;es<=nx;es++)
        {
            pasado3[es]=presente3[es];
            presente3[es]=futuro3[es];   
        }
        
    }
    
    outfile << "/n" << endl;
    ///TAMBOR 
    //condiciones iniciales del tambor
    
    
    outfile.close();
    return 0;
}