#include <iostream>
#include <vector>
using namespace std;
#include <chrono>
const int SIZE_VECTOR = 5000000;
using namespace std::chrono;
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
#include <tbb/parallel_reduce.h>

vector<int> vectorcillo(SIZE_VECTOR);

long sumaelementos(int n){
    if (n == 0) return 0;
    return n + sumaelementos(n - 1);
}

void process() {
    tbb::parallel_for(tbb::blocked_range<int>(0, SIZE_VECTOR), [&](tbb::blocked_range<int> r) {
        for (int i = r.begin(); i < r.end(); ++i) {
            vectorcillo[i] = sumaelementos(i % 100);
        }
    });

    tbb::parallel_for(tbb::blocked_range<int>(0, SIZE_VECTOR), [&](tbb::blocked_range<int> r) {
        for (int i = r.begin(); i < r.end(); ++i) {
            long a = vectorcillo[i];
            vectorcillo[i] = a;
        }
    });

    
    
    long suma = tbb::parallel_reduce(tbb::blocked_range<int>(0, SIZE_VECTOR), 0, [&](tbb::blocked_range<int> r, long local_sum) -> long {
        for (int i = r.begin(); i < r.end(); ++i) {
            local_sum += vectorcillo[i];
        }
        return local_sum;
    }, 
    [](long x, long y) -> long {
        return x + y;
    });
    cout << "La suma de los elementos del vector es: " << suma << endl;
}


int main(){
    auto start = high_resolution_clock::now();
    process();

    auto end = high_resolution_clock::now();
    duration<float, std::milli> duration_ms =end - start;
    cout << "Tiempo de ejecución TBB: " << duration_ms.count() << " ms" << endl;
    
    return 0;
}