import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq

#almacenamiento de las fotos
caraseria=plt.imread("cara_02_grisesMF.png")
carafeliz=plt.imread("cara_03_grisesMF.png")

print(np.shape(caraseria))
print(np.shape(carafeliz))


#Transformada de fourier
tfcaraseria=np.fft.fft2(caraseria).real
tfcarafeliz=np.fft.fft2(carafeliz).real

plt.imshow(tfcaraseria)
plt.imshow(tfcarafeliz)
plt.savefig("transformadafourier.png")

#Frecuencias
frecuenciaCS=np.fft.fftfreq()
frecuenciaCF=np.fft.fftfreq()


#Transformada inversa de fourier 
cara2 = np.fft.ifft2(frecuenciaCS).real
cara3 = np.fft.ifft2(frecuenciaCF).real

fig = plt.figure(2, figsize=(7,7))
plt.imshow(cara2)
plt.imshow(cara3)
plt.savefig("hibrida.png")
