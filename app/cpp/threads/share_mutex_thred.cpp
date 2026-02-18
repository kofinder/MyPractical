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
#include <algorithm>
#include <chrono>
#include <shared_mutex>
#include <syncstream>

using namespace std::chrono_literals;

#define sync_cout std::osyncstream(std::cout)

int counter = 0;

int main() {
    std::shared_mutex smtx;

    auto reader = [&]() {
        for (int i = 0; i < 10; i++) {
            smtx.lock_shared();
            // read the counter and do something
            smtx.unlock_shared();
        }
    };

    auto writer = [&]() {
        for (int i = 0; i < 10; i++) {
            smtx.lock();
            ++counter;
            sync_cout << "Counter : " << counter << std::endl;
            smtx.unlock();
            std::this_thread::sleep_for(10ms);
        }
    };

    std::thread t1(reader);
    std::thread t2(reader);
    std::thread t3(writer); // count increment

    std::thread t4(reader);
    std::thread t5(reader);
    std::thread t6(writer); // count increment

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    std::cout << "Final counter value: " << counter << "\n";
    return 0;
}
