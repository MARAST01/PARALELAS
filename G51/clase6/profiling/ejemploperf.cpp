/**
 * Programa en C++ para calcular el producto punto entre dos vectores
 * Carlos A Delgado S
 * 18 de Septiembre de 2024
 */

#include <iostream>
#include <vector>

using namespace std;

vector <int> v1;
vector <int> v2;

void llenarVectores(int n){
    for(int i = 0; i < n; i++){
        v1.push_back(i);
        v2.push_back(i);
    }
}

int productoPunto(int n){
    int resultado = 0;
    for(int i = 0; i < n; i++){
        resultado += v1[i] * v2[i];
    }
    return resultado;
}


int main(){
    int n = 1000000;
    llenarVectores(n);
    cout << "El producto punto es: " << productoPunto(n) << endl;
    return 0;
}