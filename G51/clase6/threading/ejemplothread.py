"""
Ejemplo de hilos
Carlos Andres Delgado Saavedra
18 de septiembre de 2024
"""
import threading

def T(n):
    if n == 0:
        return 3
    elif n == 1:
        return 5
    elif n == 2:
        return 7
    else:
        return T(n-1) + T(n-2) + T(n-3)
    
def lista_T(n):
    print([T(i) for i in range(n+1)])

if __name__ == "__main__":
    h1 = threading.Thread(target=lista_T, args=(25,))
    h2 = threading.Thread(target=lista_T, args=(20,))
    h1.start()
    h2.start()
    h1.join()
    h2.join()
    #Imprimir valores de la lista

