/**
 * Prueba con omp critical
 * Carlos A Delgado
 * 25-09-2024
 */

#include <iostream>
#include <omp.h>

using namespace std;

void incrementa(int &a) {
    #pragma omp critical
    {
        a++;
    }
}

int main() {
    int a = 0;
    #pragma omp parallel
    {
        incrementa(a);
    }
    cout << a << endl;
}