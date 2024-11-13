#include <iostream>
#include <omp.h>
#define MAX_VECTOR 30 // Limité el tamaño para evitar tiempos largos
// Función recursiva de Fibonacci que prefieres
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int vector[MAX_VECTOR];
    // Inicialización paralelizada
    #pragma omp parallel for
    for (int i = 0; i < MAX_VECTOR; i++) {
        vector[i] = i;
    }
    // Cálculo de Fibonacci paralelizado
    #pragma omp parallel for
    for (int i = 0; i < MAX_VECTOR; i++) {
        vector[i] = fibonacci(i);
    }
    // Impresión (no paralelizada para evitar salidas desordenadas)
    for (int i = 0; i < MAX_VECTOR; i++) {
        printf("-%d-", vector[i]);
    }
    return 0;
}
