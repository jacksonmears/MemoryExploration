#include <iostream>
using namespace std;

int main() {
    int x = 100;
    int *p = &x;
    int **pp = &p;

    cout << "x = " << x << "\n";
    cout << "*p = " << *p << "\n";
    cout << "**pp = " << **pp << "\n";

    **pp = 200;
    cout << "After **pp = 200, x = " << x << "\n";
    return 0;
}
