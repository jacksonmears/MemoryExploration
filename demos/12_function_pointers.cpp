#include <iostream>
using namespace std;

void hello() {
    cout << "Hello from a function!\n";
}

void goodbye() {
    cout << "Goodbye from a function!\n";
}

int main() {
    void (*fp)() = hello;
    fp(); // calls hello

    fp = goodbye;
    fp(); // calls goodbye

    return 0;
}
