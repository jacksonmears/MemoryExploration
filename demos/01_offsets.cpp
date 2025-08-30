#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int arr[4] = {10, 20, 30, 40};

    cout << "Array values and addresses in hex:\n";
    for (int i = 0; i < 4; i++) {
        cout << "arr[" << dec << i << "] = " << arr[i] << " at address " << hex << showbase << (uintptr_t)&arr[i] << "\n";
    }

    cout << "\nNotice how each element is offset by sizeof(int) = " << dec << sizeof(int) << " bytes.\n";
    return 0;
}
