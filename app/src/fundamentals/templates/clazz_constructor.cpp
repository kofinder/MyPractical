#include <iostream>
#include <vector> // For std::vector
#include <type_traits> // For std::remove_reference_t

// Class MyClassA with two template parameters, T and R
template<typename T, typename R>
struct MyClassA {
    MyClassA(T x, R y) {
        std::cout << "MyClassA<T, R> created with x: " << x << " and y: " << y << std::endl;
    }
};

// Template class MyString with a single template parameter T
template<typename T>
struct MyString {
    MyString(T) {
        std::cout << "MyString<T> created\n";
    }
};

// Template class CTADClass to handle two member variables x and y
template<typename T>
struct CTADClass {
    T x, y;
    CTADClass(T x, T y) : x(x), y(y) {
        std::cout << "CTADClass<T> created with x: " << x << " and y: " << y << std::endl;
    }
};

// Deduction guide for CTADClass
template<typename T>
CTADClass(T, T) -> CTADClass<T>;

// Specialized template class for CTADClass with integer template parameter I
template<int I>
struct CTADSizeClass {
    template<typename T>
    CTADSizeClass(T val) {
        std::cout << "CTADSizeClass<int> created with sizeof(T): " << I << " and value: " << val << std::endl;
    }
};

// Deduction guide for CTADSizeClass based on sizeof(T)
template<typename T>
CTADSizeClass(T) -> CTADSizeClass<sizeof(T)>;

// Another version of CTADClass that uses a universal reference
template<typename T>
struct CTADReferenceClass {
    template<typename R>
    CTADReferenceClass(R&&) {
        std::cout << "CTADReferenceClass<R> created\n";
    }
};

// Deduction guide for CTADReferenceClass using std::remove_reference_t
template<typename R>
CTADReferenceClass(R&&) -> CTADReferenceClass<std::remove_reference_t<R>>;

// Template class Container with an iterator constructor
template<typename T>
struct MyContainer {
    template<typename Iter>
    MyContainer(Iter beg, Iter end) {
        std::cout << "MyContainer<T> created with range\n";
    }
};

// Deduction guide for MyContainer based on the value type of the iterator
template<typename Iter>
MyContainer(Iter beg, Iter end) -> MyContainer<typename std::iterator_traits<Iter>::value_type>;

// Alias template for MyClassA
template<typename T>
using MyAliasB = MyClassA<T, T>;

int main() {
    // Explicit instantiation with int and float
    MyClassA<int, float> a1(2, 4.08);

    // Type deduction for class MyClassA
    MyClassA a2(3, 4.0f);

    // Deduction guide for MyString
    MyString<char const*> s{"abc"}; 

    // Deduction guide for CTADClass with two int values
    CTADClass ct1{1, 3};

    // Deduction guide for CTADSizeClass with sizeof(int)
    CTADSizeClass ct2{1};

    int x = 42;
    CTADReferenceClass ct3{x}; // Uses CTADReferenceClass<R> deduction guide

    // Vector initialization
    std::vector v{1, 2, 3};
    MyContainer c{v.begin(), v.end()}; // MyContainer deduced as MyContainer<int>

    // Alias template for MyClassA
    MyAliasB<int> b{3, 4}; // Construct MyClassA<int, int> through alias

    return 0;
}
