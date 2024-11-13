#include <iostream>
#include <thread>

using namespace std;

void addme(
    int n,
    double a[],
    double b[],
    int min,
    int max
){
    for (int i = min; i < max; i++)
    {
        a[i] = b[i] + 1;
    }
}

int main()
{
    const int n = 100000;
    double a[n+1];
    a[0] = 1.0;

    addme(n, a + 1, a, 0, n);

    double b[n+1];
    b[0] = 1.0;

    //4 hilos
    thread t1(addme, n, b + 1, b, 0, n/4);
    thread t2(addme, n, b + 1, b, n/4, n/2);
    thread t3(addme, n, b + 1, b, n/2, 3*n/4);
    thread t4(addme, n, b + 1, b, 3*n/4, n);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    for (int i = 0; i < 10; i++)
    {
        int rnd = rand() % n;
        printf("a[%d] = %.0f, b[%d] = %.0f\n", rnd, a[rnd], rnd, b[rnd]);
    }

    

    return 0;
}