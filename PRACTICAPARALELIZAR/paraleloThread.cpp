#include <iostream>
#include <vector>
using namespace std;
#include <chrono> // Para medir el tiempo de ejecución
const int SIZE_VECTOR = 5000000; // Tamaño del vector
using namespace std::chrono;
#include <thread> // Para la paralelización con hilos

// Declaración de un vector global con tamaño predefinido
vector<int> vectorcillo(SIZE_VECTOR);

// Función recursiva que suma los números desde n hasta 1
long sumaelementos(int n) {
    if (n == 0) return 0; // Caso base: si n es 0, retorna 0
    return n + sumaelementos(n - 1); // Llamada recursiva sumando n
}

// Función para inicializar una parte del vector con el resultado de sumaelementos
void inicializar(int start, int end) {
    for (int i = start; i < end; ++i) {
        // Asigna al vector el resultado de sumaelementos con el residuo de i/100
        vectorcillo[i] = sumaelementos(i % 100);
    }
}

// Función para "imprimir" (en este caso solo reasigna valores dentro del vector)
void imprimir(int start, int end) {
    for (int i = start; i < end; ++i) {
        long a = vectorcillo[i];
        vectorcillo[i] = a; // Simple reasignación (no cambia nada)
    }
}

// Función para sumar todos los elementos de una sección del vector
long sumar(int start, int end) {
    long suma = 0;
    for (int i = start; i < end; ++i) {
        suma += vectorcillo[i]; // Acumula la suma
    }
    return suma;
}

// Función que utiliza dos hilos para inicializar, imprimir y sumar
void process_two_threads(int start, int end) {
    // Inicialización en paralelo usando dos hilos
    thread t11(inicializar, start, end/2);
    thread t12(inicializar, end/2, end);
    t11.join();
    t12.join();

    // Impresión en paralelo usando dos hilos
    thread t21(imprimir, start, end/2);
    thread t22(imprimir, end/2, end);
    t21.join();
    t22.join();

    // Suma en paralelo usando dos hilos
    long resultA = 0, resultB = 0;
    thread t31([&resultA, start, end]() { resultA = sumar(start, end/2); });
    thread t32([&resultB, start, end]() { resultB = sumar(end/2, end); });
    t31.join();
    t32.join();

    // Imprime el resultado total de la suma
    cout << "La suma de los elementos del vector es: " << resultA + resultB << endl;
}

// Función que utiliza cuatro hilos para inicializar, imprimir y sumar
void process_four_threads(int start, int end) {
    // Inicialización en paralelo usando cuatro hilos
    thread t11(inicializar, start, end/4);
    thread t12(inicializar, end/4, end/2);
    thread t13(inicializar, end/2, 3*end/4);
    thread t14(inicializar, 3*end/4, end);
    t11.join();
    t12.join();
    t13.join();
    t14.join();

    // Impresión en paralelo usando cuatro hilos
    thread t21(imprimir, start, end/4);
    thread t22(imprimir, end/4, end/2);
    thread t23(imprimir, end/2, 3*end/4);
    thread t24(imprimir, 3*end/4, end);
    t21.join();
    t22.join();
    t23.join();
    t24.join();

    // Suma en paralelo usando cuatro hilos
    long resultA = 0, resultB = 0, resultC = 0, resultD = 0;
    thread t31([&resultA, start, end]() { resultA = sumar(start, end/4); });
    thread t32([&resultB, start, end]() { resultB = sumar(end/4, end/2); });
    thread t33([&resultC, start, end]() { resultC = sumar(end/2, 3*end/4); });
    thread t34([&resultD, start, end]() { resultD = sumar(3*end/4, end); });
    t31.join();
    t32.join();
    t33.join();
    t34.join();
}

// Función que utiliza ocho hilos para inicializar, imprimir y sumar
void process_eight_threads(int start, int end) {
    // Inicialización en paralelo usando ocho hilos
    thread t11(inicializar, start, end/8);
    thread t12(inicializar, end/8, end/4);
    thread t13(inicializar, end/4, 3*end/8);
    thread t14(inicializar, 3*end/8, end/2);
    thread t15(inicializar, end/2, 5*end/8);
    thread t16(inicializar, 5*end/8, 3*end/4);
    thread t17(inicializar, 3*end/4, 7*end/8);
    thread t18(inicializar, 7*end/8, end);
    t11.join();
    t12.join();
    t13.join();
    t14.join();
    t15.join();
    t16.join();
    t17.join();
    t18.join();

    // Impresión en paralelo usando ocho hilos
    thread t21(imprimir, start, end/8);
    thread t22(imprimir, end/8, end/4);
    thread t23(imprimir, end/4, 3*end/8);
    thread t24(imprimir, 3*end/8, end/2);
    thread t25(imprimir, end/2, 5*end/8);
    thread t26(imprimir, 5*end/8, 3*end/4);
    thread t27(imprimir, 3*end/4, 7*end/8);
    thread t28(imprimir, 7*end/8, end);
    t21.join();
    t22.join();
    t23.join();
    t24.join();
    t25.join();
    t26.join();
    t27.join();
    t28.join();

    // Suma en paralelo usando ocho hilos
    long resultA = 0, resultB = 0, resultC = 0, resultD = 0, resultE = 0, resultF = 0, resultG = 0, resultH = 0;
    thread t31([&resultA, start, end]() { resultA = sumar(start, end/8); });
    thread t32([&resultB, start, end]() { resultB = sumar(end/8, end/4); });
    thread t33([&resultC, start, end]() { resultC = sumar(end/4, 3*end/8); });
    thread t34([&resultD, start, end]() { resultD = sumar(3*end/8, end/2); });
    thread t35([&resultE, start, end]() { resultE = sumar(end/2, 5*end/8); });
    thread t36([&resultF, start, end]() { resultF = sumar(5*end/8, 3*end/4); });
    thread t37([&resultG, start, end]() { resultG = sumar(3*end/4, 7*end/8); });
    thread t38([&resultH, start, end]() { resultH = sumar(7*end/8, end); });
    t31.join();
    t32.join();
    t33.join();
    t34.join();
    t35.join();
    t36.join();
    t37.join();
    t38.join();
}

// Función principal
int main() {
    auto start = high_resolution_clock::now();
    process_two_threads(0, SIZE_VECTOR);
    auto end = high_resolution_clock::now();
    duration<float, std::milli> duration_ms = end - start;
    cout << "Tiempo dos hilos de ejecución: " << duration_ms.count() << " ms" << endl;

    start = high_resolution_clock::now();
    process_four_threads(0, SIZE_VECTOR);
    end = high_resolution_clock::now();
    duration_ms = end - start;
    cout << "Tiempo cuatro hilos de ejecución: " << duration_ms.count() << " ms" << endl;

    start = high_resolution_clock::now();
    process_eight_threads(0, SIZE_VECTOR);
    end = high_resolution_clock::now();
    duration_ms = end - start;
    cout << "Tiempo ocho hilos de ejecución: " << duration_ms.count() << " ms" << endl;

    return 0;
}
