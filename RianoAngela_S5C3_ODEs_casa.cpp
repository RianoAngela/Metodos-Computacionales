#include <iostream>
#include <fstream>
using namespace std;

float Vx(float,float)

int main()
{
    float m=2.0;
    float k=300.0;
    float x0=0.1;
    float pEquilibrio=0.0;
    
    float x[];
    float v[];
    
    v[0]=0.0;
    if (v==0)
    {
        float h=0.01;
        int n=200;
        for (int i=0; i<=n;i++)
        {
            x[i] = x[i] + h;
            v[i] = v[i] + h * Vx(x[i],v[i]);
        }   
    }
    
    
    return 0;   
}

float Vx(float x, float t)
{
    float dt=0.01;
    return (x*(t+(dt/2)-x*(t-(dt/2)))/dt;
}