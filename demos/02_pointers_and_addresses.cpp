#include <iostream>
using namespace std;

int main() {
    int x = 42;
    int *p = &x;

    cout << "Value of x: " << x << "\n";
    cout << "Address of x (&x): " << p << "\n";
    cout << "Value at pointer (*p): " << *p << "\n";

    *p = 99; // modify through pointer
    cout << "After *p = 99, x = " << x << "\n";
    return 0;
}
