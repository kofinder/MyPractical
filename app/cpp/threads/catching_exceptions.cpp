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

std::exception_ptr capture_expection;
std::mutex mtx;

void simpleFunc() {
    try {
        std::this_thread::sleep_for(1s);
        throw std::runtime_error("Error in func used within thread");
    } catch(...) {
        std::lock_guard<std::mutex> lock(mtx);
        capture_expection = std::current_exception();
    }
}

int main() {

    sync_cout << "Starting main threads...\n";
    std::thread t(simpleFunc);

    while (!capture_expection) {
        std::this_thread::sleep_for(2s);
        sync_cout << "In main threads...\n";
    }
    
    try {
        std::rethrow_exception(capture_expection);
    } catch(const std::exception ex) {
        std::cerr << "Exception caught in main thread" << ex.what() << std::endl;
    }

    t.join();
    
    sync_cout << "Main thread is exiting...\n";

    return 0; 
}
