#include <iostream>
#include <type_traits>

// C++ Object Layout Overview
// The layout of an object in memory refers to how its data is arranged.
// C++ defines several types of layouts:
// - Aggregate
// - Trivial copyable
// - Standard layout
// - Plain-old data (POD)

// Aggregate Layout
// An aggregate is a struct or class that supports aggregate initialization
// using curly braces syntax {} and must meet specific requirements.

struct Aggregate {
    int x;          // OK: public member
    int y[3];       // OK: arrays are fine
    int z { 3 };    // OK in C++14 and later
    Aggregate() = default; // OK: defaulted constructor
    Aggregate& operator=(const Aggregate&); // OK: assignment operator

private:
    void f() {}    // OK: private function
};

// Non-Aggregate Examples
// These examples do not meet the requirements for aggregate types.

struct NonTrivial {
    NonTrivial() {}  // !! user-provided constructor
    virtual void f() {} // !! virtual function
};

struct Trivial1 {
    Trivial1() = default; // OK: defaulted constructor
    Trivial1(int) {}      // OK: user-defined constructor
    static int x;         // OK: static member
    void f() {}           // OK: function
private:
    int z { 3 };         // OK: private and initialized
};

struct Trivial2 : Trivial1 {
    int arr[3];          // OK: array of trivials is trivial
};

// Standard Layout Examples
// Standard layout types follow specific rules for memory layout.

struct StandardLayout1 {
    StandardLayout1() {} // OK: user-provided constructor
    void f() {}         // OK: non-virtual function
};

class StandardLayout2 : virtual public StandardLayout1 {
    // Use virtual inheritance to avoid ambiguity
    int x, y;           // OK: both are private
    StandardLayout1 z;  // OK: 'z' is not the first data member
};

struct StandardLayout4 : virtual public StandardLayout1, public StandardLayout2 {
    // OK: can use multiple inheritance with virtual inheritance
};

// Example class to test traits
struct A {
    int x;
private:
    int y;
};

int main() {
    // Create instances of each type
    Aggregate agg;
    NonTrivial nonTriv;
    StandardLayout1 stdLayout1;
    StandardLayout4 stdLayout4;

    // Demonstrate their usage
    std::cout << "Aggregate instance created." << std::endl;
    std::cout << "NonTrivial instance created." << std::endl;
    std::cout << "StandardLayout1 instance created." << std::endl;
    std::cout << "StandardLayout4 instance created." << std::endl;

    // Check type traits
    std::cout << "std::is_trivially_copyable_v<A>: " << std::is_trivially_copyable_v<A> << std::endl; // true: A is trivially copyable
    std::cout << "std::is_standard_layout_v<A>: " << std::is_standard_layout_v<A> << std::endl;   // false: A does not have standard layout
    std::cout << "std::is_trivial_v<A> && std::is_standard_layout_v<A>: " 
              << (std::is_trivial_v<A> && std::is_standard_layout_v<A>) << std::endl; // Combined check for POD

    return 0;
}
