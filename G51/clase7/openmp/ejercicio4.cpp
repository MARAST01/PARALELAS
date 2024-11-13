/**
 * EJemplo scheduling en openmp
 * Carlos A Delgado
 * 25-09-2024
 */

#include <iostream>
#include <omp.h>

using namespace std;

void inicialize_static(int *matriz, int filas, int columnas) {
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < filas; i++) {
        printf("Hilo %d Fila %d Valor filas %d\n", omp_get_thread_num(), i, filas);

        for (int j = 0; j < columnas; j++) {
            matriz[i * columnas + j] = 1;
        }
    }
}

void inicialize_dynamic(int *matriz, int filas, int columnas) {
    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < filas; i++) {
        printf("Hilo %d Fila %d Valor filas %d\n", omp_get_thread_num(), i, filas);

        for (int j = 0; j < columnas; j++) {
            matriz[i * columnas + j] = 1;
        }
    }
}

void inicialize_guided(int *matriz, int filas, int columnas) {
    #pragma omp parallel for schedule(guided)
    for (int i = 0; i < filas; i++) {
        printf("Hilo %d Fila %d Valor filas %d\n", omp_get_thread_num(), i, filas);

        for (int j = 0; j < columnas; j++) {
            matriz[i * columnas + j] = 1;
        }
    }
}

void inicialize_auto(int *matriz, int filas, int columnas) {
    #pragma omp parallel for schedule(auto)
    for (int i = 0; i < filas; i++) {
        printf("Hilo %d Fila %d Valor filas %d\n", omp_get_thread_num(), i, filas);

        for (int j = 0; j < columnas; j++) {
            matriz[i * columnas + j] = 1;
        }
    }
}

void inicialize_runtime(int *matriz, int filas, int columnas) {
    #pragma omp parallel for schedule(runtime)
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

    printf("Static\n");
    inicialize_static(matriz, filas, columnas);
    printf("Dynamic\n");
    inicialize_dynamic(matriz, filas, columnas);
    printf("Guided\n");
    inicialize_guided(matriz, filas, columnas);
    printf("Auto\n");
    inicialize_auto(matriz, filas, columnas);
    printf("Runtime\n");
    inicialize_runtime(matriz, filas, columnas);

    
}