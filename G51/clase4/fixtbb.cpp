#include <iostream>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
#include <tbb/parallel_reduce.h>
#include <vector>
#include <chrono>
#include <random>
#include <cmath>

using namespace std;
using namespace std::chrono;

const int MAX_VECTOR = 10000000;
vector<long long> vectorcitaA(MAX_VECTOR);
vector<long long> vectorcitaB(MAX_VECTOR);
vector<long long> vectorcitaC(MAX_VECTOR);

void initialize() {
    //for paralelo
    tbb::parallel_for(tbb::blocked_range<int>(0, MAX_VECTOR),
        [](const tbb::blocked_range<int>& r) {
            for (int i = r.begin(); i != r.end(); ++i) {
                //Genero un número aleatorio entre 1 y 10000
                vectorcitaA[i] = 5;
                vectorcitaB[i] = 5;
            }
        });
    
}

void cross_product() {
    //for paralelo
    tbb::parallel_for(tbb::blocked_range<int>(0, MAX_VECTOR),
        [](const tbb::blocked_range<int>& r) {
            for (int i = r.begin(); i != r.end(); ++i) {
                vectorcitaC[i] = vectorcitaA[i] * vectorcitaB[i];
            }
        });
}

long long sum() {
    //reduce paralelo
    long long suma =  tbb::parallel_reduce(tbb::blocked_range<int>(0, MAX_VECTOR), 0LL,
        [](const tbb::blocked_range<int>& r, long long init) -> long {
            long long sum = init;
            for (int i = r.begin(); i != r.end(); ++i) {
                sum += vectorcitaC[i]*vectorcitaC[i];
            }
            return sum;
        },
        [](long long x, long long y) -> long long{
            return x + y;
        });
    return suma;
}

int main() {
    auto start_time = high_resolution_clock::now();
    initialize();
    cross_product();
    long long result = sum();
    auto end_time = high_resolution_clock::now();
    duration<double> duration = duration_cast<milliseconds>(end_time - start_time);
    cout << "Result: " << result << endl;
    cout << "\nTime with TBB: " << duration.count() << " milliseconds" << endl;
    
}
