#include <iostream>

// Template class BaseClass with a generic member 'x' and a method 'displayValue'
template<typename T>
struct BaseClass {
    T value;

    // A method that displays the value of 'value'
    void displayValue() {
        std::cout << "BaseClass value: " << value << std::endl;
    }
};

// DerivedClass inherits from BaseClass<T> and uses its member 'value' and method 'displayValue'
template<typename T>
struct DerivedClass : BaseClass<T> {
    // Using declarations to make the inherited members visible in DerivedClass
    using BaseClass<T>::value;
    using BaseClass<T>::displayValue;

    // A method in DerivedClass that demonstrates access to 'value' and 'displayValue'
    void showInheritedBehavior() {
        value = 100; // Accessing inherited member 'value'
        displayValue(); // Calling inherited method 'displayValue'
    }
};

int main() {
    // Create an instance of DerivedClass with type int
    DerivedClass<int> derivedObj;

    // Demonstrate inherited functionality
    derivedObj.showInheritedBehavior(); // Calls the method in DerivedClass

    return 0;
}
