/*
    Ejemplo de calculo de la distancia entre dos puntos en Rn en vectores grandes
    utilizando threads
*/

#include <iostream>
#include <vector>
#include <thread>
#include <cmath>
#include <chrono>

using namespace std;

const int N = 1000000;

void llenar(vector<double>& v) {
    for (int i = 0; i < N; i++) {
        v[i] = rand() % 100;
    }
}

void diferencia_cuadrados(const vector<double>& v1, const vector<double>& v2, vector<double>& res, int inicio, int fin) {
    for (int i = inicio; i < fin; i++) {
        res[i] = (v1[i] - v2[i]) * (v1[i] - v2[i]);
    }
}

void suma(const vector<double>& v, double& res, int inicio, int fin) {
    for (int i = inicio; i < fin; i++) {
        res += v[i];
    }
}

int main() {
    vector<double> v1(N), v2(N), res(N);
    double suma_res = 0;
    llenar(v1);
    llenar(v2);

    //Un hilo
    auto inicio = chrono::high_resolution_clock::now();
    diferencia_cuadrados(v1, v2, res, 0, N);
    suma(res, suma_res, 0, N);
    double distancia = sqrt(suma_res);
    auto fin = chrono::high_resolution_clock::now();
    printf("Distancia: %f\n", distancia);
    printf("Tiempo: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fin - inicio).count());


    //Dos hilos
    inicio = chrono::high_resolution_clock::now();
    thread t1(diferencia_cuadrados, ref(v1), ref(v2), ref(res), 0, N / 2);
    thread t2(diferencia_cuadrados, ref(v1), ref(v2), ref(res), N / 2, N);
    t1.join();
    t2.join();
    double suma_p1 = 0, suma_p2 = 0;
    thread t3(suma, ref(res), ref(suma_p1), 0, N / 2);
    thread t4(suma, ref(res), ref(suma_p2), N / 2, N);
    t3.join();
    t4.join();
    suma_res = suma_p1 + suma_p2;
    distancia = sqrt(suma_res);
    fin = chrono::high_resolution_clock::now();
    printf("Distancia: %f\n", distancia);
    printf("Tiempo: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fin - inicio).count());


    //Cuatro hilos
    inicio = chrono::high_resolution_clock::now();
    thread t5(diferencia_cuadrados, ref(v1), ref(v2), ref(res), 0, N / 4);
    thread t6(diferencia_cuadrados, ref(v1), ref(v2), ref(res), N / 4, N / 2);
    thread t7(diferencia_cuadrados, ref(v1), ref(v2), ref(res), N / 2, 3 * N / 4);
    thread t8(diferencia_cuadrados, ref(v1), ref(v2), ref(res), 3 * N / 4, N);
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    double suma_p3 = 0, suma_p4 = 0, suma_p5 = 0, suma_p6 = 0;
    thread t9(suma, ref(res), ref(suma_p3), 0, N / 4);
    thread t10(suma, ref(res), ref(suma_p4), N / 4, N / 2);
    thread t11(suma, ref(res), ref(suma_p5), N / 2, 3 * N / 4);
    thread t12(suma, ref(res), ref(suma_p6), 3 * N / 4, N);
    t9.join();
    t10.join();
    t11.join();
    t12.join();
    suma_res = suma_p3 + suma_p4 + suma_p5 + suma_p6;
    distancia = sqrt(suma_res);
    fin = chrono::high_resolution_clock::now();
    printf("Distancia: %f\n", distancia);
    printf("Tiempo: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fin - inicio).count());
}