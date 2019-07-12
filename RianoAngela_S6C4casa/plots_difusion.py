import numpy as np
import matplotlib.pyplot as plt

datos=np.genfromtxt("datos.dat",delimiter="/n")

plt.imshow(datos)