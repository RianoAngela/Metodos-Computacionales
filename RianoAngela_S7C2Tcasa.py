#Ejercicio 1 

import numpy as np
import matplotlib.pylab as plt

def mifun(x):
    x_0 = 3.0
    a = 0.01
    return np.exp(-(x**2))/((x-x_0)**2 + a**2)

x=np.linspace(-4,4,100)
plt.plot(mifun(x))

fun_normalizada=mifun(x)*np.trapz(mifun(x))
plt.plot(fun_normalizada)

def metropolis(n_iteraciones,sigma):
    camino=np.array([])
    xviejo=np.random.uniform(-4,4)
    camino=np.append(camino,xviejo)
    for i in range(n_iteraciones):
        xnuevo=np.random.normal(camino[i],sigma)
        alpha=mifun(xnuevo)/mifun(camino[i])
        if (alpha>=1):
            paso=np.append(camino,xnuevo)
        
        else:
            betha=np.random.uniform(0,1)
            if (betha<=alpha):
                camino=np.append(camino,xnuevo)
            
            else:
                camino=np.append(camino,camino[i])
    return camino

caso1=metropolis(100000,5)
plt.plot(x,fun_normalizada)
plt.hist(caso1, bins=1000,density=True)
plt.savefig("histograma_"+str("5")+"_"+str("100000")+".pdf")

caso2=metropolis(100000,0.2)
plt.plot(x,fun_normalizada)
plt.hist(caso2, bins=1000,density=True)
plt.savefig("histograma_"+str("0.2")+"_"+str("100000")+".pdf")

caso3=metropolis(100000,0.01)
plt.plot(x,fun_normalizada)
plt.hist(caso3, bins=1000,density=True)
plt.savefig("histograma_"+str("0.01")+"_"+str("100000")+".pdf")

caso4=metropolis(1000,0.1)
plt.plot(x,fun_normalizada)
plt.hist(caso4, bins=1000,density=True)
plt.savefig("histograma_"+str("0.1")+"_"+str("1000")+".pdf")

caso5=metropolis(100000,0.1)
plt.plot(x,fun_normalizada)
plt.hist(caso5, bins=1000,density=True)
plt.savefig("histograma_"+str("0.1")+"_"+str("100000")+".pdf")