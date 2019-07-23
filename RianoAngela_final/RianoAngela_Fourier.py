# Tiene una serie de tiempo, donde los datos de tiempo estan almacenados en un arreglo t y los datos de amplitud en un arreglo amp.
#1) Usando los paquetes de scipy de la transformada de Fourier, haga un FILTRO de la senial que elimine las frecuencias mayores a 1000Hz en las senial original.
#2) Haga una grafica de la senial original y la senial filtarada y guardela SIN MOSTRARLA en filtro.pdf
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

n = 1280 # number of point in the whole interval
f = 200.0 #  frequency in Hz
dt = 1 / (f * 320 ) #320 samples per unit frequency
t = np.linspace( 0, (n-1)*dt, n)
amp = np.cos(2 * np.pi * f * t) - 0.4 * np.sin(2 * np.pi * (2*f) * t ) + np.random.random(n)

# SU FILTRO
Transformada_fourier=np.fft.fft(amp)

frecuencia=np.fft.fftfreq(n,dt/n)

corte=1000
for i in range(N):
    if (abs(frecuencia[i])>corte):
        Transformada_fourier[i]=0
        
inversa=np.fft.ifft(Transformada_fourier)       

# SU GRAFICA
plt.plot(t,amp,label="Señal original")
plt.plot(t,inversa, label="Señal filtrada")
plt.legend()
plt.savefig("filtro.png")


# Puede usar los siguientes paquetes:
#from scipy.fftpack import fft, fftfreq, ifft