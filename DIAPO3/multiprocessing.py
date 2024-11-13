# Importando el módulo multiprocessing
import multiprocessing

def print_cube(num):
	print("Cube: {}".format(num * num * num))

def print_square(num):
	print("Square: {}".format(num * num))

if __name__ == "__main__":
	# Creando procesos
	p1 = multiprocessing.Process(target=print_square, args=(10,))
	p2 = multiprocessing.Process(target=print_cube, args=(10,))

	# Iniciando procesos
	p1.start()
	p2.start()

	# Esperando a que los procesos terminen
	p1.join()
	p2.join()

	print("Done!")