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
#include <string_view>

#define sync_cout std::osyncstream(std::cout)

using namespace std::chrono_literals;

int main() {

    sync_cout << "Starting main threads...\n";

    std::this_thread::sleep_for(2s);
    std::cerr << "Tomorrow home work!" << std::endl;
    std::this_thread::sleep_for(2s);

    sync_cout << "Main thread is exiting...\n";

    return 0; 
}
