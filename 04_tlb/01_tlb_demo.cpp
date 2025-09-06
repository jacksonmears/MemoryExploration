#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    cout << "Translation Lookaside Buffer (TLB) Demo:\n\n";

    const size_t N = 1024 * 1024 * 64; // 64M integers
    vector<int> arr(N, 1);

    long long sum = 0;
    auto start = high_resolution_clock::now();

    // Stride access to simulate TLB misses
    const int stride = 4096 / sizeof(int); // jump one page each step
    for (size_t i = 0; i < N; i += stride) {
        sum += arr[i];
    }

    auto end = high_resolution_clock::now();
    cout << "Stride access time: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms\n";

    /*
    -----------------------------------------------------
    Explanation:
    -----------------------------------------------------
    - CPU caches page table entries in the TLB.
    - When stride skips between pages, the TLB may miss,
      forcing a walk through page tables.
    - This demonstrates how even address translation
      has caching effects.

    Lesson:
    - TLB performance is crucial for memory-heavy programs.
    */
    return 0;
}
