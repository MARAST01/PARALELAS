/*
    Ejemplo de calculo de la distancia entre dos puntos en Rn en vectores grandes
    utilizando tbb
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <tbb/tbb.h>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
#include <tbb/parallel_reduce.h>

using namespace std;

const int N = 1000000;

void llenar(vector<double>& v) {
    for (int i = 0; i < N; i++) {
        v[i] = rand() % 100;
    }
}

void diferencia_cuadrados(const vector<double>& v1, const vector<double>& v2, vector<double>& res) {
    tbb::parallel_for(tbb::blocked_range<int>(0, N), [&](const tbb::blocked_range<int>& r) {
        for (int i = r.begin(); i < r.end(); i++) {
            res[i] = (v1[i] - v2[i]) * (v1[i] - v2[i]);
        }
    });
}

double suma(const vector<double>& v) {
    double res = 0;
    res = tbb::parallel_reduce(tbb::blocked_range<int>(0, N), 0.0, [&](const tbb::blocked_range<int>& r, double local_res) {
        for (int i = r.begin(); i < r.end(); i++) {
            local_res += v[i];
        }
        return local_res;
    }, [&](double x, double y) {
        return x + y;
    });
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
    printf("Tiempo con tbb: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fin - inicio).count());
}