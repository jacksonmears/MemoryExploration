#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};
    int *p = arr;

    cout << "*p = " << *p << "\n";
    p++;
    cout << "After p++, *p = " << *p << "\n";
    p++;
    cout << "After another p++, *p = " << *p << "\n";
    return 0;
}
