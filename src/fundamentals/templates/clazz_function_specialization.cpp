#include <iostream>

// A generic template class with a method to demonstrate function specialization.
template<typename X, typename Y>
struct GenericFunction {
    template<typename T, typename R>
    void execute();
};

// Non-specialized version of the template function.
template<typename X, typename Y>
template<typename T, typename R>
void GenericFunction<X, Y>::execute() {
    std::cout << "Generic execute called with types X, Y, T, R." << std::endl;
}

// Full specialization of the class for `int, int` and partial specialization of the method.
template<>
template<typename X, typename Y>
void GenericFunction<int, int>::execute() {
    std::cout << "Specialized execute called for class GenericFunction<int, int> with generic types X, Y." << std::endl;
}

// Full specialization of both the class and the function for `int, int`.
template<>
template<>
void GenericFunction<int, int>::execute<int, int>() {
    std::cout << "Fully specialized execute called for class GenericFunction<int, int> and function with <int, int>." << std::endl;
}

int main() {
    // Instantiate the generic class and call the methods.

    // 1. Call the generic version of the template function.
    GenericFunction<double, double> genericObj;
    genericObj.execute<float, char>();  // Generic version of execute

    // 2. Call the partially specialized version of the template function for `int, int`.
    GenericFunction<int, int> partiallySpecializedObj;
    partiallySpecializedObj.execute<double, char>();  // Specialized class, generic method

    // 3. Call the fully specialized version of the template function for `int, int`.
    partiallySpecializedObj.execute<int, int>();  // Fully specialized

    return 0;
}
