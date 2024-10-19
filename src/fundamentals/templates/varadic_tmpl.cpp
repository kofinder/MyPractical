#include <iostream>
#include <type_traits> // For std::make_unsigned_t

using namespace std;

// Variadic function that accepts multiple arguments
template<typename... TArgs>
void processArguments(TArgs... args) { // Expands the types of the arguments
    // Use decltype to create an array with the same types as args
    // This avoids narrowing conversions
    auto values[] = {static_cast<typename std::common_type<TArgs>::type>(args)...}; // Expands the arguments into an array
}

// BASE CASE for adding two values
template<typename T, typename R>
auto add(T a, R b) {
    return a + b; // Adds two values of potentially different types
}

// RECURSIVE CASE for adding multiple values
template<typename T, typename... TArgs> // Variadic template
auto add(T a, TArgs... args) { // Expands the first argument and remaining arguments
    return a + add(args...); // Recursively adds the first argument to the result of adding the rest
}

// Structure with a member variable and function
struct SampleStruct {
    int v; // Member variable
    int getValue() { return v; } // Function to return the value of v
};

// Function that uses 'add' to sum the results of 'getValue' from multiple SampleStruct instances
template<typename... TArgs>
int sumValues(TArgs... args) {
    return add(args.getValue()...); // Calls 'getValue()' on each argument and sums the results
}

// Function to calculate the square of a value
template<typename T>
T square(T value) { return value * value; }

// Function that adds the squares of multiple arguments
template<typename... TArgs>
auto addSquares(TArgs... args) {
    return add(square(args)...); // Applies 'square()' to each argument before adding
}

// Template function that processes unsigned versions of the arguments
template<typename... TArgs>
int processUnsigned(TArgs... args) {
    // Calls 'g' with the unsigned types of the arguments
    return processArguments<std::make_unsigned_t<TArgs>...>(args...);
}

// Function overloads for different parameter passing methods
template<typename... TArgs>
void passByValue(TArgs... args) {} // Passes arguments by value

template<typename... TArgs>
void passByConstReference(const TArgs&... args) {} // Passes arguments by const reference

template<typename... TArgs>
void passByPointer(TArgs*... args) {} // Passes arguments by pointer

// Function that takes arrays of different sizes
template<int... Sizes>
void handleArrays(int (&...arrays)[Sizes]) {}

int main() {
    // Example usage of the processArguments function
    processArguments(1, 2, 3, 4, 5); // Example call to processArguments

    // Example usage of the add function
    int total = add(10, 20, 30); // Should return 60
    cout << "Sum: " << total << endl;

    // Example usage of the SampleStruct
    SampleStruct a{5};
    SampleStruct b{10};
    int sum = sumValues(a, b); // Should return 15
    cout << "Sum of values: " << sum << endl;

    // Example usage of addSquares
    int squareSum = addSquares(3, 4, 5); // Should return 50 (9 + 16 + 25)
    cout << "Sum of squares: " << squareSum << endl;

    // Example usage of processUnsigned
    processUnsigned(1u, 2u, 3u); // Process unsigned versions of the integers

    return 0;
}
