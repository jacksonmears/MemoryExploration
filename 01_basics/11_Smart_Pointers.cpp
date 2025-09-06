#include <iostream>
#include <memory>  // required for smart pointers
using namespace std;

int main() {
    cout << "Demonstrating smart pointers in C++:\n\n";

    // -------------------------------
    // 1) Unique Pointer (unique_ptr)
    // -------------------------------
    cout << "1) Unique Pointer (unique_ptr):\n";
    unique_ptr<int> uptr = make_unique<int>(42); // allocate and manage automatically
    cout << "uptr points to " << *uptr << "\n";

    // unique_ptr cannot be copied (ownership is unique)
    // unique_ptr<int> uptr2 = uptr; // ERROR: compilation fails
    // Ownership can be transferred using std::move
    unique_ptr<int> uptr2 = move(uptr);
    cout << "After move, uptr2 points to " << *uptr2 << "\n";
    cout << "Original uptr is now " << (uptr ? "not null" : "null") << "\n\n";

    // -------------------------------
    // 2) Shared Pointer (shared_ptr)
    // -------------------------------
    cout << "2) Shared Pointer (shared_ptr):\n";
    shared_ptr<int> sptr1 = make_shared<int>(100);
    shared_ptr<int> sptr2 = sptr1; // multiple pointers can share ownership
    cout << "sptr1 points to " << *sptr1 << ", sptr2 points to " << *sptr2 << "\n";
    cout << "Reference count: " << sptr1.use_count() << "\n\n"; // how many owners

    // -------------------------------
    // 3) Weak Pointer (weak_ptr)
    // -------------------------------
    cout << "3) Weak Pointer (weak_ptr):\n";
    weak_ptr<int> wptr = sptr1; // does NOT increase reference count
    cout << "Reference count after weak_ptr: " << sptr1.use_count() << "\n";

    if (auto temp = wptr.lock()) { // convert weak_ptr to shared_ptr temporarily
        cout << "wptr points to " << *temp << " via lock()\n";
    } else {
        cout << "wptr is expired\n";
    }

    // Step 4: When last shared_ptr goes out of scope, memory is freed automatically
    sptr1.reset();
    sptr2.reset(); // memory is automatically deleted
    if (wptr.expired()) {
        cout << "Memory managed by shared_ptr has been freed. weak_ptr is expired.\n";
    }


    return 0;
}




/*
-----------------------------------------------------
Smart Pointers in C++
-----------------------------------------------------

1) Unique Pointer (unique_ptr)
-------------------------------
- Owns a resource exclusively.
- Cannot be copied, only moved.
- Automatically deletes the managed object when it goes out of scope.
- Useful for single ownership scenarios.

Example:
    unique_ptr<int> uptr = make_unique<int>(42);

2) Shared Pointer (shared_ptr)
-------------------------------
- Multiple shared_ptr instances can own the same resource.
- Reference count tracks ownership.
- Automatically deletes memory when the last owner goes out of scope.
- Useful for shared ownership scenarios.

Example:
    shared_ptr<int> sptr1 = make_shared<int>(100);
    shared_ptr<int> sptr2 = sptr1; // shared ownership

3) Weak Pointer (weak_ptr)
---------------------------
- Does NOT increase reference count.
- Can be used to observe a shared_ptr without owning it.
- Prevents circular references which could cause memory leaks.
- Use lock() to access the resource safely.

Example:
    weak_ptr<int> wptr = sptr1;
    if (auto temp = wptr.lock()) { ... }

-----------------------------------------------------
Control Block for shared_ptr and weak_ptr
-----------------------------------------------------
- when an object is created with make_pointer a control block is also created to manage shared/weak pointers
- Every object managed by shared_ptr has an associated "control block".
- The control block stores:
    1) The reference count for shared_ptr (how many shared owners exist)
    2) The reference count for weak_ptr (how many weak observers exist)
    3) Optional custom deleter information
- How it works:
    - When a shared_ptr is copied, the shared count increases.
    - When a shared_ptr is destroyed, the shared count decreases.
    - When shared count drops to zero, the managed object is deleted.
    - Weak pointers allow observing the object without affecting the shared count.
    - When both shared count and weak count drop to zero, the control block itself is destroyed.
- This mechanism prevents premature deletion and enables safe weak_ptr access.
i.e. increasing safety for less memory leaks!

-----------------------------------------------------
Key Advantages of Smart Pointers
-----------------------------------------------------
- Prevent memory leaks by managing heap memory automatically.
- Reduce bugs from dangling pointers and manual delete.
- unique_ptr: exclusive ownership (fast and lightweight)
- shared_ptr: shared ownership (reference-counted)
- weak_ptr: observe shared ownership without prolonging lifetime

-----------------------------------------------------
Lesson:
-----------------------------------------------------
- Prefer smart pointers over raw pointers for heap memory management.
- Use unique_ptr when only one owner exists.
- Use shared_ptr when multiple owners need access.
- Use weak_ptr to break reference cycles and safely observe objects.
- Understanding the control block is key to understanding how shared_ptr and weak_ptr work under the hood.

*/