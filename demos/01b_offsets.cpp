#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int arr[4] = {10, 20, 30, 40};

    cout << "Array values and addresses in hex:\n";
    for (int i = 0; i < 4; i++) {
        cout << "arr[" << dec << i << "] = " << arr[i] << " at address " << hex << showbase << (uintptr_t)&arr[i] << "\n";
    }

    cout << "\nNotice how each element is offset by sizeof(int) = " << dec << sizeof(int) << " bytes.\n";
    return 0;
}



/*
# Understanding Memory Offsets in Arrays

In the previous example, we learned that memory addresses point to the **first byte of a variable** in RAM.  
Now let's extend this to arrays and how elements are laid out in memory.

## Arrays Are Contiguous in Memory

- When you declare an array like `int arr[4] = {10, 20, 30, 40};`, the compiler stores all elements **contiguously** in RAM.
- Each element occupies `sizeof(int)` bytes (typically 4 bytes for a 32-bit integer).
- The memory address of each element is therefore **offset** from the previous one by `sizeof(int)`.

### Analogy

Imagine a row of mailboxes again:

- Each mailbox holds **1 byte**.
- An `int` occupies 4 consecutive mailboxes.
- The first `int` (`arr[0]`) starts at mailbox `0xe395ffe24`.
- The next `int` (`arr[1]`) starts 4 mailboxes later → `0xe395ffe28`.
- And so on for the rest of the array.
- The "offset" = number of bytes between the start of one element and the next.

## Why Offsets Matter

- CPU uses the base address of the array (`&arr[0]`) + offset to access any element.
- Formula: `address_of_element_i = base_address + i * sizeof(element_type)`
- Example from this program:

| Element       | Address (hex)       | Explanation                     |
|---------------|------------------|---------------------------------|
| arr[0] = 10   | 0x4eb9fffbe0      | first 4 bytes for arr[0]       |
| arr[1] = 20   | 0x4eb9fffbe4      | 4 bytes after arr[0]           |
| arr[2] = 30   | 0x4eb9fffbe8      | 4 bytes after arr[1]           |
| arr[3] = 40   | 0x4eb9fffbec      | 4 bytes after arr[2]           |

- Notice how each element is offset by `sizeof(int) = 4 bytes`.

### Key Takeaways

1. Arrays are stored in **contiguous memory**.
2. Offsets allow the CPU to calculate the address of any element efficiently.
3. Understanding offsets is essential for pointer arithmetic, iterating arrays, and low-level memory management.
4. Hexadecimal addresses are just **human-readable representations**; CPU still works with binary bytes.
5. This concept is imprtant for understand heap/stack growths, importance for pointer arithmetic, and understanding how this would be computed in assembly!

*/

