#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int &ref = x;   // reference
    int *ptr = &x;  // pointer

    cout << "x = " << x << "\n";
    ref = 20; // modifies x
    cout << "After ref = 20, x = " << x << "\n";
    *ptr = 30; // modifies x
    cout << "After *ptr = 30, x = " << x << "\n";

    cout << "Reference always refers to x, but pointer can change:\n";
    int y = 50;
    ptr = &y;
    cout << "*ptr = " << *ptr << " (now points to y)\n";
    return 0;
}
