"""
Ejemplo de datos entre procesos
"""

import multiprocessing

lst = []

def llenar_lista(n):
    global lst
    lst = [i for i in range(n)]
    print(f"Lista llenada {lst}")
    print("Lista llenada")

print("Lista antes de llenar: ", lst)
p1 = multiprocessing.Process(target=llenar_lista, args=(100,))
p1.start()
p1.join()
print("Lista después de llenar: ", lst)