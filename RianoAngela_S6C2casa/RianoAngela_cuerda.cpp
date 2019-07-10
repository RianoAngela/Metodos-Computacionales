#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int c=300;
    double A0=0.01;
    double l=1.0;
    double tmax=0.1;
    
    
    //Condicion de establidad
    double dx=0.005;
    double dt=(dx*0.5)/(c**2);
    
    //Arreglos
    double pasado[];
    double presente[];
    double futuro[];
    
    //Condiciones iniciales con fronteras fijas
    for (int i=0;i<=l;i++)
    {  
        if (i==l/2)
        {
            pasado[i]=A0;
        }
        if (i==0 && i==l)
        {
            pasado[i]=0;
        }
        if (i<l/2)
        {
            pasado[i]=pasado[i]*A0*(l/2);
        }
        if (i>l/2)
        {
            pasado[i]=pasado[i]*(-A0)*(l/2);
        }  
    }
    
    //condiciones iniciales con una frontera fija y la otra libre
    for (int i=0;i<=l;i++)
    {  
        if (i==l/2)
        {
            pasado[i]=A0;
        }
        if (i==0)
        {
            pasado[i]=0;
        }
        if (i==l)
        {
            pasado[i]=pasado[i-1];
        }
        if (i<l/2)
        {
            pasado[i]=pasado[i]*A0*(l/2);
        }
        if (i>l/2)
        {
            pasado[i]=pasado[i]*(-A0)*(l/2);
        }  
    }
    
    //paso 1
    float t=0.0;
    presente=(1/2)*((((c**2*dt**2)/dx**2)*(pasado+pasado-2*pasado))+(2*pasado));
    
    //for en el tiempo
    for (int t=0;t<=30;t++)
    {
        int contador=0;
        //for en el espacio
        for (int e=0; e<=l;e++)
        {     
            futuro[e]=(((c**2*dt**2)/dx**2)*(presente[e+1]+presente[e-1]-2*presente[e]))-pasado[e]+2*presente[e];
            contador++; 
        }
        //for en el espacio para cambiar las variables
        for (int es=0;es<=l;es++)
        {
            pasado[es]=presente[es];
            presente[es]=futuro[es];
        }
    }
    return 0;
}