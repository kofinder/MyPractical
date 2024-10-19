#include <iostream>

// Base class A with virtual functions
struct A {

    // Virtual function `fx` with a default parameter value of 5
    // If not overridden, this function will print "A::5" when called without arguments
    virtual void fx(int i = 5) {
        std::cout << "A::" << i << std::endl;
    }

    // Virtual function `gx` with no default parameter, meant to be overridden in derived classes
    virtual void gx(int i) {
        std::cout << "A::" << i << std::endl;
    }
};

// Derived class B, inheriting from A
struct B : A {
    int var = 3;

    // Overriding the `fx` function from class A with a different default parameter (3)
    // When called without arguments, it will print "B::3"
    void fx(int i = 3) override {
        std::cout << "B::" << i << std::endl;
    }

    // Overriding the `gx` function from class A
    // Note: Corrected typo with the output operator
    void gx(int i) override {
        std::cout << "B::" << i << std::endl; // Corrected << instead of <
    }
};

int main() {

    A a;
    B b;

    A& a1 = b; // implicit cast UPcasting

    static_cast<A&>(b).fx(); // upcasting
    static_cast<B&>(a).fx(); // downcasting

    std::cout << b.var << std::endl;
    std::cout << static_cast<B&>(a).var << std::endl; // downcasting

    std::cout << typeid(a).name() << std::endl; // print "1A"
    std::cout << typeid(b).name() << std::endl; // print "1B"
    std::cout << typeid(a1).name() << std::endl;

    // Printing the size of class A
    // Since A contains virtual functions, it has a vtable pointer, which contributes to its size
    std::cout << "Check vtable A pointer ===> " << sizeof(A) << std::endl;

    // Printing the size of class B
    // B inherits from A and also has virtual functions, so it has a vtable pointer as well
    std::cout << "Check vtable B pointer ===> " << sizeof(B) << std::endl;

    return 0;
}
