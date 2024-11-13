"""
Calcular la distancia entre dos puntos en un plano cartesiano de n dimensiones utilizando proceso.
"""

import multiprocessing
import random
import numpy as np
import time
from ctypes import c_double

n = 1000000

def llenar_arreglo(a, b):
    for i in range(n):
        a[i] = random.randint(0, 100)
        b[i] = random.randint(0, 100)

def diferencia_cuadrados(a,b,c, inicio, fin):
    #for i in range(inicio, fin):
    #    c[i] = (a[i] - b[i]) ** 2
    c[inicio:fin] = np.power((a[inicio:fin] - b[inicio:fin]),2)

def suma_cuadrados(c, res, inicio, fin):
    #for i in range(inicio, fin):
    #    d += c[i]
    res.value = np.sum(c[inicio:fin])
    

if __name__ == "__main__":
    a = np.zeros(n)
    b = np.zeros(n)

    llenar_arreglo(a, b)

    #2 procesos
    inicio = time.time()
    res = multiprocessing.Value(c_double, 0)
    res2 = multiprocessing.Value(c_double, 0)

    carray = multiprocessing.Array('d', n)

    p1 = multiprocessing.Process(target=diferencia_cuadrados, args=(a, b, carray, 0, n//2))
    p2 = multiprocessing.Process(target=diferencia_cuadrados, args=(a, b, carray, n//2, n))
    p1.start()
    p2.start()
    p1.join()
    p2.join()
    
    print(f"c[:10] = {carray[:10]}")

    p3 = multiprocessing.Process(target=suma_cuadrados, args=(carray, res, 0, n//2))
    p4 = multiprocessing.Process(target=suma_cuadrados, args=(carray, res2, n//2, n))
    p3.start()
    p4.start()

    p3.join()
    p4.join()

    print(res.value)
    print(res2.value)
    print(np.sqrt(np.sum(res.value) + np.sum(res2.value)))
    fin = time.time()
    print(f"Tiempo de ejecución 2 procesos: {fin - inicio}")