from timeit import timeit
import numpy as np

def llenar(n, lst, arr):
    for i in range(n):
        lst[i] = arr[i]

def suma_cuadrados(arg):
    suma = 0
    for i in range(n):
        suma += arg[i]**2
    return suma

def suma_numpy():
    return np.apply_along_axis(lambda x: x**2, 0, arr).sum()

if __name__ == "__main__":

    n = 10000000
    arr = np.random.randint(0, 100, n)
    lst = [0]*n
    llenar(n,lst,arr)
    it = 100
    print(timeit("suma_cuadrados(lst)", globals=globals(), number=it)/it)
    print(timeit("suma_numpy()", globals=globals(), number=it)/it)