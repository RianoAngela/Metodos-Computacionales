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
    for (int i=0; i<n;i++)
    {
        x[i] = x[i-1] + h;
        y[i] = y[i-1] + h * funcion(x[i-1],y[i-1]);
    }   
    
    cout << x;
    cout << y;
    return 0;
}

float funcion(float x, float y)
{
    return -y;
}
