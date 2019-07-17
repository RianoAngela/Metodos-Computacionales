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
datosR=np.random.uniform(0,30.5,1000)
cuadrado=np.linspace(0,30.5,1000)

plt.scatter(cuadrado,datosR)
plt.title("datos dentro del cuadrado")
plt.savefig("cuadrado.pdf")


r=23
datosC=np.random.uniform(-23,23,1000)
areaC=np.pi*(r**2)

circulo=[]
for i in range(1000):
    if (datosC[i]<=areaC):
        circulo.append(datosC[i])
        
plt.scatter(circulo,datosC)
plt.title("datos dentro del circulo")
plt.savefig("circulo.pdf")

#Ejercicio 4

npasos=100
N=1000
sigma=0.25
pasosx=np.empty((0))
pasosy=np.empty((0))

pasosx=np.append(pasosx, np.random.random())
pasosy=np.append(pasosy, np.random.random())

for i in range(N):
    for j in range(npasos):
        pasosx = np.random.normal(pasosx[i][j], sigma)
        pasosy = np.random.normal(pasosy[i][j], sigma)
        
        if (pasosx[i][j] >30.5):
            pasosx[i][j]=0+pasosx[i][j]
        if (pasosy[i][j]>30.5):
            pasosy[i][j]=0+pasosy[i][j]
        
        
        