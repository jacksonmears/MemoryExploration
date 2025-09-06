#include <iostream>
using namespace std;

int main() {
    // Step 1: Normal integer variable
    int x = 100;
    
    // Step 2: Pointer to integer
    int *p = &x;   // p stores the address of x
    
    // Step 3: Pointer to pointer (double pointer)
    int **pp = &p; // pp stores the address of p

    cout << "x = " << x << "\n";       
    cout << "*p = " << *p << "\n";     
    cout << "**pp = " << **pp << "\n"; 

    // Modifying x using double pointer
    **pp = 200; 
    cout << "After **pp = 200, x = " << x << "\n";

    // Double pointer can be used to change which pointer points to what
    int y = 300;
    *pp = &y; // now p points to y
    cout << "After *pp = &y:\n";
    cout << "*p = " << *p << " (p now points to y)\n";
    cout << "**pp = " << **pp << " (double pointer still works)\n";

    
    return 0;
}







/*

-----------------------------------------------------
Pointers vs Double Pointers in C++
-----------------------------------------------------

1) Single Pointers
------------------
int *p = &x;

- Stores the **address** of a variable.
- Dereference with *p to access/change the value.
- Can point to different variables at different times.

2) Double Pointers
------------------
int **pp = &p;

- Stores the **address of a pointer**.
- Dereference once (*pp) → gives the pointer itself (p)
- Dereference twice (**pp) → gives the value pointed to by the pointer (x)
- Useful for:
    - Passing pointers to functions so they can modify the original pointer
    - Managing dynamically allocated arrays of pointers
    - Working with multi-level pointer structures

3) Key Differences
------------------
- Single pointer: points to a variable.
- Double pointer: points to a pointer.
- Can have triple pointers (***ppp) but they are rarely needed.
- Each level of indirection adds flexibility but also complexity.

-----------------------------------------------------
Quick Summary
-----------------------------------------------------
- *p  → value of x
- **pp → value of x through pointer to pointer
- *pp  → the pointer p itself
- Double pointers allow indirect modification of pointers themselves.
- Useful in dynamic memory management, function parameter modification, and complex data structures.

*/
