#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void euler(double dt, string nombre);
void leap_frog(double dt, string nombre);
void rk(double dt, string nombre);

int main ()
{
    euler(0.005, "euler_0.005.dat");
    euler(0.001, "euler_0.001.dat");
    euler(0.0001, "euler_0.0001.dat");
    leap_frog(0.005, "leap_0.005.dat");
    leap_frog(0.001, "leap_0.001.dat");
    leap_frog(0.0001, "leap_0.0001.dat");
    rk(0.005, "rk_0.005.dat");
    rk(0.001, "rk_0.001.dat");
    rk(0.0001, "rk_0.0001.dat");
    
    return 0;
}


void euler(double dt, string nombre)
{
    double G = 6.674*pow(10,-29);
    double M = 1.989*pow(10,30);
    int pasos=20;
    double x_presente[pasos];
    double y_presente[pasos];
    double vx_presente[pasos];
    double vy_presente[pasos];
    
    //condiciones iniciales
    x_presente[0] = 0.1163;
    y_presente[0] = 0.9772;
    vx_presente[0] = -6.35;
    vy_presente[0] = 0.606;
    
    ofstream outfile;
    outfile.open(nombre);
   
    double t=0.0;
    for (int i=1;i<=20;i++)
    {
        outfile<< x_presente[i-1]<<" "<<y_presente[i-1]<<" "<<vx_presente[i-1]<<" "<<vy_presente[i-1]<<endl;
        double R = sqrt(pow(x_presente[i-1],2)+pow(y_presente[i-1],2));
        x_presente[i] = (vx_presente[i-1]*dt)+x_presente[i-1];
        y_presente[i] = (vy_presente[i-1]*dt)+y_presente[i-1];   
        vx_presente[i] = ((((-G*M)/pow(R,3))*x_presente[i-1])*dt)+vx_presente[i-1];
        vy_presente[i] = ((((-G*M)/pow(R,3))*y_presente[i-1])*dt)+vy_presente[i-1];
        t=t+dt;
        
    }
    outfile.close();
}

void leap_frog(double dt,string nombre)
{
    double G = 6.674*pow(10,-29);
    double M = 1.989*pow(10,30);
    int pasos=22;
    double x_presente[pasos];
    double y_presente[pasos];
    double vx_presente[pasos];
    double vy_presente[pasos];
    
    //condiciones iniciales
    x_presente[0] = 0.1163;
    y_presente[0] = 0.9772;
    vx_presente[0] = -6.35;
    vy_presente[0] = 0.606;
    
    //paso 1
    double R1 = sqrt(pow(x_presente[0],2)+pow(y_presente[0],2));
    x_presente[1] = (vx_presente[0]*dt)+x_presente[0];
    y_presente[1] = (vy_presente[0]*dt)+y_presente[0];   
    vx_presente[1] = ((((-G*M)/pow(R1,3))*x_presente[0])*dt)+vx_presente[0];
    vy_presente[1] = ((((-G*M)/pow(R1,3))*y_presente[0])*dt)+vx_presente[0];
    
    ofstream outfile;
    outfile.open(nombre);
    
    double t=0.0;
    for (int i=2;i<=22;i++)
    {
        outfile<< x_presente[i-2]<<" "<<y_presente[i-2]<<" "<<vx_presente[i-2]<<" "<<vy_presente[i-2]<<endl;
        double R = sqrt(pow(x_presente[i-1],2)+pow(y_presente[i-1],2));
        x_presente[i] = (vx_presente[i-1]*(2*dt))+x_presente[i-2];
        y_presente[i] = (vy_presente[i-1]*(2*dt))+y_presente[i-2];
        vx_presente[i] = ((((-G*M)/pow(R,3))*x_presente[i-1])*(2*dt))+vx_presente[i-2];
        vy_presente[i] = ((((-G*M)/pow(R,3))*y_presente[i-1])*(2*dt))+vy_presente[i-2];
        t=t+dt;
        
    }
    outfile.close();
}

void rk(float dt, string nombre)
{
    ofstream outfile;
    outfile.open(nombre);
    
    outfile.close()
}




