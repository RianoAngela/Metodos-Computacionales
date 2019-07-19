#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void euler(double dt, string nombre);
void leap_frog(double dt, string nombre);
void runge_kutta(double dt, string nombre);

int main ()
{
    euler(0.01, "euler_0.01.dat");
    euler(0.001, "euler_0.001.dat");
    euler(0.0001, "euler_0.0001.dat");
    leap_frog(0.01, "leap_0.01.dat");
    leap_frog(0.001, "leap_0.001.dat");
    leap_frog(0.0001, "leap_0.0001.dat");
    runge_kutta(0.01, "rk_0.01.dat");
    runge_kutta(0.001, "rk_0.001.dat");
    runge_kutta(0.0001, "rk_0.0001.dat");
    return 0;
}


void euler(double dt, string nombre)
{
    double G = 6.674*pow(10,-29);
    double M = 1.989*pow(10,30);
    double m = 5.972*pow(10,24);
    double pi = 2*acos(0.0);
    int pasos = 100;
    double x_presente[pasos],y_presente[pasos],vx_presente[pasos],vy_presente[pasos];
    double energia[pasos], momento[pasos];
    
    ofstream outfile;
    outfile.open(nombre);
    
    //condiciones iniciales
    x_presente[0] = 0.1163;
    y_presente[0] = 0.9772;
    vx_presente[0] = -6.35;
    vy_presente[0] = 0.606;
    energia[0]=((1.0/2.0)*m*(pow(vx_presente[0],2)+pow(vy_presente[0],2)))- ((G*M*m)/sqrt(pow(x_presente[0],2)+pow (y_presente[0],2)));
    momento[0] = m*2*pi*sqrt(pow(x_presente[0],2)+pow(y_presente[0],2));  
    outfile<< x_presente[0]<<" "<<y_presente[0]<<" "<<vx_presente[0]<<" "<<vy_presente[0]<<" "<<energia[0]<<" "<<momento[0]<<endl;
    
    double t=0.0;
    for (int i=1;i<=20;i++)
    {
        double R = sqrt(pow(x_presente[i-1],2)+pow(y_presente[i-1],2));
        double auxiliar= (-G*M)/pow(R,3);
        x_presente[i] = (vx_presente[i-1]*dt)+x_presente[i-1];
        y_presente[i] = (vy_presente[i-1]*dt)+y_presente[i-1];   
        vx_presente[i] = ((auxiliar*x_presente[i-1])*dt)+vx_presente[i-1];
        vy_presente[i] = ((auxiliar*y_presente[i-1])*dt)+vy_presente[i-1];
        energia[i] = ((1.0/2.0)*m*(pow(vx_presente[i-1],2)+pow(vy_presente[i-1],2)))- ((G*M*m)/R);
        momento[i] = m*2*pi*R;         
        outfile<< x_presente[i]<<" "<<y_presente[i]<<" "<<vx_presente[i]<<" "<<vy_presente[i]<<" "<<energia[i]<<" "<<momento[i]<<endl;
        t=t+dt;
    }
    outfile.close();
}


void leap_frog(double dt,string nombre)
{
    double G = 6.674*pow(10,-29);
    double M = 1.989*pow(10,30);
    double m = 5.972*pow(10,24);
    double pi = 2*acos(0.0);
    int pasos=100;
    double x_presente[pasos],y_presente[pasos],vx_presente[pasos],vy_presente[pasos];
    double energia[pasos],momento[pasos];
    
    ofstream outfile;
    outfile.open(nombre);
    
    //condiciones iniciales
    x_presente[0] = 0.1163;
    y_presente[0] = 0.9772;
    vx_presente[0] = -6.35;
    vy_presente[0] = 0.606;
    energia[0]=((1.0/2.0)*m*(pow(vx_presente[0],2)+pow(vy_presente[0],2)))- ((G*M*m)/sqrt(pow(x_presente[0],2)+pow (y_presente[0],2)));
    momento[0] = m*2*pi*sqrt(pow(x_presente[0],2)+pow(y_presente[0],2));  
    outfile<< x_presente[0]<<" "<<y_presente[0]<<" "<<vx_presente[0]<<" "<<vy_presente[0]<<" "<<energia[0]<<" "<<momento[0]<<endl;
    
    //paso 1
    double R1 = sqrt(pow(x_presente[0],2)+pow(y_presente[0],2));
    double auxiliar1= (-G*M)/pow(R1,3);
    x_presente[1] = (vx_presente[0]*dt)+x_presente[0];
    y_presente[1] = (vy_presente[0]*dt)+y_presente[0];   
    vx_presente[1] = ((auxiliar1*x_presente[0])*dt)+vx_presente[0];
    vy_presente[1] = ((auxiliar1*y_presente[0])*dt)+vy_presente[0];
    energia[1]=((1.0/2.0)*m*(pow(vx_presente[0],2)+pow(vy_presente[0],2)))- ((G*M*m)/R1);
    momento[1] = m*2*pi*R1;  
    outfile<< x_presente[1]<<" "<<y_presente[1]<<" "<<vx_presente[1]<<" "<<vy_presente[1]<<" "<<energia[1]<<" "<<momento[1]<<endl;
    
    double t=0.0;
    for (int i=2;i<=20;i++)
    {
        double R = sqrt(pow(x_presente[i-1],2)+pow(y_presente[i-1],2));
        double auxiliar= (-G*M)/pow(R,3);
        x_presente[i] = (vx_presente[i-1]*(2*dt))+x_presente[i-1];
        y_presente[i] = (vy_presente[i-1]*(2*dt))+y_presente[i-1];
        vx_presente[i] = ((auxiliar*x_presente[i-1])*(2*dt))+vx_presente[i-1];
        vy_presente[i] = ((auxiliar*y_presente[i-1])*(2*dt))+vy_presente[i-1];
        energia[i] = ((1.0/2.0)*m*(pow(vx_presente[i-1],2)+pow(vy_presente[i-1],2)))- ((G*M*m)/R);
        momento[i] = m*2*pi*R; 
        outfile<< x_presente[i]<<" "<<y_presente[i]<<" "<<vx_presente[i]<<" "<<vy_presente[i]<<" "<<energia[i]<<" "<<momento[i]<<endl;
        t=t+dt; 
    }
    outfile.close();
}


void runge_kutta(double dt, string nombre)
{
    double G = 6.674*pow(10,-29);
    double M = 1.989*pow(10,30);
    double m = 5.972*pow(10,24);
    double pi = 2*acos(0.0);
    double t, t_futuro;
    double x_presente, y_presente, vx_presente, vy_presente;
    double x_futuro, y_futuro, vx_futuro, vy_futuro;
    double k0_x, k0_y, k0_vx, k0_vy;
    double k1_x, k1_y, k1_vx, k1_vy;
    double k2_x, k2_y, k2_vx, k2_vy;
    double k3_x, k3_y, k3_vx, k3_vy;
    double k_x, k_y, k_vx, k_vy;
    double dvx, dvy, dvx1, dvy1;
    double momento, energia;
  
    ofstream outfile;
    outfile.open(nombre);
    //condiciones iniciales
    x_presente = 0.1163;
    y_presente = 0.9772;
    vx_presente = -6.35;
    vy_presente = 0.606;
   
    t=0.0;
    for (int i=0; i<=20;i++)
    {
        double R = sqrt(pow(x_presente,2)+pow(y_presente,2));
        double auxiliar = (-G*M)/pow(R,3);
        energia = ((1.0/2.0)*m*(pow(vx_presente,2)+pow(vy_presente,2)))-((G*M*m)/R);
        momento = m*2*pi*R;  
        dvx = ((auxiliar*y_presente)*dt)+vy_presente;
        dvy = ((auxiliar*x_presente)*dt)+vx_presente;
        outfile<<x_futuro<<" "<<y_futuro<<" "<<vx_futuro<<" "<<vy_futuro<<" "<<energia<<" "<<momento<<endl;
        
        k0_x = vx_presente;
        k0_y = vy_presente;
        k0_vx = dvx;
        k0_vy = dvy;
        
        x_futuro = x_presente + ((0.5 * dt) * k0_x);
        y_futuro = y_presente + ((0.5 * dt) * k0_y);
        vx_futuro = vx_presente + ((0.5 * dt) * k0_vx);
        vy_futuro = vy_presente + ((0.5 * dt) * k0_vy);
        
        dvx1 = (((-G*M)/pow(R,3))*y_futuro)*dt+vy_futuro;
        dvy1 = (((-G*M)/pow(R,3))*x_futuro)*dt+vx_futuro;
        k1_x = vx_futuro;
        k1_y = vy_futuro;
        k1_vx = dvx;
        k1_vy = dvy;
        
        x_futuro = x_presente + ((0.5 * dt) * k1_x);
        y_futuro = y_presente + ((0.5 * dt) * k1_y);
        vx_futuro = vx_presente + ((0.5 * dt) * k1_vx);
        vy_futuro = vy_presente + ((0.5 * dt) * k1_vy);
        k2_x = vx_futuro;
        k2_y = vy_futuro;
        k2_vx = dvx1;
        k2_vy = dvy1;
       
        x_futuro = x_presente + (dt * k2_x);
        y_futuro = y_presente + (dt * k2_y);
        vx_futuro = vx_presente + (dt * k2_vx);
        vy_futuro = vy_presente + (dt * k2_vy);
        k3_x = vx_futuro;
        k3_y = vy_futuro;
        k3_vx = dvx1;
        k3_vy = dvy1;
        
        k_x  = (k0_x/6.0) + (k1_x/3.0) + (k2_x/3.0) + (k3_x/6.0);
        k_y  = (k0_y/6.0) + (k1_y/3.0) + (k2_y/3.0) + (k3_y/6.0);
        k_vx = (k0_vx/6.0) + (k1_vx/3.0) + (k2_vx/3.0) + (k3_vx/6.0);
        k_vy = (k0_vy/6.0) + (k1_vy/3.0) + (k2_vy/3.0) + (k3_vy/6.0);
        
        x_futuro = x_presente + (dt * k_x);
        y_futuro = y_presente + (dt * k_y);
        vx_futuro = vx_presente + (dt * k_vx);
        vy_futuro = vy_presente + (dt * k_vy);
        t = t + dt;
        
        x_presente = x_futuro;
        y_presente = y_futuro;
        vx_presente = vx_futuro;
        vy_presente = vy_futuro;
    }
    outfile.close();
}