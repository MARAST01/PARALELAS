/**
 * Programa de ejemplo de acceso a la memoria cache
 * Carlos A Delgado
 * 25-09-2024
 */

#include <iostream>
#include <chrono>

using namespace std;

int main() {
    int filas = 3000000;
    int columnas = 200;
    int *matriz = new int[filas * columnas];

    //Acceso secuencial
    //Visitamos filas y luego columnas
    /*
    Filas 10
    Columnas 5
    0 ... 49
    0 1 2 3 4
    5 6 7 8 9
    10 11 12 13 14
    15 16 17 18 19
    ...
    45 46 47 48 49
    */
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i * columnas + j] = 0;
        }
    }
    //Duración en milisegundos
    auto end = chrono::high_resolution_clock::now();
    cout << "Duración secuencial: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;

    //Acceso salteado
    //Visitamos columnas y luego filas
    //Filas = 10, Col = 5
    /**
     * 0 5 10 15 20 30 35 40 45
     * 1 6 11 16 21 31 36 41 46
     * 2 7 12 17 22 32 37 42 47
     * ..
     * 4 9 14 19 24 34 39 44 49
     */
    auto start2 = chrono::high_resolution_clock::now();
    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < filas; j++) {
            matriz[j * columnas + i] = 0;
        }
    }
    //Duración en milisegundos
    auto end2 = std::chrono::high_resolution_clock::now();
    cout << "Duración salteada: " << chrono::duration_cast<chrono::milliseconds>(end2 - start2).count() << " ms" << endl;

}