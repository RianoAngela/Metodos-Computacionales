import numpy as np
import matplotlib.pyplot as plt

canal = np.genfromtxt("Canal_ionico.txt")

def estimacion_bayesiana(centro):
    N=len(canal)
    x_viejo=np.array([])
    y_viejo=np.array([])
    
    x_viejo=np.append(x_viejo,np.random.uniform())
    y_viejo=np.append(y_viejo,np.random.uniform())
    
    for i in range(N)
        x_nuevo=np.array([])
        y_nuevo=np.array([])
        
        x_nuevo=np.append(x_nuevo,np.random.normal())
        y_nuevo=np.append(y_nuevo,np.random.normal())
        
        alpha=(x_nuevo+y_nuevo)/(x_viejo+y_viejo)
        if (alpha>=1):
            x_nuevo=np.append(x_nuevo[i],centro)
            y_nuevo=np.append(y_nuevo[i],centro)
   
        else:
            beta=np.random.uniform(0,1)
            if (beta<alpha):
                x_nuevo=np.append(x_nuevo[i],centro)
                y_nuevo=np.append(y_nuevo[i],centro)

            else:
                x_nuevo=np.append(x_nuevo[i],x_viejo)
                y_nuevo=np.append(y_nuevo[i],x_viejo)
                
    return x_nuevo,y_nuevo
    
plt.figure()
plt.scatter(canal[:,1],canal[:,0])
plt.plot(estimacion_bayesiana(0.01))
plt.savefig("canal.png")