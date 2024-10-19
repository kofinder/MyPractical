#include <iostream>

// Generic template class TemplateClass with one template parameter T
template<typename T> 
struct TemplateClass {};

// Template class Container, which accepts a class template (R) as a template parameter
template< template<typename> class R >
struct Container {
    R<int> intMember;      // Member of type R<int>
    R<float> floatMember;  // Member of type R<float>

    void displayMembers() {
        std::cout << "Container holding R<int> and R<float>" << std::endl;
    }
};

// Generic template function that works with any class template that accepts exactly one template parameter
template< template<typename> class R, typename S >
void processTemplate(R<S> obj) {
    std::cout << "processTemplate called with an object of template class R<" << typeid(S).name() << ">" << std::endl;
}

int main() {
    // Create an instance of Container using TemplateClass
    Container<TemplateClass> containerObj;
    containerObj.displayMembers();  // Demonstrates the use of the template members

    // Call processTemplate with an instance of TemplateClass<int>
    processTemplate(TemplateClass<int>());

    return 0;
}
