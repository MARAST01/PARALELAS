/**
 * Ejemplo de for en openmp
 * Carlos A Delgado
 * 25-09-2024
 */

#include <iostream>
#include <omp.h>

using namespace std;

void inicialize(int *matriz, int filas, int columnas) {
    #pragma omp parallel for shared(filas, columnas, matriz)
    for (int i = 0; i < filas; i++) {

        printf("Hilo %d Fila %d Valor filas %d\n", omp_get_thread_num(), i, filas);

        for (int j = 0; j < columnas; j++) {
            matriz[i * columnas + j] = 1;
        }
    }
}

int main() {
    int filas = 30;
    int columnas = 5;
    int *matriz = new int[filas * columnas];

    inicialize(matriz, filas, columnas);

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i * columnas + j] << " ";
        }
        cout << endl;
    }
    
}