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
#include <mutex>
#include <syncstream>

int counter = 0; // Shared variable between threads
std::mutex mtx;

#define sync_cout std::osyncstream(std::cout)

void increment(int id) {

    for (int i = 0; i < 10000; i++) {
        mtx.lock();
        counter++;
        mtx.unlock();
    }

    sync_cout << "Thread " << id << " done\n";
}

int main() {
    std::thread t1(increment, 1);
    std::thread t2(increment, 2);
    std::thread t3(increment, 3);
    std::thread t4(increment, 4);
    std::thread t5(increment, 5);
    std::thread t6(increment, 6);
    std::thread t7(increment, 7);
    std::thread t8(increment, 8);



    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    std::cout << "Final counter value: " << counter << "\n";
    return 0;
}
