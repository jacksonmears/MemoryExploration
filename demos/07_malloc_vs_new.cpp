#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    // 1. Stack allocation (automatic storage)
    vector<int> stackVec = {1, 2, 3};
    cout << "Stack-allocated vector contents: ";
    for (int val : stackVec) cout << val << " ";
    cout << "\n";

    // 2. Heap allocation with malloc (C style)
    // !!! WARNING: malloc does not call constructors !!!
    vector<int> *badVec = (vector<int>*)malloc(sizeof(vector<int>));
    // At this point, 'badVec' points to raw memory with no constructor called.
    // Accessing it would be undefined behavior.
    cout << "Heap (malloc): allocated raw memory for vector, but not initialized.\n";
    free(badVec);

    // 3. Heap allocation with new (C++ style)
    vector<int> *heapVec = new vector<int>({4, 5, 6});
    cout << "Heap-allocated vector contents (via new): ";
    for (int val : *heapVec) cout << val << " ";
    cout << "\n";
    delete heapVec;

    return 0;
}


/*
# Comparing Stack, malloc, and new in C++

In this program, we compare **three different ways to create a vector**:

---

## 1. Stack Allocation (Automatic Storage)

    vector<int> stackVec = {1, 2, 3};

- Memory is allocated on the **stack**.
- Lifetime is automatic: destroyed when the function exits.
- Constructors/destructors are called automatically.
- No need for `free` or `delete`.

---

## 2. Heap Allocation with malloc (C style)

    vector<int> *badVec = (vector<int>*)malloc(sizeof(vector<int>));

- Allocates raw bytes on the **heap**, but does **not call the vector constructor**.
- The object is left in an **uninitialized state** → using it is undefined behavior.
- You would need to call **placement new** to properly initialize it.
- Must be released with `free()`.
- Shows why `malloc` is unsafe for C++ objects.

---

## 3. Heap Allocation with new (C++ style)

    vector<int> *heapVec = new vector<int>({4, 5, 6});

- Allocates memory on the **heap** *and* calls the vector’s constructor.
- Object is properly initialized.
- Must be released with `delete` (which calls destructor + frees memory).
- Safe and idiomatic in C++ (but usually replaced by RAII containers like `std::unique_ptr`).

---

## Analogy

- **Stack** = A shelf where items are automatically placed and removed when done.
- **malloc** = Renting raw space in a warehouse, but no shelves or organization provided.
- **new** = Renting space *and* getting shelves installed to organize items correctly.

---

## Leading into Heap vs Stack

- The **stack** is fast, automatically managed, but limited in size.
- The **heap** is larger and flexible, but requires manual management (`new/delete`, `malloc/free`).
- Misusing `malloc` or `new` can cause memory leaks or undefined behavior.

*/
