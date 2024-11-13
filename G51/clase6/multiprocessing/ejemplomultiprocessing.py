"""
Ejemplo multiprocessing en Python
Carlos Andres Delgado Saavedra
18 de septiembre de 2024
"""
import multiprocessing
import os

def proceso1():
    a = [i for i in range(1000000)]
    print("Proceso 1 " + str(os.getpid()))
    print("Proceso 1 terminado")
    return a

def proceso2():
    a = [i for i in range(10000)]
    print("Proceso 2 " + str(os.getpid()))
    print("Proceso 2 terminado")
    return a

def proceso3():
    a = [i for i in range(100)]
    print("Proceso 3 " + str(os.getpid()))
    print("Proceso 3 terminado")
    return a

if __name__ == "__main__":
    p1 = multiprocessing.Process(target=proceso1)
    p2 = multiprocessing.Process(target=proceso2)
    p3 = multiprocessing.Process(target=proceso3)
    p1.start()
    p2.start()
    p3.start()
    p1.join()
    p2.join()
    p3.join()
    #Imprimir valores de la lista
    print("Fin del programa")