#include <iostream>
#include <type_traits> // For std::enable_if and std::is_member_function_pointer

// Forward declaration of the Tuple struct template
template<typename... TArgs>
struct Tuple; // Data structure declaration

// Specialization of Tuple for a single parameter (base case)
template<typename T>
struct Tuple<T> { 
    T value; // Holds a single value
};

// Specialization of Tuple for multiple parameters (recursive case)
template<typename T, typename... TArgs>
struct Tuple<T, TArgs...> { 
    T value; // Holds the first value
    Tuple<TArgs...> tail; // Holds the remaining values in a nested Tuple
};

// Structure to retrieve the number of arguments (arity) for function types
template <typename T>
struct GetArity; // Forward declaration for general case

// Specialization for function pointer types
template<typename R, typename... Args>
struct GetArity<R(*)(Args...)> {
    static constexpr int value = sizeof...(Args); // Number of arguments
};

// Specialization for function reference types
template<typename R, typename... Args>
struct GetArity<R(&)(Args...)> {
    static constexpr int value = sizeof...(Args); // Number of arguments
};

// Specialization for function object types
template<typename R, typename... Args>
struct GetArity<R(Args...)> {
    static constexpr int value = sizeof...(Args); // Number of arguments
};

// Overloaded specializations for member function pointers
template<typename R, typename C, typename... Args>
struct GetArity<R(C::*)(Args...)> { // Non-const member function
    static constexpr int value = sizeof...(Args); // Number of arguments
};

template<typename R, typename C, typename... Args>
struct GetArity<R(C::*)(Args...) const> { // Const member function
    static constexpr int value = sizeof...(Args); // Number of arguments
};

// Example class with overloaded operator() functions
struct Functor {
    void operator()(char, char) {} // Non-const operator
    void operator()(char, char) const {} // Const operator
};

// A sample function to demonstrate GetArity usage
void sampleFunction(int, char, double) {}

int main() {
    // Demonstrate the Tuple structure
    Tuple<int, double, char> myTuple; // Create a Tuple instance
    myTuple.value = 42; // Set the first value
    myTuple.tail.value = 3.14; // Set the second value in the nested Tuple
    myTuple.tail.tail.value = 'A'; // Set the third value in the nested Tuple

    // Demonstrate GetArity usage
    std::cout << "Arity of sampleFunction: " << GetArity<decltype(&sampleFunction)>::value << std::endl; // Should print 3
    std::cout << "Arity of Functor::operator(): " << GetArity<decltype(&Functor::operator())>::value << std::endl; // Should print 2

    return 0; // Indicate successful execution
}
