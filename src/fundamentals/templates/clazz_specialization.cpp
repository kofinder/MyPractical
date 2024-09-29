#include <iostream>
#include <type_traits>
#include <typeinfo>

// Template class Temp: A generic class that stores a value of type T
template<typename T>
struct Temp { 
    T x = 0;  // Initializes x to 0 (default value for the type)
};

// Overload operator<< for Temp: Defines how Temp objects should be printed
template<typename T>
std::ostream& operator<<(std::ostream& os, const Temp<T>& obj) {
    // Output format includes the type name of T and the value of x
    os << "Temp<" << typeid(T).name() << ">: " << obj.x;
    return os;
}

// Template class TempB: A template class that stores a constant integer N
template<int N>
struct TempB {
    int x = N;  // Initializes x to the template parameter N
};

// Overload operator<< for TempB: Defines how TempB objects should be printed
template<int N>
std::ostream& operator<<(std::ostream& os, const TempB<N>& obj) {
    // Output format includes the value of N (compile-time constant)
    os << "TempB<" << N << ">: " << obj.x;
    return os;
}


// Generic Template: Primary template definition with two type parameters T and R
template<typename T, typename R>
struct GenrericTmpl {
    T x;  // Member variable of type T
    // Function to print the value of x
    void print() { 
        std::cout << "Primary template: T = " << x << std::endl; 
    }
};

// Partial Specialization: Specializes GenrericTmpl when the second type is int
template<typename T>
struct GenrericTmpl<T, int> {
    T y;  // Member variable of type T (y instead of x)
    // Function to print the value of y
    void print() {
        std::cout << "Partial specialization: T = " << y << std::endl; 
    }
};

// Full Specialization: Specializes GenrericTmpl for T = float and R = int
template<>
struct GenrericTmpl<float, int> {
    // Function to print a message for full specialization
    void print() { 
        std::cout << "Full specialization for <float, int>" << std::endl; 
    }
};

// Simple Type Trait: Determines if two types are the same
template<typename T, typename R>
struct is_same {
    static constexpr bool value = false;  // Defaults to false if types are different
};

// Specialization: Sets value to true if both types are the same
template<typename T>
struct is_same<T, T> {
    static constexpr bool value = true;  // True when both T and R are the same type
};

// Type Trait: Checks if a pointer is a constant pointer
template<typename T>
struct is_const_pointer : std::false_type {};  // Default is false for non-const pointers

// Specialization: Sets value to true for const pointers
template<typename R>
struct is_const_pointer<const R*> : std::true_type {};  // True for const pointers


// Example template class A (empty struct for comparison purposes)
template<typename T>
struct A {};

// Template Comparison: Compares two types, defaulting to false
template<typename T, typename R>
struct Compare : std::false_type {};

// Specialization: Compares two instances of the template class A with the same type T
template<typename T, typename R>
struct Compare<A<T>, A<R>> : std::true_type {};


int main() {
    // Instantiating Temp template for different types
    Temp<int> a1;
    Temp<float> a2;
    
    // Instantiating TempB template with different constant values
    TempB<1> b1;
    TempB<2> b2;

    // Displaying the values of Temp and TempB objects
    std::cout << a1 << std::endl;
    std::cout << a2 << std::endl;
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    // Using generic and specialized templates
    GenrericTmpl<double, char> primary;  // Primary template usage
    primary.x = 3.14;
    primary.print();  // Prints: Primary template: T = 3.14

    GenrericTmpl<int, int> partial;  // Partial specialization (R = int)
    partial.y = 42;
    partial.print();  // Prints: Partial specialization: T = 42

    GenrericTmpl<float, int> full;  // Full specialization (T = float, R = int)
    full.print();  // Prints: Full specialization for <float, int>

    // Checking type traits
    std::cout << "is_same<int, char>::value = " << is_same<int, char>::value << std::endl;  // False
    std::cout << "is_same<float, float>::value = " << is_same<float, float>::value << std::endl;  // True

    // Checking if a pointer is a const pointer
    std::cout << "is_const_pointer<int*>::value = " << is_const_pointer<int*>::value << std::endl;  // False
    std::cout << "is_const_pointer<const int*>::value = " << is_const_pointer<const int*>::value << std::endl;  // True

    // Comparing template instances
    std::cout << "Compare<int, float>::value = " << Compare<int, float>::value << std::endl;  // False
    std::cout << "Compare<A<int>, A<int>>::value = " << Compare<A<int>, A<int>>::value << std::endl;  // True
    std::cout << "Compare<A<int>, A<float>>::value = " << Compare<A<int>, A<float>>::value << std::endl;  // True

    return 0;
}
