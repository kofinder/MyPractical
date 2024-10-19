#include <iostream>
#include <algorithm>
#include <vector>
#include <type_traits>

template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

std::string getCxxVersion() {
    if (__cplusplus == 201703L) {
        return "C++17";
    } else if (__cplusplus == 201402L) {
        return "C++14";
    } else if (__cplusplus == 201103L) {
        return "C++11";
    } else if (__cplusplus == 199711L) {
        return "C++98";
    } else if (__cplusplus == 202002L) {
        return "C++20";
    } else if (__cplusplus == 202300L) {
        return "C++23";
    } else {
        return "Unknown C++ version";
    }
}

// Lambda Expressions:
// []: No variables are captured.
// [=]: Captures all local variables by value.
// [&]: Captures all local variables by reference.
// [var]: Captures a specific variable by value.
// [&var]: Captures a specific variable by reference.
// [var1, &var2]: Captures var1 by value and var2 by reference.
// [=, &var2]: Captures all local variables by value except var2, which is captured by reference.


auto fnLambda() {
    return [](int value){ 
        return value + 4; 
    };
}

int main() {
    std::cout << getCxxVersion() << "\n";

    // Array of integers to be sorted and searched
    int array[] = {7, 2, 5, 1};

    // Lambda expression to compare two integers (used for sorting in descending order)
    auto lambda = [](int a, int b) {
        return a > b; // Compare two integers in descending order
    };

    // Sort the array in descending order using the lambda comparator
    std::sort(array, array + 4, lambda);

    // Print sorted array
    std::cout << "Sorted array in descending order: ";
    for (int value : array) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Example of different lambda capture lists

    // Capture all local variables by value
    int limit = 20;
    auto lambda1 = [=](int value) { 
        // Captures all local variables (like 'limit') by value
        // Changes to 'limit' in the lambda do not affect the original 'limit'
        return value > limit; 
    };

    // Capture all local variables by reference
    auto lambda2 = [&](int value) { 
        // Captures all local variables (like 'limit') by reference
        // Changes to 'limit' in the lambda will affect the original 'limit'
        return value > limit; 
    };

    // Capture a specific variable (limit) by value
    auto lambda3 = [limit](int value) { 
        // Captures 'limit' by value
        // The lambda uses a copy of 'limit', so changes to 'limit' outside the lambda do not affect this copy
        return value > limit; 
    };

    // Capture a specific variable (limit) by reference
    auto lambda4 = [&limit](int value) { 
        // Captures 'limit' by reference
        // The lambda uses the actual 'limit', so changes to 'limit' outside the lambda affect its value in the lambda
        return value > limit; 
    };

    // Capture no variables (this will not compile due to the use of 'limit' inside the lambda without capture)
    auto lambda5 = [](int value) { 
        // This lambda cannot use 'limit' as it is not captured
        // Uncommenting this line will cause a compilation error
        // return value > limit; 
        return value > 0; // Placeholder implementation
    };

    // Use lambda1 to find the first element greater than limit
    auto result = std::find_if(array, array + 4, lambda1);

    // Check if a result was found and print it
    if (result != array + 4) {
        std::cout << "First value greater than " << limit << " is: " << *result << std::endl;
    } else {
        std::cout << "No value greater than " << limit << " found." << std::endl;
    }


    // Capture List - Others Cases

    constexpr int lmt = 5;
    int var1 = 3, var2 = 4;

    auto lambda6 = [](int value) {
        return value > lmt;
    };

    auto lambda7 = [=, &var2]() {
        return var1 > var2;
    };

    // Lambda Express can be composed
    auto lambda8 = [](int value) {
        return value + 4;
    };

    auto lambda9 = [](int value) {
        return value * 2;
    };

    auto composeLambda = [&](int value) {
        return lambda8(lambda9(value));
    };
    
    auto fnLmbda = fnLambda();
    std::cout << fnLmbda(2) << "\n"; // print "6"
    
    // constexpr lambda expression
    auto factorial = [](int value) constexpr {
        int ret = 1;
        for(int i =0; i < value; i ++) {
            ret *= 1;
        };
        return ret;
    };

    //  consteval lambda expresion
    auto mulplity = [](int value) consteval {
        return value * 2;
    };


    // Template lambda expression
    auto tmplLambda = []<typename T>(T value) requires Arithmetic<T> {
        return value * 2;
    };

    std::cout << tmplLambda(3.4) << "\n";


    int var = 0; // Define `var` before using it
    auto mutableLambda = [&]() mutable { var = 3; }; // Capture by reference to modify original
    mutableLambda(); // Invoke lambda
    std::cout << "Let see what is it ==>"<< var << "\n"; // Output the modified value of `var`

    return 0;
}
