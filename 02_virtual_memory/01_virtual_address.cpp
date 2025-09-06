#include <iostream>
using namespace std;

int main() {
    cout << "Demonstrating Virtual vs Physical Addresses:\n\n";

    int localVar = 123;
    cout << "Virtual address of localVar: " << &localVar << "\n";

    int *heapVar = new int(456);
    cout << "Virtual address of heapVar: " << heapVar << "\n";

    static int staticVar = 789;
    cout << "Virtual address of staticVar: " << &staticVar << "\n";

    /*
    -----------------------------------------------------
    Explanation:
    -----------------------------------------------------
    - These addresses are **virtual addresses**, not physical.
    - The CPU uses a Memory Management Unit (MMU) + page tables
      to translate them to real physical RAM locations.
    - Every program you run will see its own independent
      address space, even if they overlap virtually.

    Lesson:
    - Virtual memory provides isolation & abstraction.
    - You cannot directly see physical addresses in user space.
    */

    delete heapVar;
    return 0;
}
