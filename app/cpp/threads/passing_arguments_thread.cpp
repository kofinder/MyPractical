/**
 * --------------------------------------------------------------------------------
 * Credit / Remark:
 * This source code was inspired by C++ asynchronous programming books and online
 * examples. Portions of the code (e.g., thread examples, lambda usage) are adapted
 * for learning and practice purposes.
 *
 * Author of this adaptation: Ko Thein
 * Purpose: Practice and demonstration of C++ std::thread, lambdas, function objects,
 *          and member function threading.
 *
 * Note:
 * - Original ideas and examples are not my own.
 * - This code is intended solely for educational purposes.
 *
 * --------------------------------------------------------------------------------
*/

#include <iostream>
#include <thread>
#include <vector>
#include <sstream>
#include <string>


void funcByValue(const std::string& str, int number) {
    std::ostringstream oss;
    oss << "funcByValue: str='" << str << "', number=" << number << "\n";
    std::cout << oss.str();
}

void modifyByValue(std::string& str, int number) {
    str += "Threads";
    number++;

    std::ostringstream oss;
    oss << "modifyByValue: str='" << str << "', number=" << number << "\n";
    std::cout << oss.str();

}

void constReference(const std::vector<int>& vec) {
    std::ostringstream oss;
    oss << "constReference: vector sequence = ";
    for (int x : vec) {
        oss << x << " ";
    }
    oss << "\n";
    std::cout << oss.str();
}

/**
 * --------------------------------------------------------------------------------
 * Demonstration of std::thread argument passing:
 * - Pass by value
 * - Pass by reference (using std::ref)
 * - Pass by const reference
 *
 * Shows why std::ref is needed for references in std::thread.
 * --------------------------------------------------------------------------------
*/

int main() {
    using std::thread;

    int number = 1;
    std::string str = "Passing by value";
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};

    // -----------------------------
    // 1. Pass by value: copies arguments
    // Changes inside funcByValue do NOT affect str or number in main
    thread t1(funcByValue, str, number);

    // -----------------------------
    // 2. Pass by reference: modify original variables
    // need to understand usage of std::ref first:
    // std::ref is a wrapper that allows you to pass a variable by reference
    // to functions like std::thread, std::async, or std::bind, instead of copying it.
    thread t2(modifyByValue, std::ref(str), std::ref(number));

    // -----------------------------
    // 3. Pass by const reference: read-only access
    // Note: no need for std::ref here because const reference binding works automatically for lvalues
    thread t3(constReference, vec);

    // Wait for all threads to finish
    t1.join();
    t2.join();
    t3.join();

    // Check the final values after thread execution
    std::cout << "\nMain thread: str='" << str << "', number=" << number << "\n";

    return 0;
}