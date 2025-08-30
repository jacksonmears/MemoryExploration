#include <iostream>
using namespace std;

struct Demo {
    char a;   // 1 byte
    int b;    // 4 bytes (but aligned)
    char c;   // 1 byte
};

int main() {
    Demo d;
    cout << "sizeof(Demo) = " << sizeof(Demo) << "\n";
    cout << "Address of d.a = " << (void*)&d.a << "\n";
    cout << "Address of d.b = " << &d.b << "\n";
    cout << "Address of d.c = " << (void*)&d.c << "\n";
    return 0;
}
