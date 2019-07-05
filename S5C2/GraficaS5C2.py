import numpy as np
import matplotlib.pyplot as plt 

euler=np.genfromtxt("S5C2/euler.cpp",delimiter="/t")
rk4=np.genfromtxt("S5C2/RK4orden.cpp",delimiter="/t")

plt.plot(euler)
plt.title("Euler")
plt.xlabel("x")
plt.ylabel("y(x)")

plt.plot(rk4)
plt.title("Runge Kutta 4to orden")
plt.xlabel("x")
plt.ylabel("y(x)")