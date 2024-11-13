"""
Ejemplo de servidor de procesos con Queue
Carlos Andres Delgado Saavedra
18 de septiembre de 2024
"""
import multiprocessing

def proceso1(queue):
    while not queue.empty():
        print(queue.get())
    queue.put([i for i in range(20)])
    print("Proceso 1 terminado")

def proceso2(queue):
    while not queue.empty():
        print(queue.get())
    queue.put([f"cositæ feæ {i+1}" for i in range(10)])
    print("Proceso 2 terminado")

if __name__ == "__main__":
    queue1 = multiprocessing.Queue()
    queue2 = multiprocessing.Queue()
    queue1.put("Mensaje hacia el proceso 1")
    queue1.put([1,2,3,4])
    queue2.put("Mensaje hacia el proceso 2")
    queue2.put([5,6,7,8])
    p1 = multiprocessing.Process(target=proceso1, args=(queue1,))
    p2 = multiprocessing.Process(target=proceso2, args=(queue2,))
    p1.start()
    p2.start()
    p1.join()
    p2.join()
    while not queue1.empty():
        print(queue1.get())


    while not queue2.empty():
        print(queue2.get())
