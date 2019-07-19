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
    int pasos=100;
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
        double auxiliar= (-G*M)/pow(R,3);
        x_presente[i] = (vx_presente[i-1]*dt)+x_presente[i-1];
        y_presente[i] = (vy_presente[i-1]*dt)+y_presente[i-1];   
        vx_presente[i] = ((auxiliar*x_presente[i-1])*dt)+vx_presente[i-1];
        vy_presente[i] = ((auxiliar*y_presente[i-1])*dt)+vy_presente[i-1];
        t=t+dt;
        
    }
    outfile.close();
}

void leap_frog(double dt,string nombre)
{
    double G = 6.674*pow(10,-29);
    double M = 1.989*pow(10,30);
    int pasos=100;
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
    double auxiliar1= (-G*M)/pow(R1,3);
    x_presente[1] = (vx_presente[0]*dt)+x_presente[0];
    y_presente[1] = (vy_presente[0]*dt)+y_presente[0];   
    vx_presente[1] = ((auxiliar1*x_presente[0])*dt)+vx_presente[0];
    vy_presente[1] = ((auxiliar1*y_presente[0])*dt)+vy_presente[0];
    
    ofstream outfile;
    outfile.open(nombre);
    
    double t=0.0;
    for (int i=2;i<=20;i++)
    {
        outfile<< x_presente[i-2]<<" "<<y_presente[i-2]<<" "<<vx_presente[i-2]<<" "<<vy_presente[i-2]<<endl;
        double R = sqrt(pow(x_presente[i-1],2)+pow(y_presente[i-1],2));
        double auxiliar= (-G*M)/pow(R,3);
        x_presente[i] = (vx_presente[i-1]*(2*dt))+x_presente[i-1];
        y_presente[i] = (vy_presente[i-1]*(2*dt))+y_presente[i-1];
        vx_presente[i] = ((auxiliar*x_presente[i-1])*(2*dt))+vx_presente[i-1];
        vy_presente[i] = ((auxiliar*y_presente[i-1])*(2*dt))+vy_presente[i-1];
        t=t+dt;
        
    }
    outfile.close();
}

void rk(float dt, string nombre)
{
    double G = 6.674*pow(10,-29);
    double M = 1.989*pow(10,30);
    
    double x_presente, y_presente, vx_presente, vy_presente;
    double x_futuro, y_futuro, vx_futuro, vy_futuro;
    double k0_x, k0_y, k0_vx, k0_vy;
    double k1_x, k1_y, k1_vx, k1_vy;
    double k2_x, k2_y, k2_vx, k2_vy;
    double k3_x, k3_y, k3_vx, k3_vy;
    double t_presente, t_futuro;
    
    //condiciones iniciales
    x_presente = 0.1163;
    y_presente = 0.9772;
    vx_presente = -6.35;
    vy_presente = 0.606;
    
    ofstream outfile;
    outfile.open(nombre);
    double t=0.0;
    for (int i=1; i<=20;i++)
    {
        x_futuro = vx_presente*dt + x_presente;
        y_futuro = vy_presente*dt + y_presente;
        vx_futuro = (((-G*M)/pow(R,3))*x_presente)*dt+vx_presente;
        vy_futuro = (((-G*M)/pow(R,3))*y_presente)*dt+vy_presente;
        
        outfile << x_futuro << " " << y_futuro << " " << vx_futuro << " " << vy_futuro << endl;
        
        k0_x = ;
        k0_y = ;
        k0_vx = ;
        k0_vy = ;
        
        t_futuro = t_presente + dt*0.5;
        x_futuro = x_presente + 0.5 * dt * k0_x;
        y_futuro = y_presente + 0.5 * dt * k0_y;
        vx_futuro = vx_presente + 0.5 * dt * k0_vx;
        vy_futuro = vy_presente + 0.5 * dt * k0_vy;
        k1_x = ;
        k1_y = ;
        k1_vx = ;
        k1_vy = ;
        
        t_futuro = t_presente + dt*0.5;
        x_futuro = x_presente + 0.5 * dt * k1_x;
        y_futuro = y_presente + 0.5 * dt * k1_y;
        vx_futuro = vx_presente + 0.5 * dt * k1_vx;
        vy_futuro = vy_presente + 0.5 * dt * k1_vy;
        k2_x = ;
        k2_y = ;
        k2_vx = ;
        k2_vy = ;
        
        t_futuro = t_presente + dt;
        x_futuro = x_presente + dt * k2_x;
        y_futuro = y_presente + dt * k2_y;
        vx_futuro = vx_presente + dt * k1_vx;
        vy_futuro = vy_presente + dt * k1_vy;
        k3_x = ;
        k3_y = ;
        k3_vx = ;
        k3_vy = ;
        
        k_x  = k0_x/6.0 + k1_x/3.0 + k2_x/3.0 + k3_x/6.0;
        k_y  = k0_y/6.0 + k1_y/3.0 + k2_y/3.0 + k3_y/6.0;
        k_vx = k0_vx/6.0 + k1_vx/3.0 + k2_vx/3.0 + k3_vx/6.0;
        k_vy = k0_vy/6.0 + k1_vy/3.0 + k2_vy/3.0 + k3_vy/6.0;
        
        x_futuro = x_presente + dt * k_x;
        y_futuro = y_presente + dt * k_y;
        vx_futuro = vx_presente + dt * k_vx;
        vy_futuro = vy_presente + dt * k_vy;
        t = t + dt;
    }
    outfile.close();
}