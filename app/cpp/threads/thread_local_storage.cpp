/**
 * --------------------------------------------------------------------------------
 * Credit / Remark:
 * This source code is inspired by C++ asynchronous programming books and online examples.
 * Portions of the code (e.g., thread examples, lambda usage) are adapted for learning and practice.
 *
 * Author of this adaptation: Ko Thein
 * Purpose: Practice and demonstration of C++ std::thread, std::jthread, RAII, function objects,
 *          lambdas, and member function threading with cooperative cancellation.
 *
 * Note:
 * - Original ideas and examples are not my own.
 * - This code is intended solely for educational purposes.
 *
 * --------------------------------------------------------------------------------
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <functional>
#include <syncstream>
#include <memory>
#include <atomic>
#include <exception>
#include <string_view>

#define sync_cout std::osyncstream(std::cout)

using namespace std::chrono_literals;

thread_local int val = 0;

void setValue(int value) { val = value; }

void print() { sync_cout << val << " "; }

void multiplyByTwo(int arg) {
    setValue(arg);
    val *= 2;
    print();
}


int main() {

    sync_cout << "Starting main threads...\n";

    val = 1;
    std::thread t1(multiplyByTwo,  1);
    std::thread t2(multiplyByTwo,  2);
    std::thread t3(multiplyByTwo,  3);

    t1.join();
    t2.join();
    t3.join();

    sync_cout << "\n Main thread is exiting...\n";

    return 0; 
}
