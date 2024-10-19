#include <iostream>

// Template to add two values
template<typename T>
T add(T a, T b) {
    return a + b;
}

// Template to add three values
template<typename T>
T add(T a, T b, T c) {
    return a + b + c;
}

// Overloaded template with an additional integer constant C
template<int C, typename T>
T add(T a, T b) {
    return a + b + C;
}

int main() {
    // Testing the add method with two parameters
    std::cout << "add(3, 4) ===> " << add(3, 4) << std::endl;          // Output: 7

    // Testing the add method with three parameters
    std::cout << "add(3, 4, 5) ===> " << add(3, 4, 5) << std::endl;    // Output: 12

    // Testing the overloaded add method with a constant C (e.g., C = 10)
    std::cout << "add<10>(3, 4) ===> " << add<10>(3, 4) << std::endl;  // Output: 17

    return 0;
}
