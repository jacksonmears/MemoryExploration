#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;



int main() {

    vector<int> v = {1, 2, 3, 4, 5};

    auto it = v.end() - 1;
    cout << *it << "\n"; // prints 5


    return 0;
}
