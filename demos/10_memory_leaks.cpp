#include <iostream>
using namespace std;

int main() {
    cout << "Demonstrating a memory leak:\n";
    int *leak = new int(42);
    cout << "Allocated int = " << *leak << "\n";
    // forgot delete leak;  <-- leak!
    cout << "Program ends without freeing memory.\n";
    return 0;
}
