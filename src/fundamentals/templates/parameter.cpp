#include <iostream>

template<typename T>
int add(T a, T b) {
    return a + b;
}

enum class Enum { LEFT, RIGHT };

template<Enum Z>
int add_enum(int a, int b) {
    return (Z == Enum::LEFT) ? a + b : a;
}

template <int DIV, typename T>
T ceil_div(T value) {
    return (value + DIV - 1) / DIV;
}

template<int DIV, typename T>
T round_div(T value) {
    return (value + DIV / 2) / DIV;
}

template <int A = 3, int B = 4>
void printOne() {
    std::cout << "PrintOne Result ===> " << A << "," << B << std::endl;
}

// B is required but A has a default value
template <int A = 3, int B>
void printTwo() {
    std::cout << "PrintTwo Result ===> " << A << "," << B << std::endl;
}

// Function template with a default value for B, which is A + 3
template<int A, int B = A + 3>
void printSum() {
    std::cout << "Value of B: " << B << std::endl;  // Output the value of B
}

// Function template to print the size of type T
template<typename T, int Size = sizeof(T)>
void printSize(T value) {
    std::cout << "Size of type: " << Size << std::endl;  // Output the size of the type T
}


int main() {
    printOne<2, 5>();   // prints 2, 5 (A = 2, B = 5)
    printOne<2>();      // prints 2, 4 (A = 2, B uses default value = 4)
    printOne<>();       // prints 3, 4 (A, B use default values)
    printOne();         // prints 3, 4 (A, B use default values)
    printTwo<2, 5>();   // prints 2, 5 (A = 2, B = 5)

    // The following will result in compile-time errors:
    // printTwo<2>();  // Error: B is not provided (B has no default value)
    // printTwo<>();   // Error: B is required, no default value is provided
    // printTwo();     // Error: B is required, no default value is provided

    std::cout << "Added Enum Result ===> " << add_enum<Enum::LEFT>(5, 7) << std::endl;
    std::cout << "Added Enum Result ===> " << add_enum<Enum::RIGHT>(8, 9) << std::endl;
    std::cout << "Ceil Division Result ===> " << ceil_div<3>(5) << std::endl;
    std::cout << "Round Division Result ===> " << round_div<3>(5) << std::endl;

    printSum<3>();  // B is 6 (A = 3, B = A + 3)
    printSize(3);   // S is 4 (Size of int is 4 bytes)


    return 0;
}
