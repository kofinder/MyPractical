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
#include <mutex>
#include <syncstream>
#include <vector>

using namespace std::chrono_literals;

#define sync_cout std::osyncstream(std::cout)


constexpr int NUM_THREADS = 8;
int counter = 0;
int failed = 0;

int main() {

    std::timed_mutex tmutx;
    std::mutex mutx;

    auto worker = [&]() {
        for (int i = 0; i < 10; i++) {
            if(tmutx.try_lock_for(10s)) {
                ++counter;
                sync_cout << "Counter :" << counter << std::endl;
                std::this_thread::sleep_for(10s);

                mutx.unlock();
            } else {
                mutx.lock();

                ++failed;
                sync_cout << "Thread :" << std::this_thread::get_id() << " Failed to lock" << std::endl;

                mutx.unlock();
            }
            std::this_thread::sleep_for(12ms);
        }
    };

    std::vector<std::thread> threads;

    for (int i = 0; i < NUM_THREADS; i++) {
        threads.emplace_back(worker);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Counter: " << counter << "\n";
    std::cout << "Failed: " << failed << "\n";
    return 0;
}
