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
#include <functional>
#include <memory>

std::mutex mtx;
uint32_t counter{};

void function_throws() { throw std::runtime_error("Error"); }

int main() {
    
    auto worker = []() {
        for (int i = 0; i < 1000000; ++i) { 
            mtx.lock();
            counter++;
            mtx.unlock();
        }
    };

    auto worker_exceptions = []() {
        for (int i = 0; i < 1000000; ++i) {
            try {
                std::lock_guard<std::mutex> lock(mtx);
                counter++;
                function_throws();
            } catch(std::system_error& e) {
                std::cout << e.what() << std::endl;
                return;
            } catch(...) {
                return;
            }
        }
    };

    std::thread t1(worker_exceptions);
    std::thread t2(worker);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}
