

/**
 * --------------------------------------------------------------------------------
 * Credit / Remark: :
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


// Returning values from a thread
// ------------------------------
// Threads don’t literally return a value like a normal function does — 
// there’s no `return x;` that goes back to the caller.
//
// Instead, there are indirect ways to get data out of a thread:
//
// 1. By reference (using std::ref)
//    → Pass a variable into the thread by reference so the thread can modify it directly.
//
// 2. Using shared data + synchronization (mutex, atomic, etc.)
//    → Useful when multiple threads read/write shared data safely.
//
// 3. Using futures/promises or std::async
//    → A more modern, safer way to get a “return value” from a thread-like task.
//
// In this example, we use the first technique — “returning” a result 
// through a variable passed by reference.

#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <mutex>
#include <chrono>

using namespace std::chrono_literals;

namespace { // anonymous namespace = internal linkage
    int result = 0; // visible only in this .cpp file

    std::mutex mtx;
}

void func(int& result) {
    std::this_thread::sleep_for(1s);
    result = 1 + (rand() % 10);
}

void funcWithMutex() {
    std::this_thread::sleep_for(1s);
    int ret = 1 + (rand() % 10);
    std::lock_guard<std::mutex> lock(mtx);
    result = ret;
}

int main() {
    
    // std::thread t(func, std::ref(result));
    std::thread t(funcWithMutex);
    t.join();

    std::cout << "Result: " << result << std::endl;

    return 0;
}
