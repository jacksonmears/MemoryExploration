#include <bits/stdc++.h>
using namespace std;

// ===== Global variables (live in data segment) =====
int global_var = 123;
int global_array[3] = {10, 20, 30};

// ===== Recursive function to show stack growth =====
void recurse(int depth) {
    int local = depth; // stack variable
    cout << "Stack depth " << depth << " -> address: " << &local
         << " value: " << local << endl;
    if (depth > 0) recurse(depth - 1);
}

int main() {
    cout << "===== GLOBALS (Data Segment) =====" << endl;
    cout << "global_var @ " << &global_var << " value: " << global_var << endl;
    cout << "global_array @ " << &global_array << " size: " << sizeof(global_array) << endl;

    // why the aparent 4 byte gap between global_var and global_array? My initail reaction was the global_array must have a pointer for it's memory address I forgot about
    // but that is NOT the case! the array structure is built with the initial pointer included (also why you can do it-array.begin() to get index of iterator! very useful!)
    // the buffer or "padding" is just that. padding. On a 64-bit system most global variables are aligned to 8-byte boundaries so this is a hardware requirement for efficient memeory access

    for (int i = 0; i < 3; i++) {
        cout << "global_array[" << i << "] @ " << &global_array[i]
             << " value: " << global_array[i] << endl;
    }

    cout << "\n===== STACK (locals) =====" << endl;
    int local_main = 42;
    cout << "local_main @ " << &local_main << " value: " << local_main << endl;

    cout << "\n===== HEAP (malloc) =====" << endl;
    int* arr_malloc = (int*) malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) arr_malloc[i] = i + 1;
    for (int i = 0; i < 5; i++) {
        cout << "arr_malloc[" << i << "] @ " << &arr_malloc[i]
             << " value: " << arr_malloc[i] << endl;
    }
    // don’t forget to free malloc
    free(arr_malloc);

    cout << "\n===== HEAP (new) =====" << endl;
    int* arr_new = new int[5];
    for (int i = 0; i < 5; i++) arr_new[i] = (i + 1) * 10;
    for (int i = 0; i < 5; i++) {
        cout << "arr_new[" << i << "] @ " << &arr_new[i]
             << " value: " << arr_new[i] << endl;
    }
    delete[] arr_new;

    cout << "\n===== STACK (recursion demo) =====" << endl;
    recurse(10);

    cout << "\n===== ASCII MEMORY MAP =====" << endl;
    cout << "[ Data/Globals ] -> [ Heap grows upward ] .... [ Stack grows downward ]" << endl;
    cout << "    ^ global_var @ " << &global_var << endl;
    cout << "    ^ arr_new/malloc near here" << endl;
    cout << "                                v stack frames (see recursion output)" << endl;

    return 0;
}
