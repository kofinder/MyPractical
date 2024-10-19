#include <iostream>

using namespace std;

// Function template that sums the arguments using unary folding
template<typename... Args>
auto sumUnary(Args... args) { // Variadic template accepting multiple arguments
    return (... + args); // Unary fold: sums all arguments together
}

// Function template that sums the arguments using binary folding
template<typename... Args>
auto sumBinary(Args... args) { // Variadic template accepting multiple arguments
    return (1 + ... + args); // Binary fold: adds 1 to the sum of all arguments
}

int main() {
    // Example usage of sumUnary
    auto unaryResult = sumUnary(1, 2.0f, 3ll); // Returns 6.0f (float)
    cout << "Result of sumUnary: " << unaryResult << endl;

    // Example usage of sumBinary
    auto binaryResult = sumBinary(1, 2.0f, 3ll); // Returns 7.0f (float)
    cout << "Result of sumBinary: " << binaryResult << endl;

    return 0; // Indicate successful execution
}
#include <iostream>

using namespace std;

// Function template that sums the arguments using unary folding
template<typename... Args>
auto sumUnary(Args... args) { // Variadic template accepting multiple arguments
    return (... + args); // Unary fold: sums all arguments together
}

// Function template that sums the arguments using binary folding
template<typename... Args>
auto sumBinary(Args... args) { // Variadic template accepting multiple arguments
    return (1 + ... + args); // Binary fold: adds 1 to the sum of all arguments
}

int main() {
    // Example usage of sumUnary
    auto unaryResult = sumUnary(1, 2.0f, 3ll); // Returns 6.0f (float)
    cout << "Result of sumUnary: " << unaryResult << endl;

    // Example usage of sumBinary
    auto binaryResult = sumBinary(1, 2.0f, 3ll); // Returns 7.0f (float)
    cout << "Result of sumBinary: " << binaryResult << endl;

    return 0; // Indicate successful execution
}
