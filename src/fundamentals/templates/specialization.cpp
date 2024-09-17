#include <iostream>

// Generic template function to compare two values of any type T
// Returns true if a is greater than b
template <typename T>
bool compare(T a, T b) {
    return a > b;
}

// Specialized template function for float type
// This function does the same comparison but is specialized for floats
template<>
bool compare<float>(float a, float b) {
    return a > b;
}

int main() {
    // Test the compare function with float values
    // Expected output: 1 (true), because 7.0f > 6.9f
    std::cout << "Comparison Result: " << compare(7.0f, 6.9f) << std::endl;

    return 0;
}
