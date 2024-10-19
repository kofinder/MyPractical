#include <iostream>

// Template class TypeHolder that has a type alias
template<typename T>
struct TypeHolder {
    using type = int; // Alias 'type' is defined as int for any T
};

// Generic function processType() that uses the type alias from TypeHolder
template<typename R>
void processType() {
    using X = typename TypeHolder<R>::type; // 'type' depends on R, resolves to int
    std::cout << "processType called with TypeHolder, X is resolved to int." << std::endl;
}

// Alias template to make type aliasing cleaner
template<typename T>
using TypeAlias = typename TypeHolder<T>::type;

// Reimplementation of the processType function using the alias template
template<typename R>
void processTypeUsingAlias() {
    using X = TypeAlias<R>; // Uses the alias template
    std::cout << "processTypeUsingAlias called using TypeAlias." << std::endl;
}

// Template class Wrapper with an inner function template process
template<typename P>
struct Wrapper {
    template<typename C>
    void process() {
        std::cout << "Wrapper's process method called with type C." << std::endl;
    }
};

// Function f that demonstrates the use of template specialization and dependent names
template<typename P>
void demonstrateTemplateDependence(Wrapper<P> wrapperObj) {
    // The following line would cause a compile error:
    // wrapperObj.process<int>(); // Incorrect because process<int> is a dependent name.

    // The correct way to call the templated function is using the 'template' keyword.
    wrapperObj.template process<int>(); // Correct, using 'template' to indicate it's a templated function
}

int main() {
    // Call processType with a sample type
    processType<double>(); // Calls processType with R = double

    // Call processTypeUsingAlias with a sample type
    processTypeUsingAlias<float>(); // Calls processTypeUsingAlias with R = float

    // Demonstrate the use of dependent names in templates
    Wrapper<int> wrapperObj;
    demonstrateTemplateDependence(wrapperObj); // Calls the process method of Wrapper<int>

    return 0;
}
