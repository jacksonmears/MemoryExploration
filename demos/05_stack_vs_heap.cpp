#include <iostream>
using namespace std;

int main() {
    int stackVar = 5; // stack
    int *heapVar = new int(10); // heap

    cout << "Stack variable address: " << &stackVar << "\n";
    cout << "Heap variable address: " << heapVar << "\n";

    delete heapVar;
    return 0;
}
