all : canal.png filtro.png 
    
canal.png : RianoAngela_canal_ionico.py
    python RianoAngela_canal_ionico.py
    
filtro.png : RianoAngela_Fourier.py
    python RianoAngela_Fourier.py