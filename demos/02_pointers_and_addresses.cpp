#include <iostream>
using namespace std;

int main() {
    int x = 42;          // A regular integer stored on the stack
    int *p = &x;         // Pointer p holds the address of x

    cout << "Value of x: " << x << "\n";
    cout << "Address of x (&x): " << p << "\n";
    cout << "Value at pointer (*p): " << *p << "\n";
    cout << "Address of pointer (&p): " << &p << "\n";

    *p = 99; // modify x through the pointer
    cout << "After *p = 99, x = " << x << "\n";
    return 0;
}


/*

(my simplified version):

the CPU at runtime converts the 
int x = 42;
int *p = &x;

to 

int 0x930e3ffd24 = 00000000 000000000 00000000 00101010;
int *0x6ab11ff700 = 0x930e3ffd24;

so when you dereference the pointer p you get:

int *p = 99;
int *0x6ab11ff700 points to memory -> 0x930e3ffd24 = 99;


(chatGPTs attempt at deepening the conversation):


--------------------------------------------
How pointers and memory addresses work
--------------------------------------------

When the program runs:

    int x = 42;

The compiler asks the operating system for 4 bytes of memory (on most systems,
sizeof(int) == 4). Suppose the OS gives us address 0x930e3ffd24.  
So memory at that location contains:

    0x930e3ffd24 : 00000000 00000000 00000000 00101010   (binary for 42)

Then:

    int *p = &x;

Here, `p` itself is a variable (usually 8 bytes on a 64-bit system).
It is stored at a DIFFERENT memory address, e.g. 0x6ab11ff700.  
Inside p’s storage we place the value `0x930e3ffd24` (the address of x).  
So:

    p (0x6ab11ff700) -> stores 0x930e3ffd24
    x (0x930e3ffd24) -> stores the bits for 42

When you dereference:

    *p

The CPU looks at the address stored inside p (0x930e3ffd24),
goes to that memory location, and reads/writes 4 bytes there (because p is an int*).

So:

    *p = 99;

rewrites the 4 bytes at address 0x930e3ffd24 to represent 99.
After that, `x` will print as 99.

--------------------------------------------
How does the CPU/compiler know the type?
--------------------------------------------

At runtime, the CPU doesn’t “know” about C++ types — it only knows about bytes
in memory. The type information exists at COMPILE TIME.  

- `int` tells the compiler how many bytes to reserve (usually 4).  
- `int*` tells the compiler to treat the stored value as an *address*, 
  not as an integer.  
- When you write `*p`, the compiler generates assembly that:
    1. Reads the value inside p (an address).  
    2. Treats it as pointing to an `int`.  
    3. Loads or stores 4 bytes at that location.  

So the difference between `int` and `int*` is entirely in how the compiler
generates instructions. The CPU itself just executes loads/stores of bytes
at given addresses.

--------------------------------------------
Quick Summary
--------------------------------------------
- Variables have addresses and hold values.  
- Pointers are variables that hold addresses.  
- Dereferencing `*p` follows the address and reads/writes the data there.  
- Type (`int`, `int*`, `double*`, etc.) tells the compiler how many bytes
  to read/write at the pointed location.  

This is the core idea behind pointers in C++.

*/
