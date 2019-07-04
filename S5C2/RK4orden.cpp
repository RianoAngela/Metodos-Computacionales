#include <iostream>
using namespace std;

float funcion(float,float);

int main()
{
    float h=0.001;
    float x1=0.0;
    float x2=2.0;
    int n=((x2-x1)/h);
    float x[n];
    float y[n];

    x[0]=x1;
    y[0]=0;
    float aux=0.5*h;
    for (int i=0; i<n;i++)
    {
        float k1= h*funcion(x[i-1],y[i-1]);
        float k2= h*funcion(x[i-1]+aux,y[i-1]+0.5*k1);
        float k3= h*funcion(x[i-1]+aux,y[i-1]+0.5*k2);
        float k4= h*funcion(x[i-1]+h,y[i-1]*k3);
            
        float promedio= 1/6*(k1+(2*k2)+(2*k3)+k4);
        
        x[i] = x[i-1] + h;
        y[i] = y[i-1] + promedio;
    }
    
    cout << x;
    cout << y;

    return 0;
}

float funcion(float x, float y)
{
    return -y;
}