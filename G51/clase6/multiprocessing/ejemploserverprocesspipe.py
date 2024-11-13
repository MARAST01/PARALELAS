"""
Ejemplo de server process con pipes y queues
Carlos Andres Delgado Saavedra
18 de septiembre de 2024
"""

import multiprocessing

def proceso1(pipe):
    while pipe.poll():
        print(pipe.recv())
    pipe.send([i for i in range(100)])
    print("Proceso 1 terminado")

def proceso2(pipe):
    print(pipe.recv())
    pipe.send([f"cosita {i+1}" for i in range(10)])
    print("Proceso 2 terminado")

if __name__ == "__main__":
    pipe1, pipe2 = multiprocessing.Pipe()
    pipe1.send("Mensaje hacia el proceso 1")
    pipe2.send("Mensaje hacia el proceso 2")
    p1 = multiprocessing.Process(target=proceso1, args=(pipe1,))
    p2 = multiprocessing.Process(target=proceso2, args=(pipe2,))
    p1.start()
    p2.start()
    p1.join()
    p2.join()

    while pipe1.poll():
        print(pipe1.recv())

    while pipe2.poll():
        print(pipe2.recv())

    pipe1.close()
    pipe2.close()