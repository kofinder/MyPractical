#include <iostream>

// Template class GenericA with no specific behavior (placeholder template)
template<typename T>
struct GenericA {};

// Template class GenericB with two type parameters T and R
template<typename T, typename R>
struct GenericB {};

// Generic template function process() with no specific behavior
template<typename T>
void process() {
    std::cout << "Generic process function template called." << std::endl;
}

// Class MyClass demonstrating various friend declarations
class MyClass {
    // Declare a specific specialization of the process<int> function as a friend
    friend void process<int>();

    // Declare the general template function process<T> as a friend
    template<typename T>
    friend void process();

    // Declare the template class GenericA<T> as a friend
    template<typename T>
    friend struct GenericA;

public:
    // A simple method to demonstrate the class can still have its own members
    void show() {
        std::cout << "MyClass method called." << std::endl;
    }
};

int main() {
    // Demonstrate calling the specialized and generic functions
    process<int>();        // Calls the friend specialization process<int>()
    process<double>();     // Calls the generic template process<T>()

    // Create an instance of MyClass and call its member function
    MyClass obj;
    obj.show();            // Calls the show method of MyClass

    return 0;
}
