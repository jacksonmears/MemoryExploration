#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int stackVar1 = 5;  // allocated on the stack
    int stackVar2 = 22; // also on the stack

    int *heapVar1 = new int(10);               // allocated on the heap (C++ style)
    int *heapVar2 = (int*)malloc(sizeof(int)); // allocated on the heap (C style)

    cout << "Stack variable address: " << &stackVar1 << "\n";
    cout << "Stack variable address: " << &stackVar2 << "\n";
    cout << "Heap variable address: " << heapVar1 << "\n";
    cout << "Heap variable address: " << heapVar2 << "\n";

    delete heapVar1; // free heapVar1 (calls destructor for objects, safe in C++)
    free(heapVar2);  // free heapVar2 (raw free, no destructor called)
    return 0;
}

/*
# Understanding Stack vs Heap Memory

This program demonstrates the difference in **memory regions** where variables are stored:
(also note the memory addresses used in the examples are from MY system and could very well be different than yours but the concept would hold true however the hex addresses may be different than yours!)

---

## Stack Allocation
- `stackVar1` and `stackVar2` are local variables.
- Their addresses are very close together:
  Stack variable address: 0x7a399ff95c
  Stack variable address: 0x7a399ff958
- Notice how the second address (`stackVar2`) is just a few bytes apart from the first.
- This is because the **stack grows and stores data contiguously** (last-in, first-out).
- Memory is automatically managed: when `main()` exits, these variables are destroyed.

---

## Heap Allocation
- `heapVar1` (created with `new`) and `heapVar2` (created with `malloc`) both live on the **heap**.
- Their addresses:
  Heap variable address: 0x24e5dab1a60
  Heap variable address: 0x24e5dab1a80
- Notice how they are also close together, but **separated from the stack region**.
- Heap memory is managed manually — you must call `delete` (C++) or `free` (C) when done.
- Unlike the stack, the heap does **not automatically clean up** when the function ends.

---

## Stack vs Heap in Memory Layout
- **Stack region**: Typically grows **downward** in memory (higher to lower addresses).
- **Heap region**: Typically grows **upward** in memory (lower to higher addresses).
- That’s why stack addresses (`0x7a399ff95c`) look very different from heap addresses (`0x24e5dab1a60`).

---

## Key Differences

| Feature              | Stack                          | Heap                                |
|----------------------|--------------------------------|-------------------------------------|
| Allocation           | Automatic (compiler managed)   | Manual (`new/delete`, `malloc/free`)|
| Lifetime             | Ends when scope ends           | Until explicitly freed              |
| Speed                | Very fast (contiguous)         | Slower (fragmentation possible)     |
| Size                 | Limited                        | Large (depends on system RAM)       |
| Errors if misused    | Stack overflow                 | Memory leaks / dangling pointers    |

---

## Educational Notes
- Stack and heap live in **different regions of process memory**.
- They are clearly separate, but within each region, allocations tend to be close together.
- Understanding this distinction is critical for debugging memory issues, preventing leaks, and writing efficient C++ code.

*/
