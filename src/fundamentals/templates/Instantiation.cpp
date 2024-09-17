#include <iostream>

template<typename T>
void f(T a) {
    std::cout << "f() called with type: " << typeid(T).name() << std::endl;
}

void g() {
    f(3);            // generates: void f(int) → implicit deduction from argument type
    f<short>(3.0);   // generates: void f(short) → explicit template specialization, short conversion

    // The second call converts 3.0 (double) to short explicitly.
}

// Explicit template instantiation for type int
template void f<int>(int);   // Explicit instantiation of f<int> for type int

int main() {
    g();
    return 0;
}
