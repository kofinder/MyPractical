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

void func() {
    for(int i = 10; i < 1000; i++) {
        std::this_thread::sleep_for(500ms);
    }
}

int main() {
    
    std::thread t(func);
    std::thread t2 = std::move(t);
    t2.join();

    return 0;
}
