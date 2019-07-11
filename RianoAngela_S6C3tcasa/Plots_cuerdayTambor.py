import numpy as np
import matplotlib.pyplot as plt

cuerda=np.genfromtxt("datos.dat",delimiter="/t")
plt.plot(cuerda)
plt.title("Caso 1")
plt.xlabel("Posición m")
plt.ylabel("Amplitud m")