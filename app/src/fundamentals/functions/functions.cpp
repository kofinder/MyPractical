#include <iostream>
#include <algorithm>
#include <vector>

// Function declarations and overloading practice

// Function with signature (int, char*)
// Example: void fnSignature(int a, char* b);
void fnSignature(int a, char* b); 

// Overloaded function with a const int parameter
// The signature is now (const int, char*), which is different from the original
void fnSignature(const int a, char* b); 

// Overloaded function with a const char* parameter
// The signature is now (int, const char*), which is different from the original
void fnSignature(int a, const char* b); 

// Overloaded function with a different number of parameters
// The signature is (int), which is different from the original
int fnSignature(int a); 

// Overloaded function with a different parameter type
// The signature is (char*), which is different from the original
char fnSignature(char* b); 

// This function declaration will cause a compile error
// because it has the same signature (int, char*) as the first declaration
// but a different return type (char). Functions cannot be overloaded based on return type alone
// char fnSignature(int a, char* b); 


// Function declaration with an integer parameter
void fnX(int);

// Function declaration with a double parameter is explicitly deleted
// This means that any attempt to call fnX with a double argument will cause a compile-time error
void fnX(double) = delete;

// Function declaration with a float parameter
void fnX(float);

// Function to compare two integers for sorting in descending order
// This function can be used with functions like qsort for custom sorting
int descending(const void* a, const void* b) {
    // Cast void pointers to int pointers, then compare the values
    return *((const int*) a) > *((const int*) b);
}

// Function that evaluates a function pointer with two integer arguments
// It takes an integer function pointer and returns the result of calling it with a and b
int eval(int a, int b, int (*f)(int, int)) {
    return f(a, b);
}

// Function to add two integers
// Example: add(5, 3) will return 8
int add(int a, int b) { 
    return a + b; 
}

// Function to subtract two integers
// Example: sub(5, 3) will return 2
int sub(int a, int b) { 
    return a - b; 
}


// Functor to compare two integers for sorting in descending order
// This is an example of a function object (or functor) in C++
struct Descending {
    // Overloaded function call operator
    bool operator()(int a, int b) const { 
        return a > b; // Compare in descending order
    }
};



int main() {

    // Example usage of Descending functor with std::sort
    std::vector<int> values = {4, 2, 3, 1, 5};
    
    // Sort the vector using the Descending functor
    std::sort(values.begin(), values.end(), Descending());

    std::cout << "Sorted values in descending order: ";
    for (int value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;


    int result1 = eval(5, 3, add); // Calls add(5, 3), which returns 8
    int result2 = eval(5, 3, sub); // Calls sub(5, 3), which returns 2

    std::cout << "Result of add: " << result1 << std::endl;
    std::cout << "Result of sub: " << result2 << std::endl;



    // fnX(1);      // OK: calls fnX(int)
    // fnX(1.0);    // Error: fnX(double) is deleted
    // fnX(1.0f);   // OK: calls fnX(float)


    return 0;
}
