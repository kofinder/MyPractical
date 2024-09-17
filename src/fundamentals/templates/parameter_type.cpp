#include <iostream>
#include <array>

// Template function to print static members of a type
template <typename T>
void printStaticMembers() {
    std::cout << T::x << ", " << T::y << std::endl;
}

// Structure with static members
struct Multi {
    static const int x = 1;
    static constexpr float y = 2.0f;
};

// Template function with integer template parameters
template<int Width, int Height>
void processDimensions() {
    std::cout << "Width: " << Width << ", Height: " << Height << std::endl;
}

// Template function with non-type template parameters before C++17
template<typename Type1, Type1 Width, typename Type2, Type2 Height>
void processSizes() {
    std::cout << "Width: " << Width << ", Height: " << Height << std::endl;
}

// Template function with auto template parameters (C++17 and later)
template<auto Width, auto Height>
void processAutoSizes() {
    std::cout << "Width: " << Width << ", Height: " << Height << std::endl;
}

// Structure with a constexpr constructor
struct A {
    int x;
    constexpr A(int _x) : x{_x} {}
};

// Template function to print the value of a static member of a structure
template<A Value>
void printConstexprMember() {
    std::cout << Value.x << std::endl;
}

// Template function to print elements of a std::array
template<std::array<int, 4> Arr>
void printArrayElement() {
    std::cout << Arr[2] << std::endl;
}

// Template function to print an integer pointed to by a pointer
template<int* Ptr>
void printIntPointer() {
    std::cout << Ptr[0] << std::endl;
}

// Template function to print the first element of an integer array by reference
template<int (&Array)[3]>
void printIntArrayReference() {
    std::cout << Array[0] << std::endl;
}

// Global integer array
int array[] = { 7, 9, 4 };

// Structure with integer member and an integer array member
struct Area {
    int x = 5;
    int y[3] = {4, 2, 3};
};

// Template function to print a member pointer to an integer
template<int Area::*MemberPointer>
void printAreaMember() {
    std::cout << Area{}.*MemberPointer << std::endl;
}

// Template function to print a member pointer to an integer array
template<int (Area::*ArrayPointer)[3]>
void printAreaArrayMember() {
    std::cout << Area{}.*ArrayPointer << std::endl;
}

// Template function to apply a binary operation using a function pointer
template<int (*Operation)(int, int)>
int applyOperation(int a, int b) {
    return Operation(a, b);
}

// Binary operation functions
int add(int a, int b) { 
    return a + b; 
}

int multiply(int a, int b) { 
    return a * b; 
}

// Template function to apply a binary operation using a function type template parameter
template<decltype(add) Operation>
int applyOperationUsingType(int a, int b) {
    return Operation(a, b);
}

int main() {
    // Print static members of the Multi struct
    printStaticMembers<Multi>();

    // Process dimensions using integer template parameters
    processDimensions<5, 10>();

    // Process sizes using non-type template parameters
    processSizes<int, 5, char, 'a'>();

    // Process sizes using auto template parameters
    processAutoSizes<5, 'a'>();

    // Print constexpr member value
    printConstexprMember<A{5}>();

    // Print an element of a std::array
    printArrayElement<std::array<int, 4>{1, 3, 4, 5}>();

    // Print elements of an integer array by pointer and reference
    printIntPointer<array>();
    printIntArrayReference<array>();

    // Print member values of Area struct
    printAreaMember<&Area::x>();
    printAreaArrayMember<&Area::y>();

    // Apply binary operations and print results
    int sum = applyOperation<add>(2, 3); // returns 5
    int product = applyOperationUsingType<multiply>(2, 3); // returns 6

    std::cout << "Sum: " << sum << ", Product: " << product << std::endl;

    return 0;
}
