"""
Calcular la distancia entre dos puntos en un plano cartesiano de n dimensiones utilizando hilos.
"""
import threading
import random
import numpy as np
import time

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
    d = 0
    #for i in range(inicio, fin):
    #    d += c[i]
    d = np.sum(c[inicio:fin])
    res.append(d)

if __name__ == "__main__":
    a = np.zeros(n)
    b = np.zeros(n)
    c = np.zeros(n)

    llenar_arreglo(a, b)

    #1 hilo

    inicio = time.time()

    diferencia_cuadrados(a, b, c, 0, n)
    res = []
    suma_cuadrados(c, res, 0, n)

    print(res)

    fin = time.time()
    print(np.sqrt(np.sum(res)))
    print(f"Tiempo de ejecución 1 hilo: {fin - inicio}")

    #2 hilos
    inicio = time.time()
    t1 = threading.Thread(target=diferencia_cuadrados, args=(a, b, c, 0, n//2))
    t2 = threading.Thread(target=diferencia_cuadrados, args=(a, b, c, n//2, n))

    t1.start()
    t2.start()

    t1.join()
    t2.join()

    res = []
    t3 = threading.Thread(target=suma_cuadrados, args=(c, res, 0, n//2))
    t4 = threading.Thread(target=suma_cuadrados, args=(c,res, n//2, n))


    t3.start()
    t4.start()

    t3.join()
    t4.join()

    print(res)

    fin = time.time()
    print(np.sqrt(np.sum(res)))
    print(f"Tiempo de ejecución 2 hilos: {fin - inicio}")

    #4 hilos
    inicio = time.time()
    t1 = threading.Thread(target=diferencia_cuadrados, args=(a, b, c, 0, n//4))
    t2 = threading.Thread(target=diferencia_cuadrados, args=(a, b, c, n//4, n//2))
    t3 = threading.Thread(target=diferencia_cuadrados, args=(a, b, c, n//2, 3*n//4))
    t4 = threading.Thread(target=diferencia_cuadrados, args=(a, b, c, 3*n//4, n))

    t1.start()
    t2.start()
    t3.start()
    t4.start()

    t1.join()
    t2.join()
    t3.join()
    t4.join()

    res = []
    t5 = threading.Thread(target=suma_cuadrados, args=(c, res, 0, n//4))
    t6 = threading.Thread(target=suma_cuadrados, args=(c, res, n//4, n//2))
    t7 = threading.Thread(target=suma_cuadrados, args=(c, res, n//2, 3*n//4))
    t8 = threading.Thread(target=suma_cuadrados, args=(c, res, 3*n//4, n))

    t5.start()
    t6.start()
    t7.start()
    t8.start()

    t5.join()
    t6.join()
    t7.join()
    t8.join()

    print(res)

    fin = time.time()
    print(np.sqrt(np.sum(res)))
    print(f"Tiempo de ejecución 4 hilos: {fin - inicio}")



