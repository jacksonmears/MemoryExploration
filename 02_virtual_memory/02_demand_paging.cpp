#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    cout << "Demonstrating Demand Paging:\n\n";

    const size_t SIZE = 256 * 1024 * 1024; // 256 MB
    vector<char> bigArray(SIZE);           // allocated but not touched

    cout << "Step 1: Allocated 256 MB, but memory is not yet committed.\n";

    // Measure access time
    auto start = high_resolution_clock::now();
    for (size_t i = 0; i < SIZE; i += 4096) {
        bigArray[i] = 1; // touch each page (~4KB)
    }
    auto end = high_resolution_clock::now();

    cout << "Step 2: Accessed every page (page faults trigger).\n";
    cout << "Elapsed time: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms\n";

    /*
    -----------------------------------------------------
    Explanation:
    -----------------------------------------------------
    - The OS does not allocate real RAM until pages are touched.
    - When we access bigArray[i], the OS triggers a "page fault"
      and maps a real page of RAM to that virtual address.
    - This is called "demand paging".

    Lesson:
    - Virtual memory + page tables allow huge allocations
      without committing RAM until needed.
    */
    return 0;
}
