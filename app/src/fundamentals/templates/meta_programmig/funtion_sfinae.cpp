#include <iostream>
#include <type_traits>

using namespace std; // Using std namespace for convenience

// enable_if implementation: defines 'type' only if 'Condition == true'
template<bool Condition, typename T = void>
struct enable_if {};

// Specialization when 'Condition == true'
template<typename T>
struct enable_if<true, T> {
    using type = T;
};

// Function for signed types
template<typename T>
std::enable_if_t<std::is_signed_v<T>> printSigned(T) {
    cout << "Signed Type\n";
}

// Function for unsigned types
template<typename T>
std::enable_if_t<!std::is_signed_v<T>> printUnsigned(T) {
    cout << "Unsigned Type\n";
}

// Function using enable_if inside function signature
template<typename T>
void printSignedAlt(std::enable_if_t<std::is_signed_v<T>, T>) {
    cout << "Signed Type (Alternative)\n";
}

template<typename T>
void printUnsignedAlt(std::enable_if_t<!std::is_signed_v<T>, T>) {
    cout << "Unsigned Type (Alternative)\n";
}

// Function templates with default integer parameters
template<typename T>
void printSignedWithDefault(T, std::enable_if_t<std::is_signed_v<T>, int> = 0) {
    cout << "Signed Type (With Default)\n";
}

template<typename T>
void printUnsignedWithDefault(T, std::enable_if_t<!std::is_signed_v<T>, int> = 0) {
    cout << "Unsigned Type (With Default)\n";
}

// SFINAE with template parameters
template<typename T, std::enable_if_t<std::is_signed_v<T>, int> = 0>
void handleSigned(T) {
    cout << "Handling Signed Type\n";
}

template<typename T, std::enable_if_t<!std::is_signed_v<T>, int> = 0>
void handleUnsigned(T) {
    cout << "Handling Unsigned Type\n";
}

// Template for adding two numbers
template<typename T, typename R>
decltype(T{} + R{}) addValues(T a, R b) { // Works for types that support `+`
    return a + b;
}

// Specialization for class types
template<typename T, typename R>
std::enable_if_t<std::is_class_v<T>, T> addClassType(T a, R) {  // Works when T is a class type
    return a;
}

struct A {}; // Example class

// Function to handle arrays
template<typename T, int Size>
void processArray(T (&array)[Size]) {
    cout << "Processing array of size: " << Size << '\n';
}

// Function to handle pointers
template<typename T>
std::enable_if_t<std::is_pointer_v<T>> processPointer(T ptr) {
    cout << "Processing pointer\n";
}

int main() {
    // Demonstrate signed and unsigned type handling
    int signedVal = -5;
    unsigned int unsignedVal = 5;

    printSigned(signedVal);         // Output: Signed Type
    printUnsigned(unsignedVal);     // Output: Unsigned Type

    printSignedAlt(signedVal);      // Output: Signed Type (Alternative)
    printUnsignedAlt(unsignedVal);  // Output: Unsigned Type (Alternative)

    printSignedWithDefault(signedVal);    // Output: Signed Type (With Default)
    printUnsignedWithDefault(unsignedVal);// Output: Unsigned Type (With Default)

    handleSigned(signedVal);        // Output: Handling Signed Type
    handleUnsigned(unsignedVal);    // Output: Handling Unsigned Type

    // Demonstrate adding values
    int sum = addValues(10, 20);  // Works for integer addition
    cout << "Sum of 10 + 20: " << sum << '\n';  // Output: Sum of 10 + 20: 30

    // Demonstrate handling a class type
    A a;
    A resultClass = addClassType(a, signedVal);  // Works for class A
    (void)resultClass;  // Suppress unused variable warning

    // Demonstrate processing array
    int array[5] = {1, 2, 3, 4, 5};
    processArray(array);  // Output: Processing array of size: 5

    // Demonstrate processing pointer
    int* ptr = &signedVal;
    processPointer(ptr);  // Output: Processing pointer

    return 0;
}
