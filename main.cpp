#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void heavy_task(long long &result) {
    long long sum = 0;
    for (long long i = 0; i < 1e8; i++) sum += i % 7;
    result = sum;
}

int main() {
    // --- Single-threaded version ---
    long long r1 = 0, r2 = 0;
    auto start1 = chrono::high_resolution_clock::now();

    heavy_task(r1);
    heavy_task(r2);

    auto end1 = chrono::high_resolution_clock::now();

    cout << "Single-thread results: " << r1 << " " << r2 << "\n";
    cout << "Elapsed (1 thread): "
         << chrono::duration_cast<chrono::milliseconds>(end1 - start1).count()
         << " ms\n\n";

    // --- Multi-threaded version ---
    r1 = r2 = 0;
    auto start2 = chrono::high_resolution_clock::now();

    thread t1(heavy_task, ref(r1));
    thread t2(heavy_task, ref(r2));

    t1.join();
    t2.join();

    auto end2 = chrono::high_resolution_clock::now();

    cout << "Multi-thread results: " << r1 << " " << r2 << "\n";
    cout << "Elapsed (2 threads): "
         << chrono::duration_cast<chrono::milliseconds>(end2 - start2).count()
         << " ms\n";
}
