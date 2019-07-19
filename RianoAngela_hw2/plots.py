import numpy as np
import matplotlib.pyplot as plt

#importacion de los datos 
euler1=np.genfromtxt("euler_0.005.dat")
leap1=np.genfromtxt("leap_0.005.dat")
rk1=np.genfromtxt("rk_0.005.dat")

euler2=np.genfromtxt("euler_0.001.dat")
leap2=np.genfromtxt("leap_0.001.dat")
rk2=np.genfromtxt("rk_0.001.dat")

euler3=np.genfromtxt("euler_0.001.dat")
leap3=np.genfromtxt("leap_0.001.dat")
rk3=np.genfromtxt("rk_0.001.dat")

#Graficas de x vs y
fig, (ax1, ax2, ax3, ax4, ax5, ax6, ax7, ax8, ax9) = plt.subplots(9,3)
fig.suptitle("Graficas x vs y", fontsize=20)

ax1.set_title("dt=0.005 euler")
ax1.plot(euler1[:,0],euler1[:,1])
ax2.set_title("dt=0.005 leap frog")
ax2.plot(euler1[:,0],euler1[:,1])
ax3.set_title("dt=0.005 runge kutta")
ax3.plot(rk1[:,0],rk1[:,1])
ax4.set_title("dt=0.001 euler")
ax4.plot(euler2[:,0],euler2[:,1])
ax5.set_title("dt=0.001 leap frog")
ax5.plot(leap2[:,0],leap2[:,1])
ax6.set_title("dt=0.001 runge kutta")
ax6.plot(rk2[:,0],rk2[:,1])
ax7.set_title("dt=0.0001 euler")
ax7.plot(euler3[:,0],euler3[:,1])
ax8.set_title("dt=0.0001 leap frog")
ax8.plot(leap3[:,0],leap3[:,1])
ax9.set_title("dt=0.0001 runge kutta")
ax9.plot(rk3[:,0],rk3[:,1])

plt.tight_layout()
plt.subplots_adjust(top=0.6)
plt.savefig("XY_met_dt.pdf")

#Graficas de vx vs vy 
fig1, (a1, a2, a3, a4, a5, a6, a7, a8, a9) = plt.subplots(9,3)
fig1.suptitle("Velocidad en x vs velocidad en y", fontsize=20)

a1.set_title("dt=0.005 euler")
a1.plot(euler1[:,2],euler1[:,3])
a2.set_title("dt=0.005 leap frog")
a2.plot(euler1[:,2],euler1[:,3])
a3.set_title("dt=0.005 runge kutta")
a3.plot(rk1[:,2],rk1[:,3])
a4.set_title("dt=0.001 euler")
a4.plot(euler2[:,2],euler2[:,3])
a5.set_title("dt=0.001 leap frog")
a5.plot(leap2[:,2],leap2[:,3])
a6.set_title("dt=0.001 runge kutta")
a6.plot(rk2[:,2],rk2[:,3])
a7.set_title("dt=0.0001 euler")
a7.plot(euler3[:,2],euler3[:,3])
a8.set_title("dt=0.0001 leap frog")
a8.plot(leap3[:,2],leap3[:,3])
a9.set_title("dt=0.0001 runge kutta")
a9.plot(rk3[:,2],rk3[:,3])

plt.tight_layout()
plt.subplots_adjust(top=0.6)
plt.savefig("VxVy_met_dt.pdf")

#Graficas del momento angular 


#Graficas de la energia total del sistema
