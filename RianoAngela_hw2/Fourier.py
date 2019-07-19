import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq

#almacenamiento de las fotos
caraseria=plt.imread("cara_02_grisesMF.png")
carafeliz=plt.imread("cara_03_grisesMF.png")

#Transformada de Fourier
cara2_ft = np.fft.fft2(caraseria)
cara3_ft = np.fft.fft2(carafeliz)

plt.figure(figsize=(8,8))
plt.subplot(2,2,1)
plt.imshow(cara2_ft.real, vmin=0, vmax=2)
plt.title("FFT cara 2")
plt.subplot(2,2,2)
plt.imshow(cara3_ft.real, vmin=0, vmax=2)
plt.title("FFT cara 3")

plt.savefig("FFtIm.pdf")

#Frecuencia 
cara2_fr = np.fft.fftshift(cara2_ft)
cara3_fr = np.fft.fftshift(cara3_ft)

plt.figure(figsize=(8,8))
plt.subplot(2,2,1)
plt.imshow(cara2_fr.real, vmin=0,vmax=2)
plt.title("Frecuencia cara 2")
plt.subplot(2,2,2)
plt.imshow(cara3_fr.real,vmin=0, vmax=2)
plt.title("Frecuencia cara 3")

for i in range(254):
    for j in range (170):
        if (abs(cara2_fr[i,j])>=250):
            cara2_fr[i,j]=0
        
for k in range(254):
    for l in range (170):
        if (abs(cara3_fr[k,l])<=250):
            cara3_fr[k,l]=0

#Transformada Inversa 
img2= np.fft.ifft2(cara2_fr)
img3= np.fft.ifft2(cara3_fr)

plt.figure(figsize=(6,6))
plt.subplot(2,2,1)
plt.imshow(cara2_fr.real, vmin=0, vmax=0.0001)
plt.title("Frecuencia filtrada cara 2")
plt.subplot(2,2,2)
plt.imshow(cara3_fr.real, vmin=0, vmax=0.0001)
plt.title("Frecuencia filtrada cara 3")
plt.subplot(2,2,3)
plt.imshow(img2.real, vmin=0, vmax=0.1)
plt.title("iFF cara 2")
plt.subplot(2,2,4)
plt.imshow(img3.real, vmin=0, vmax=0.999)
plt.title("iFF cara 3")
plt.savefig("ImProces.pdf")


#Imagen hibrida
final1=img2+img3
plt.figure(figsize=(6,5))
plt.subplot(2,2,1)
plt.imshow(final1.real, plt.cm.gray,vmin=0,vmax=1)
plt.title("Fotografia hibrida")
plt.savefig("ImHybrid.pdf")


