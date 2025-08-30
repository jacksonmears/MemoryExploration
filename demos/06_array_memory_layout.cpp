#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1,2,3,4,5};

    cout << "Array elements in memory:\n";
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << arr[i]
             << " at " << &arr[i] << "\n";
    }

    return 0;
}
