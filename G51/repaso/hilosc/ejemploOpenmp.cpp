/*
    Ejemplo de calculo de la distancia entre dos puntos en Rn en vectores grandes
    utilizando openmp
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <omp.h>

using namespace std;

const int N = 1000000;

void llenar(vector<double>& v) {
    for (int i = 0; i < N; i++) {
        v[i] = rand() % 100;
    }
}

void diferencia_cuadrados(const vector<double>& v1, const vector<double>& v2, vector<double>& res) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        res[i] = (v1[i] - v2[i]) * (v1[i] - v2[i]);
    }
}

double suma(const vector<double>& v) {
    double res = 0;
    #pragma omp parallel for reduction(+:res)
    for (int i = 0; i < N; i++) {
        res += v[i];
    }
    return res;
}

int main() {
    vector<double> v1(N), v2(N), res(N);
    double suma_res = 0;
    llenar(v1);
    llenar(v2);

    auto inicio = chrono::high_resolution_clock::now();
    diferencia_cuadrados(v1, v2, res);
    suma_res = suma(res);
    double distancia = sqrt(suma_res);
    auto fin = chrono::high_resolution_clock::now();
    printf("Distancia: %f\n", distancia);
    printf("Tiempo con openmp: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fin - inicio).count());
}