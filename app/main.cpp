#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void pointerTest() {
    cout << "START POINTER TUTORIALS \n" << endl;

    int n = 5;

    cout << &n << endl;

    int *ptr = &n;

    cout << *ptr << endl;

    *ptr = 10;

    cout << *ptr << endl;

    cout << n << endl;

    int v;
    int *ptr2 = &v;
    *ptr2 = 30;

    cout << *ptr2 << endl;

    cout << "END POINTER TUTORIALS" << endl;
}

int main() {
    pointerTest();

    return 0;
}