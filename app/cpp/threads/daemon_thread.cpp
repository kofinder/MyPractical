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

#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

namespace {
    int timeout = 3;
}

void daemondThread() {
    std::cout << "daemon thread starting ...." << std::endl;

    while (timeout-- > 0) {
        std::cout << "daemon thread is running ...." << std::endl;
        std::this_thread::sleep_for(1s);
    }
    
}

int main() {
    
    std::thread t(daemondThread);
    t.detach();

    std::this_thread::sleep_for(std::chrono::seconds(timeout + 1));
    std::cout << "Main thread exixting...." << std::endl;

    return 0;
}
