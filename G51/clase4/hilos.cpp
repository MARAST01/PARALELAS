#include <iostream>
#include <thread>
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

int main() {
    auto start = high_resolution_clock::now();

    thread t1(fillVector, 0, VECTOR_SIZE / 2);
    thread t2(fillVector, VECTOR_SIZE / 2, VECTOR_SIZE);

    t1.join();
    t2.join();

    long result1 = 0, result2 = 0;
    thread t3(sumVector, 0, VECTOR_SIZE / 2, ref(result1));
    thread t4(sumVector, VECTOR_SIZE / 2, VECTOR_SIZE, ref(result2));

    t3.join();
    t4.join();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time 2 threads: " << duration.count() << " ms" << endl;

    cout << "Result: " << result1 + result2 << endl;

    return 0;
}