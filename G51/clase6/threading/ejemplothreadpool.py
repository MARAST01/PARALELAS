"""
Ejemplo thread pool
Carlos Andres Delgado Saavedra
18 de septiembre de 2024
"""
import concurrent.futures

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
    
    result = [T(i) for i in range(n+1)]
    print(f"Ejecución de T({n})")
    return result

if __name__ == "__main__":
    with concurrent.futures.ThreadPoolExecutor() as executor:
        f1 = executor.submit(lista_T, 25)
        f2 = executor.submit(lista_T, 20)
        f3 = executor.submit(lista_T, 15)
        print(f1.result())
        print(f2.result())
        print(f3.result())
        #Imprimir valores de la lista