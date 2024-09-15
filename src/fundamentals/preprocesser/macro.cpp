#include <iostream>  // Including the iostream library for input/output operations

// Defining a macro named 'value'. However, it's not assigned any value, 
// and it's not used in this code. Could cause confusion; should be defined or removed.
#define number

// Defining a macro for subtraction. This is incorrect because it doesn't account 
// for operator precedence, which can cause issues when used in complex expressions.
#define SUB(a, b) a - b  // WRONG: No parentheses around arguments, leading to incorrect behavior

// A slight improvement but still wrong. Parentheses added, but it won't fix all issues 
// related to operator precedence when used in complex expressions.
#define SUB2(a, b) (a - b)  // WRONG: Parentheses around the whole expression

// Correct macro definition. Parentheses around the macro parameters ensure 
// that operator precedence is correctly handled in complex expressions.
#define SUB3(a, b) (a) - (b)  // CORRECT: Ensures correct evaluation of expressions

# define MIN(a, b) ((a) < (b) ? (a) : (b))

#include "macro.hpp"
#include "source.hpp"


// Macro does not have scope
void fx() {
    #define value 4
    std::cout << "marco function with assign value ==>" << value << std::endl;
};

int main() {
    std::cout << "Start learning Macro" << std::endl;  // Outputs a string to indicate the start

    // Demonstrating the incorrect behavior of the SUB macro:
    // Expected result: (5) * (2 - 1) = 5 * 1 = 5, but due to lack of parentheses, 
    // it's evaluated as (5 * 2) - 1 = 10 - 1 = 9.
    std::cout << "Evaluated Subtract Macro ===> " << (5) * SUB(2, 1) << std::endl;  // Incorrect output due to operator precedence

    // Demonstrating the behavior of SUB2 macro:
    // Expected result: (3 + 3) - (2 + 2) = 6 - 4 = 2, but it results in 3 because 
    // parentheses are not around the arguments.
    std::cout << "Evaluated Subtract Macro2 ===>" << SUB2(5, 3) << std::endl;  // Incorrect output due to missing parentheses around parameters

    // Correctly using the SUB3 macro:
    // Expected result: (3 + 3) - (2 + 2) = 6 - 4 = 2, which works as intended because 
    // parentheses ensure correct operator precedence.
    std::cout << "Evaluated Subtract Macro3 ===> " << SUB3(9, 3 + 4) << std::endl;  // Correct output because operator precedence is handled

    // Testing the multiply function from macro.hpp:
    // Expected result: multiply(7) adds 3 to the input value, so 7 + 3 = 10.
    std::cout << "Evaluated Assign Macro ===> "<< multiply(7) << std::endl;  // Correct usage of the multiply function
    
    fx();
    std::cout << "Call marco value ==" << value; 


    int array1[] = { 1, 5, 2 };
    int array2[] = { 6, 3, 4 };
    int i = 0;
    int j = 0;
    int v1 = MIN(array1[i++], array2[j++]); // v1 = 5!!
    int v2 = MIN(array1[i++], array2[j++]); 

    std::cout << "Check minimium value of arrays ==" << v1 << std::endl;
    std::cout << "ReCheck minimium value of arrays ==" << v2 << std::endl;


    logger(1);


    return 0;
}
