#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

void benchmark(size_t size) {
    vector<int> arr(size, 1);
    auto start = high_resolution_clock::now();
    long long sum = 0;
    for (int repeat = 0; repeat < 100; repeat++) {
        for (size_t i = 0; i < size; i++) sum += arr[i];
    }
    auto end = high_resolution_clock::now();
    cout << "Size " << size * sizeof(int) / 1024 << " KB: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms\n";
}

int main() {
    cout << "Cache Levels Demonstration:\n\n";

    benchmark(4 * 1024);      // ~16 KB fits in L1
    benchmark(64 * 1024);     // ~256 KB fits in L2
    benchmark(2 * 1024 * 1024); // ~8 MB fits in L3
    benchmark(64 * 1024 * 1024); // ~256 MB -> main memory

    /*
    -----------------------------------------------------
    Explanation:
    -----------------------------------------------------
    - L1 cache: tiny, very fast (~1 ns).
    - L2 cache: bigger, slower (~4 ns).
    - L3 cache: shared, slower (~10-20 ns).
    - Main memory: hundreds of ns.

    Lesson:
    - Performance depends heavily on data fitting into cache.
    - Larger arrays spill out of small caches → slowdowns.
    */
    return 0;
}
