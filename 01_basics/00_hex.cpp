
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int showcase_hex[13] = {1, 2, 8, 16, 32, 33, 41, 8, 9, 10, 11, 12, 15000};

    for (int i = 0; i < 13 ; i++) {
        cout << "Showcase[" << dec << i << "] = " << showcase_hex[i] << " with hex of " << hex << showcase_hex[i] << endl;
    }
}


/*
# Why Understanding Memory Addresses Matters

Memory addresses are the fundamental way a computer organizes and accesses data. Every variable, object, or data structure in a program resides at a specific address in memory. 
Understanding memory addresses is important because:

1. **Pointer Manipulation**
   - Pointers store memory addresses, allowing programs to directly reference and modify data. Knowing how addresses work helps prevent common bugs like dangling pointers or buffer overflows.

2. **Efficient Data Access**
   - Low-level optimizations, such as cache-friendly data layouts or aligned memory access, rely on an understanding of how memory is structured.

3. **Debugging and Diagnostics**
   - Tools like debuggers, memory profilers, or crash logs often display memory addresses in hexadecimal. Understanding them lets you interpret these tools effectively.

4. **Systems Programming**
   - Operating systems, embedded systems, and drivers frequently require direct memory manipulation. Without a grasp of addresses, programming at this level becomes error-prone or impossible.

**Key Idea:** While humans read addresses in hexadecimal for convenience, the CPU and RAM only work with binary. Recognizing this distinction gives you better insight into how programs interact with memory under the hood.



In hexadecimal:
 - Byte is 8 bits and a nibble is 4 bits
 - hexadecimal values are comprised of nibbles
 - Values in bianry are converted to digits go from 0–9, then continue as a–f (where 'a' = 10, 'b' = 11, etc.).
 - Example: decimal 8 = hex '8', decimal 9 = hex '9', decimal 10 = hex 'a', decimal 11 = hex 'b', etc.
 - example for 17 -> binary is 10001. hexadecimal is computed in nibbles so now we have -> (000)1 and 0001
 - 17 was split into two nibbles obviously starting from the least significant bit. 
 - now merely concatenate each nibble and you get 11 for the hexadecimal for 17. 

Program Output Breakdown:

Showcase[0] = 1 with hex of 1
   → Decimal 1 is simply hex 1.

Showcase[1] = 2 with hex of 2
   → Decimal 2 is hex 2.

Showcase[2] = 8 with hex of 8
   → Decimal 8 is hex 8.

Showcase[3] = 16 with hex of 10
   → Decimal 16 converts to hex 10 (because 16 = 10000 (binary) = 0001 + 0000 = 0).

Showcase[4] = 32 with hex of 20
   → Decimal 32 converts to hex 20 (32 = 100000 (binary) = 0010 + 0000 = 32).

Showcase[5] = 33 with hex of 21
   → Decimal 33 converts to hex 21 (33 = 100001 = 0010 + 0001 = 21).

Showcase[6] = 41 with hex of 29
   → Decimal 41 converts to hex 29 (101001 = 0010 + 1001 = 29).

Showcase[7] = 8 with hex of 8
   → Same as earlier, decimal 8 is hex 8.

Showcase[8] = 9 with hex of 9
   → Decimal 9 is hex 9.

Showcase[9] = 10 with hex of a
   → Decimal 10 converts to hex 'a' (hex letters start here).

Showcase[10] = 11 with hex of b
   → Decimal 11 converts to hex 'b'.

Showcase[11] = 12 with hex of c
   → Decimal 12 converts to hex 'c'.

Showcase[12] = 15000 with hex of 3a98
   → Decimal 15000 = hex 3a98 (0011101010011000 = 0011 + 1010 + 1001 + 1000 = 3 + 'a' + 9 + 8 = 3a98).

*/