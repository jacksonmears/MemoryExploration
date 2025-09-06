#include <iostream>
using namespace std;

int main() {
    int x = 10;
    cout << "This program can't directly show virtual memory mapping,\n";
    cout << "but every address you see (e.g., &x = " << &x << ")\n";
    cout << "is a virtual address managed by the OS.\n";
    return 0;
}
