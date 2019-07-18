import numpy as np
import matplotlib.pyplot as plt

#Graficas para dt=0.005
euler1=np.genfromtxt("euler_0.005.dat")
leap1=np.genfromtxt("leap_0.005.dat")
rk1=np.genfromtxt("rk_0.005.dat")

plt.plot(euler1[:,0],euler1[:,1])
plt.plot(leap1[:,0],leap1[:,1])
plt.plot(rk1[:,0],rk1[:,1])

plt.plot(euler1[:,2],euler1[:,3])
plt.plot(leap1[:,2],leap1[:,3])
plt.plot(rk1[:,2],rk1[:,3])


#graficas para dt=0.001
euler1=np.genfromtxt("euler_0.001.dat")
leap1=np.genfromtxt("leap_0.001.dat")
rk1=np.genfromtxt("rk_0.001.dat")

plt.plot(euler2[:,0],euler2[:,1])
plt.plot(leap2[:,0],leap2[:,1])
plt.plot(rk[:,0],rk2[:,1])

plt.plot(euler2[:,2],euler2[:,3])
plt.plot(leap2[:,2],leap2[:,3])
plt.plot(rk2[:,2],rk2[:,3])

#graficas para dt=0.0001
euler3=np.genfromtxt("euler_0.005.dat")
leap3=np.genfromtxt("leap_0.005.dat")
rk3=np.genfromtxt("rk_0.005.dat")

plt.plot(euler3[:,0],euler3[:,1])
plt.plot(leap3[:,0],leap3[:,1])
plt.plot(rk3[:,0],rk3[:,1])

plt.plot(euler3[:,2],euler3[:,3])
plt.plot(leap3[:,2],leap3[:,3])
plt.plot(rk3[:,2],rk3[:,3])
