#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};  // Array allocated on the stack
    int *p = arr;               // `arr` decays into a pointer to its first element

    cout << "*p = " << *p << "\n";   // prints arr[0] = 10
    p++;                             // move pointer to next int (offset by sizeof(int) = 4 bytes)
    cout << "After p++, *p = " << *p << "\n";   // prints arr[1] = 20
    p++;
    cout << "After another p++, *p = " << *p << "\n"; // prints arr[2] = 30
    return 0;
}

/*
# Understanding Arrays, Vectors, and Pointers Under the Hood

This program shows how pointer arithmetic works with arrays, and sets up the bigger picture of how C++ arrays and vectors are represented in memory.

-------------------------------------------------
## Arrays in Memory 
- `int arr[3] = {10,20,30};` declares a **fixed-size array** on the **stack**.
- The name `arr` decays into a pointer to the **first element** (`&arr[0]`).
- Elements are laid out **contiguously** in memory:
    arr[0] | arr[1] | arr[2]
- Each element is `sizeof(int)` (typically 4 bytes).
- base_address = &arr[0] like mentioned earlier with the first element
- Formula for address:
    address_of(arr[i]) = base_address + i * sizeof(int)

Example:
If arr[0] is at `0x7ffd5e9a0c0`, then:
- arr[1] = 0x7ffd5e9a0c4
- arr[2] = 0x7ffd5e9a0c8

Pointer arithmetic (`p++`) automatically jumps by `sizeof(int)` bytes.

-------------------------------------------------
## Vectors in Memory
Unlike arrays, `std::vector<int> v = {10,20,30};` has two parts:
1. **Vector object itself** → lives on the **stack**.
   - Contains 3 fields (on a 64-bit system, each is 8 bytes):
     - Pointer to the first element in the heap
     - Size (number of elements currently stored)
     - Capacity (how many elements can be stored before resizing)
   - Total: ~24 bytes.

2. **Dynamic storage (the elements)** → lives on the **heap**.
   - The pointer stored in the vector object points here.
   - These heap elements are contiguous, just like arrays.

So:
- `arr[i]` = offset into stack memory.
- `vector[i]` = offset into heap memory (via a pointer stored in the stack object).

-------------------------------------------------
## Key Distinctions
- **Arrays:**
  - Fixed size, allocated on stack (unless declared with `new`).
  - Elements live directly in stack memory.
  - `arr` is just a pointer to the first element.

- **Vectors:**
  - Small control block on stack (pointer, size, capacity).
  - Elements allocated dynamically on the heap.
  - Grows/resizes automatically when more space is needed.
  - Safer and more flexible, but slightly more overhead.

-------------------------------------------------
## Why This Matters
- Arrays and vectors both rely on **contiguous memory** and **offset calculation**.
- The CPU does not "walk through" memory; it calculates addresses directly:
    base + i * element_size
- Understanding the difference in stack vs heap storage is critical for:
  - Performance tuning
  - Avoiding memory leaks
  - Writing efficient low-level code
*/
