#include <iostream>
#include <vector>
using namespace std;
#include <chrono>
const int SIZE_VECTOR = 5000000;
using namespace std::chrono;

vector<int> vectorcillo(SIZE_VECTOR);

long sumaelementos(int n){
    if (n == 0) return 0;
    return n + sumaelementos(n - 1);
}

void inicializar(int start, int end) {
    for (int i = start; i < end; ++i) {
        vectorcillo[i] = sumaelementos(i % 100);
    }
}

void imprimir(int start, int end){
    for (int i = start; i < end; ++i) {
        long a = vectorcillo[i];
        vectorcillo[i] = a;
    }
}

long sumar (int start, int end){
    long suma = 0;
    for (int i = start; i < end; ++i) {
        suma += vectorcillo[i];
    }
    return suma;
}

int main(){
    auto start = high_resolution_clock::now();
    inicializar(0, SIZE_VECTOR);
    imprimir(0, SIZE_VECTOR);
    cout << "La suma de los elementos del vector es: " << sumar(0, SIZE_VECTOR) << endl;

    auto end = high_resolution_clock::now();
    duration<float, std::milli> duration_ms =end - start;
    cout << "Tiempo de ejecución: " << duration_ms.count() << " ms" << endl;
    
    return 0;
}