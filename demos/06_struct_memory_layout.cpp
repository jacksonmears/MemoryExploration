#include <iostream>
using namespace std;

struct Demo {
    char a;   // 1 byte
    char b;
    int one;    // 4 bytes (but aligned)
    char c;   // 1 byte
    char d;     // 1 byte
    char e;
    int two;
    int three;
    char f;
};

int main() {
    Demo d;
    cout << "sizeof(Demo) = " << sizeof(Demo) << "\n";
    cout << "address of d.a = " << (void*)&d.a << "\n";
    cout << "Address of d.c = " << (void*)&d.b << "\n";
    cout << "Address of d.b = " << &d.one << "\n";
    cout << "Address of d.c = " << (void*)&d.c << "\n";
    cout << "Address of d.c = " << (void*)&d.d << "\n";
    cout << "Address of d.c = " << (void*)&d.e << "\n";
    cout << "Address of d.b = " << &d.two << "\n";
    cout << "Address of d.b = " << &d.three << "\n";
    cout << "Address of d.c = " << (void*)&d.f << "\n";
    return 0;
}


/*
Understanding Struct Padding and Alignment in C++

This program demonstrates how struct padding and data alignment affect memory layout in C++.

Sample Output (addresses will differ on each run/system):
---------------------------------------------------------
sizeof(Demo) = 24
address of d.a = 0xd82a3ff9b0
Address of d.c = 0xd82a3ff9b1
Address of d.b = 0xd82a3ff9b4
Address of d.c = 0xd82a3ff9b8
Address of d.c = 0xd82a3ff9b9
Address of d.c = 0xd82a3ff9ba
Address of d.b = 0xd82a3ff9bc
Address of d.b = 0xd82a3ff9c0
Address of d.c = 0xd82a3ff9c4

Why sizeof(Demo) = 24?
----------------------
- Actual data = 7 chars (7 bytes) + 3 ints (12 bytes) = 19 bytes.
- Reported size = 24 bytes.
- The compiler inserts padding to align ints and make memory access efficient.

Breakdown of field placement:
-----------------------------
1. char a  -> offset 0
2. char b  -> offset 1
   (2 bytes padding for alignment)
3. int one -> offset 4
4. char c  -> offset 8
5. char d  -> offset 9
6. char e  -> offset 10
   (1 byte padding for alignment)
7. int two -> offset 12
8. int three -> offset 16
9. char f -> offset 20
   (3 bytes padding at the end so total size is a multiple of 4)

Educational Notes:
------------------
- Padding ensures that data types are aligned to word boundaries.
- Without padding, misaligned data could cause slower access.
- Struct size is often larger than the sum of its members.
- Rearranging members (grouping ints together, then chars) reduces padding.
*/