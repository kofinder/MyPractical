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
#include <string_view>

#define sync_cout std::osyncstream(std::cout)

using namespace std::chrono_literals;

//--------------------------------------------------------
// Counter class: wraps a thread executing a callback periodically
//--------------------------------------------------------
class Counter {
    using CallBack = std::function<void(void)>;

public:
    /**
     * Constructor: starts a thread that repeatedly executes the provided callback.
     * @param callback Function to run periodically in a separate thread.
     */
    Counter(const CallBack& callback) {
        t = std::jthread([&]() {
            while (running.load()) {
                callback();                       // Execute the callback function
                std::this_thread::sleep_for(1s);  // Simulate periodic work
            }
        });
    }

    /**
     * Request the thread to stop.
     * The thread will exit gracefully after completing the current iteration.
     */
    void stop() { running.store(false); }

private:
    std::jthread t;                  // RAII-managed thread
    std::atomic_bool running{true};  // Atomic flag for cooperative cancellation
};

//--------------------------------------------------------
// Template function to show stop token properties
//--------------------------------------------------------
template <typename T>
void show_stop_props(std::string_view name, const T& stop_item) {
    sync_cout << std::boolalpha
              << name
              << ": stop_possible = " << stop_item.stop_possible()
              << ", stop_requested = " << stop_item.stop_requested()
              << '\n';
}

//--------------------------------------------------------
// Function demonstrating use of std::stop_token
//--------------------------------------------------------
void func_with_stop_token(std::stop_token stop_token) {
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(300ms);

        if (stop_token.stop_requested()) {
            sync_cout << "stop_worker: Stopping as requested\n";
            return;
        }

        sync_cout << "stop_worker: Going back to sleep\n";
    }
}

//--------------------------------------------------------
// Main function demonstrating cooperative thread cancellation
//--------------------------------------------------------
int main() {



    // Counter counter([&]() {  sync_cout << "Call Back Running.... \n"; });
    // std::this_thread::sleep_for(1s);
    // counter.stop();  // Signal the counter thread to stop

    sync_cout << "Starting main threads...\n";

    // Using std::jthread with stop_token
    auto worker1 = std::jthread(func_with_stop_token);
    std::stop_token stop_token = worker1.get_stop_token();
    show_stop_props("stop_token", stop_token);

    worker1.request_stop();    // Signal worker1 to stop
    worker1.join();            // Wait for worker1 to finish
    show_stop_props("stop_token after request", stop_token);

    // Using std::stop_source
    auto worker2 = std::jthread(func_with_stop_token);
    std::stop_source stop_source = worker2.get_stop_source();
    show_stop_props("stop_source", stop_source);

    auto stopper = std::thread([stop_source]() mutable {
        std::this_thread::sleep_for(500ms);
        sync_cout << "Request stop for worker2 via stop_source\n";
        stop_source.request_stop();
    });

    stopper.join();
    std::this_thread::sleep_for(200ms); // Wait a bit to let worker2 react
    show_stop_props("stop_source after request", stop_source);

    sync_cout << "Main thread is exiting...\n";

    return 0; // std::jthread automatically joins threads on destruction
}
