#include <stdio.h>
#include <omp.h>

void addme(int n, double a[], double b[], double c[]) {
    int i;

    // Paralelizamos el bucle con OpenMP
    #pragma omp parallel for
    for (i = 0; i < n; i++) {
        a[i] = b[i] + c[i];
    }
}

int main() {
    double a[10];
    a[0] = 1;

    // Llamada a la función addme
    addme(9, a + 1, a, a);

    // Imprimir el resultado
    for (int i = 0; i < 10; i++) {
        printf("a[%d] = %.0f\n", i, a[i]);
    }

    return 0;
}
