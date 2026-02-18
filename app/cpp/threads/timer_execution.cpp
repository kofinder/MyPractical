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

using namespace std::chrono;


template<typename Duration>
class Timer {

    public:

        typedef std::function<void(void)> CallBack;

        Timer(const Duration interval, const CallBack& callback) {
            auto value = duration_cast<milliseconds>(interval);
            sync_cout << "Timer: Starting with interval of" << value << std::endl;

            t = std::jthread([&](std::stop_token stop_token) {
                while (!stop_token.stop_requested()) {
                    sync_cout << "Timer: Running callback" << val.load() << std::endl;
                    val++;
                    callback();
                    sync_cout << "Timer:: Sleeping ...\n";
                    std::this_thread::sleep_for(interval);
                }
                sync_cout << "Timer Exit \n";
            });
        }

        void stop() {
            t.request_stop();
        }

    private:

        std::jthread t;

        std::atomic_char32_t val{0};

};

int main() {

    sync_cout << "Starting main threads...\n";

    Timer timer(1s, [&]() {
        sync_cout << "Callback: Running ..... \n";
    });

    std::this_thread::sleep_for(3s);
    sync_cout << "Main Thread Stop timer \n";
    timer.stop();
    std::this_thread::sleep_for(5000ms);

    sync_cout << "\n Main thread is exiting...\n";

    return 0; 

}
