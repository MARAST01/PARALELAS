import time
import numpy as np



def llenar():
    for i in range(n):
        lst[i] = arr[i]

def suma_cuadrados(arg):
    suma = 0
    for i in range(n):
        suma += arg[i]**2
    return suma

if __name__ == "__main__":
    n = 1000000
    arr = np.random.randint(0, 100, n)
    lst = [0]*n
    llenar()

    t0 = time.perf_counter(), time.process_time()
    print(suma_cuadrados(lst))
    t1 = time.perf_counter(), time.process_time()
    print(f"Tiempo operación listas {t1[0]-t0[0]}")
    print(t0,t1)

    t0 = time.perf_counter(), time.process_time()
    print(np.apply_along_axis(lambda x: x**2, 0, arr).sum())
    t1 = time.perf_counter(), time.process_time()
    print(f"Tiempo operación numpy {t1[0]-t0[0]}")
