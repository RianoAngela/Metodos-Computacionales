import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq

#almacenamiento de las fotos
caraseria=plt.imread("cara_02_grisesMF.png")
carafeliz=plt.imread("cara_03_grisesMF.png")

print(np.shape(caraseria))
print(np.shape(carafeliz))


plt.imshow(caraseria)
plt.savefig("cara2Original.png")

plt.imshow(carafeliz)
plt.savefig("cara3Original.png")

##Para obtener la cara nueva 2 y 3 se baso en el proceso realizado en computo ciencias uniandes
#proceso para cara3
t = np.linspace(-6, 6, 10)
foto = np.exp(-0.00025*t**2)
foto = foto / np.trapz(foto)

aumento = foto[:, np.newaxis] * foto[np.newaxis, :]
aumento_ft = np.fft.fft2(aumento, s=carafeliz.shape[:2], axes=(0, 1))
cara3_ft = np.fft.fft2(carafeliz)
cara3_ft = aumento_ft[:,:] * cara3_ft
cara3 = np.fft.ifft2(img3_ft).real

plt.imshow(cara3)
plt.savefig("nuevacara3.png")

#proceso para cara2
foto1 = np.exp(-15*t**2)
foto1 = foto1 / np.trapz(foto1)

aumento1 = foto1[:, np.newaxis] * foto1[np.newaxis, :]
aumento1_ft = np.fft.fft2(aumento1, s=caraseria.shape[:2], axes=(0, 1))
cara2_ft = np.fft.fft2(caraseria)
cara2_ft = aumento1_ft[:,:] * cara2_ft
cara2 = np.fft.ifft2(img2_ft).real

plt.imshow(cara2)
plt.savefig("nuevacara2.png")

#foto hibrida 
hibrida=cara2+cara3

plt.imshow(hibrida)
plt.savefig("hibrida.png")
