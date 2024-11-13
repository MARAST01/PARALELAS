"""
Ejemplo de memoria compartida entre procesos (variable tipo lista)
Carlos Andres Delgado Saavedra
18 de septiembre de 2024
"""
import multiprocessing

arr = multiprocessing.Array('i', range(10))

def modificar(i, arr):
    arr[i] = arr[i] * 10

if __name__ == "__main__":
    print("Arreglo original: ", arr[:])
    p1 = multiprocessing.Process(target=modificar, args=(2, arr))
    p2 = multiprocessing.Process(target=modificar, args=(5, arr))
    p1.start()
    p2.start()
    p1.join()
    p2.join()
    print("Arreglo modificado: ", arr[:])
    