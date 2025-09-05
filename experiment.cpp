#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main() {
    shared_ptr<void> ptr1 = make_shared<int>(5);
    shared_ptr<void> ptr2 = make_shared<char>('a');

    vector<shared_ptr<void>> dynamic = {ptr1, ptr2};

    // To use them, cast back:
    cout << *static_pointer_cast<int>(dynamic[0]) << "\n";
    cout << *static_pointer_cast<char>(dynamic[1]) << "\n";
}
