"""
Programa para calcular una lista de factoriales desde 0! hasta n!
Carlos Andres Delgado Saavedra
18 de septiembre de 2024
"""

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)
    
def lista_factoriales(n):
    return [factorial(i) for i in range(n+1)]

if __name__ == "__main__":
    print(lista_factoriales(26))