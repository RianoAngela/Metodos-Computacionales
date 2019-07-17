import numpy as np
import matplotlib.pyplot as plt

#Ejercicio 1
nu=np.random.uniform(-10,10,1000)

plt.hist(nu, label="datos uniformes")
plt.title("Valores uniformes")
plt.ylabel("")
plt.xlabel("")
plt.legend()
plt.savefig("uniforme.pdf")


centro=17
sigma=5
ng=np.random.normal(centro,sigma,1000)

plt.hist(ng, label="datos normales")
plt.title("Valores normales")
plt.legend()
plt.savefig("gausiana.pdf")

#Ejercicio 2
datosR=np.random.uniform(0,30.5,100)
cuadrado=np.linspace(0,30.5,100)

plt.scatter(cuadrado,datosR)
plt.title("datos dentro del cuadrado")
plt.savefig("cuadrado.pdf")


r=23
datosC=np.random.uniform(-23,23,100)
areaC=np.pi*(r**2)

circulo=[]
for i in range(100):
    if (datosC[i]<=areaC):
        circulo.append(datosC[i])
        
plt.scatter(circulo,datosC)
plt.title("datos dentro del circulo")
plt.savefig("circulo.pdf")

#Ejercicio 3
npasos=100
N=1000
sigma=0.25
pasosx=np.random.normal(0,sigma,N)
pasosy=np.random.normal(0,sigma,N)
camino=[pasosx,pasosy]
#print (np.shape(camino))

for i in range(N):
    for j in range(npasos):
        
        
