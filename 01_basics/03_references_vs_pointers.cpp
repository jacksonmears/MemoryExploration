#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int &ref = x;   // reference (alias to x)
    int *ptr = &x;  // pointer (stores the address of x)

    cout << "x = " << x << "\n";

    ref = 20; // modifies x
    cout << "After ref = 20, x = " << x << "\n";

    *ptr = 30; // modifies x through pointer
    cout << "After *ptr = 30, x = " << x << "\n";

    cout << "Reference always refers to x, but pointer can change:\n";
    int y = 50;
    ptr = &y; // now pointer refers to y
    cout << "*ptr = " << *ptr << " (now points to y)\n";

    return 0;
}


/*

-----------------------------------------------------
Pointers vs References in C++
-----------------------------------------------------

1) References
-------------
    int &ref = x;

- A reference is an **alias** for an existing variable.
- After binding, `ref` and `x` are the same object with two names.
- References cannot be "reseated":
  - You cannot make `ref` refer to another variable later.
- At the assembly level, references often compile down to the same
  load/store instructions as if you directly used the variable.

Example:
    int x = 10;
    int &ref = x;  // ref is another name for x
    ref = 20;      // modifies x directly

2) Pointers
-----------
    int *ptr = &x;

- A pointer is a variable that stores an **address**.
- You can change a pointer to point to a different variable.
- To access the value at the pointed address, use `*ptr` (dereference).
- To get the address of a variable, use `&x`.

Example:
    int y = 50;
    ptr = &y;    // pointer now points to y
    *ptr = 60;   // modifies y

3) Key Differences
------------------
- **Reference:**
  - Must be initialized when declared.
  - Cannot be null.
  - Cannot be reseated (always bound to the original variable).
  - Acts as a permanent alias.

- **Pointer:**
  - Can be null (point to nothing).
  - Can be reassigned to point to different variables.
  - Requires dereferencing (`*ptr`) to access the value.

4) How does the compiler/CPU know the type?
--------------------------------------------
- At runtime, the CPU does not know about "references" — they are
  purely a compile-time construct.
- For pointers, the CPU just sees an integer value (an address).
- The type (`int*`, `double*`, etc.) tells the compiler how many
  bytes to load or store when dereferencing.

-----------------------------------------------------
Quick Summary
-----------------------------------------------------
- References are "aliases" → simpler, safer, cannot be changed.
- Pointers are "variables storing addresses" → more flexible, but riskier.
- Both allow indirect access to data, but references are stricter
  while pointers are more powerful.

*/
