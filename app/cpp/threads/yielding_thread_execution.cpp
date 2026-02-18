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
#include <random>
#include <functional>
#include <syncstream>
#include <memory>

#define sync_cout std::osyncstream(std::cout)

using namespace std::chrono;

//--------------------------------------------------------
// Shared resources
//--------------------------------------------------------
namespace {
    int value = 0;
    std::mutex mtx;
}

int main() {

    //--------------------------------------------------------
    // Thread worker lambda
    //--------------------------------------------------------
    auto lambda_func = [&](const std::string& name) {
        while (true) {
            bool work_to_do = rand() % 2;
            if(work_to_do) {
                sync_cout << name << "working..... \n ";
                std::lock_guard<std::mutex> lock(mtx);

                for(
                    auto start = steady_clock::now(), 
                    now = start; 
                    now < start + 3s;
                    now = steady_clock::now()
                ) {
                    // amazing.... progress
                }
            } else {
                sync_cout << name << "yielding..... \n ";
                std::this_thread::yield();
            }
        }
        
    };

    sync_cout << "Starting threads...\n";

    // Create worker threads (RAII with std::jthread)
    std::jthread t1(lambda_func, "<Thread-1>");
    std::jthread t2(lambda_func, "<Thread-2>");
    
    sync_cout << "Main thred is exixting..... " << std::endl;

    return 0;
}

