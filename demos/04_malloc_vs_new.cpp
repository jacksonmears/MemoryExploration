#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    // malloc/free (C style)
    int *p1 = (int*)malloc(sizeof(int));
    *p1 = 123;
    cout << "malloc int = " << *p1 << "\n";
    free(p1);

    // new/delete (C++ style)
    int *p2 = new int(456);
    cout << "new int = " << *p2 << "\n";
    delete p2;

    return 0;
}
