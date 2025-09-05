#include <iostream>
using namespace std;

int main() {
    cout << "Demonstrating a real memory leak:\n";

    // Step 1: Allocate memory on the heap
    int *ptr = new int(42);   // heap memory allocated
    cout << "ptr points to " << *ptr << " at address " << ptr << "\n";

    // Step 2: Reassign pointer without deleting old memory
    int x = 30;
    ptr = &x;  // old memory (42) is now lost -> memory leak!
    cout << "ptr now points to " << *ptr << " at address " << ptr << "\n";


    cout << "Program ends. Original 42 is still leaked because we lost the pointer.\n";

    

    return 0;
}


/*

-----------------------------------------------------
What just happened:
-----------------------------------------------------
1) new int(42) allocates memory on the heap and returns an address.
    'ptr' stores this address.
    there is currently no way to access the address for (42) besides the current ptr pointer.

2) ptr = new int(100) allocates new memory on the heap.
    Now 'ptr' points to the new allocation.
    The original memory (42) has no pointer referencing it.
    This memory is now **floating** in the heap.
    There is no way to acces it NOR delete it -> memory leak!


-----------------------------------------------------
Key Points About Memory Leaks
-----------------------------------------------------
- Occur when heap memory becomes unreachable without being freed.
- Reassigning a pointer without deleting its previous memory is a common cause.
- Always free memory before reassigning pointers:
    delete ptr;      // free old memory
    ptr = new int(100);  // safe reassignment
- Alternatively, use smart pointers (unique_ptr, shared_ptr) to automate cleanup.

-----------------------------------------------------
Lesson:
-----------------------------------------------------
- Raw pointers are powerful but risky.
- Heap memory must always be explicitly managed.
- Memory leaks accumulate and can crash long-running programs.

*/