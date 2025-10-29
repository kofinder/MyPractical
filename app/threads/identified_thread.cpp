#include <iostream>
#include <thread>
#include <vector>
#include <syncstream>
#include <chrono>

/**
 * --------------------------------------------------------------------------------
 * Credit / Remark:
 * This source code was inspired by C++ asynchronous programming books and online
 * examples. Portions of the code (e.g., thread examples, lambda usage) are adapted
 * for learning an/d practice purposes.
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


// Define a macro for synchronized console output.
// std::osyncstream (C++20) ensures that multiple threads printing to std::cout
// do not interleave their outputs — each entire message is flushed atomically.
#define sync_cout std::osyncstream(std::cout)

// Make the chrono duration literals (e.g., 1s, 500ms) available
using namespace std::chrono_literals;


/**
 * --------------------------------------------------------------------------------
 * Function: simpleFunc
 *
 * Purpose:
 * Demonstrates how a thread can "sleep" (pause execution) for a given amount of time.
 *
 * Explanation:
 * - std::this_thread::sleep_for() suspends the current thread for at least the
 *   specified duration. It does not guarantee *exact* timing because it depends
 *   on how the operating system schedules threads.
 * - Using 1s (from chrono_literals) means "1 second".
 *
 * Note:
 * The thread that runs this function will sleep for one second before finishing.
 * --------------------------------------------------------------------------------
*/
void simpleFunc() {
    std::this_thread::sleep_for(1s);
}

int main() {

    std::thread t(simpleFunc);
    std::cout << "Thread ID: " << t.get_id() << std::endl;
    t.join();

    return 0;
}