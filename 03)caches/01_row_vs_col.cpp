#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

const int N = 4096; // 4096x4096 matrix (~128 MB)

int main() {
    cout << "Row-major vs Column-major Access:\n\n";
    static int matrix[N][N];

    // Row-major access (cache-friendly)
    auto start = high_resolution_clock::now();
    long long sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += matrix[i][j];
    auto end = high_resolution_clock::now();
    cout << "Row-major time: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms\n";

    // Column-major access (cache-unfriendly)
    start = high_resolution_clock::now();
    sum = 0;
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            sum += matrix[i][j];
    end = high_resolution_clock::now();
    cout << "Column-major time: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms\n";

    /*
    -----------------------------------------------------
    Explanation:
    -----------------------------------------------------
    - Memory is laid out row by row (row-major order).
    - Row-major traversal keeps data in the cache (fast).
    - Column-major jumps around in memory, causing cache misses.

    Lesson:
    - Access patterns matter a LOT for cache efficiency.
    */
    return 0;
}
