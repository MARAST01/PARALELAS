#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int VECTOR_SIZE = 10000000;
vector<long> v(VECTOR_SIZE);

void fillVector(int start, int end) {
    for (int i = start; i < end; i++) {
        v[i] = 100;
    }
}

void sumVector(int start, int end, long &result) {
    for (int i = start; i < end; i++) {
        result += v[i];
    }
}


int main () {
    auto start = high_resolution_clock::now();

    fillVector(0, VECTOR_SIZE);
    long result = 0;
    sumVector(0, VECTOR_SIZE, result);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time seq: " << duration.count() << " ms" << endl;
    cout << "Result: " << result << endl;

    return 0;
}