#include <iostream>
#include <fstream>
using namespace std;

//caso 1
int main()
{
    float c=300.0;
    float A0=0.01;
    float l=1.0;
    float tmax=0.1;
    
    
    //Condicion de establidad
    float dx=0.005;
    float dt=(dx*0.5)/c**2;
    
    //Arreglos
    float pasado[];
    float presente[];
    float futuro[];
    
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
    
    //paso 1
    float t=0.0;
    presente=(1/2)*((((c**2*dt**2)/dx**2)*(pasado+pasado-2*pasado))+(2*pasado));
    
    //for en el tiempo
    for (int t=0;t<=30;t++)
    {
        //for en el espacio
        for (int e=0; e<=l;e++)
        {     
            futuro[e]=(((c**2*dt**2)/dx**2)*(presente[e+1]+presente[e-1]-2*presente[e]))-pasado[e]+2*presente[e];
            contador++; 
        }
        //for en el espacio para cambiar las variables
        for (int es=0;es<=l;es++)
        {
            pasado[e]=presente[e];
            presente[e]=futuro[e];
        }
    }
    return 0;
}