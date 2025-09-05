#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int num1 = 1;
    int num2 = 2;
    int* arr[2] = {&num1, &num2};

    cout << "Values and addresses in hex:\n";
    for (int i = 0; i < 2; i++) {
        cout << "arr[" << dec << i << "] = " << *arr[i] << " at address " << arr[i] << "\n";
    }

    return 0;
}


/*
# Understanding Memory Addresses and RAM

Memory addresses in a computer tell the CPU where to find data in RAM. To truly understand this, we need to look at **how RAM is organized**.

## RAM is a Giant Array of Bytes

- Think of RAM as **one massive array of 1’s and 0’s**.
- Every **8 bits** (1 or 0) are grouped into a **byte**.
- Each byte has a unique label (its memory address):
  - The first 8 bits → byte 0
  - The next 8 bits → byte 1
  - … eventually → byte 0xe395ffe24, etc. (decimal format is the 61085282496th byte)
- This is why memory addresses are so large when printed—they’re indexing this enormous array of bytes.

### Analogy

Imagine a **row of mailboxes**, each mailbox holding 8 letters (bits).  
- Each mailbox has a number on it (memory address).  
- If you want to store an object (like an `int`), you place its bits across 4 consecutive mailboxes.  
- The address of the object is the number of the first mailbox.  
- Memory Addresses are like a map telling you, “Start reading from this mailbox to get the whole object.”

## Variables Occupy Multiple Bytes

- Example: `int num = 12345;`  
  - Typically 4 bytes (32 bits) → stored in 4 consecutive bytes.
  - Memory address `&num` → points to first byte of `num`.
  - CPU reads 4 bytes starting from that address to reconstruct the integer.
  - (assuming memory address is 0xe395ffe24)

| Byte Address  | Stored Bits           |
|---------------|---------------------|
| 0xe395ffe24   | first 8 bits of num  |
| 0xe395ffe25   | next 8 bits          |
| 0xe395ffe26   | next 8 bits          |
| 0xe395ffe27   | last 8 bits          |


## Takeaways

- RAM = huge array of bytes.
- Memory addresses = labels for individual bytes.
- Pointers always point to the first byte of a variable.
- Hex is just human-friendly formatting; the CPU sees binary.
- Understanding this is crucial for pointers, arrays, and low-level programming.
*/
