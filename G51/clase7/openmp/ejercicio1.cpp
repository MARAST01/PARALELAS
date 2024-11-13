/**
 * Ejercicio sencillo openmp
 * Carlos A Delgado
 * 25-09-2024
 */

#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    omp_set_num_threads(4); //Establecer el numero de hilos
    #pragma omp parallel
    {
        printf("Hola mundo %d %d\n", omp_get_thread_num(), omp_get_num_threads());
    }
}