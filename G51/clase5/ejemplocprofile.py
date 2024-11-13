from cProfile import Profile
from pstats import Stats, SortKey
import numpy as np
from functools import lru_cache

def llenar(n, lst, arr):
    for i in range(n):
        lst[i] = arr[i]

def suma_cuadrados(arg):
    suma = 0
    for i in range(len(arg)):
        suma += arg[i]**2
    return suma

def suma_numpy():
    return np.apply_along_axis(lambda x: x**2, 0, arr).sum()

def fib(n):
    return n if n < 2 else fib(n-1) + fib(n-2)

@lru_cache(maxsize=None)
def fibmem(n):
    return n if n < 2 else fibmem(n-1) + fibmem(n-2)

if __name__ == "__main__":
    n = 10000000
    arr = np.random.randint(0, 100, n)
    lst = [0]*n
    llenar(n, lst, arr)
    with Profile() as prof:
        print(suma_cuadrados(lst))
        print(
            Stats(prof)
            .strip_dirs()
            .sort_stats(SortKey.TIME)
            .print_stats()
        )

    with Profile() as prof:
        print(suma_numpy())
        print(
            Stats(prof)
            .strip_dirs()
            .sort_stats(SortKey.TIME)
            .print_stats()
       )
    
    with Profile() as prof:
        print(fib(30))
        print(
            Stats(prof)
            .strip_dirs()
            .sort_stats(SortKey.TIME)
            .print_stats()
        )

    with Profile() as prof:
        print(fibmem(30))
        print(
            Stats(prof)
            .strip_dirs()
            .sort_stats(SortKey.TIME)
            .print_stats()
        )
        