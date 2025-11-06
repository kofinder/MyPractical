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

#include <condition_variable>
#include <mutex>
#include <vector>
#include <iostream>

template <typename T>
class Queue {

   public:

        Queue(std::size_t capacity) : capacity_{capacity}, buffer_(capacity) {}

        void push(const T& item) {
            std::unique_lock<std::mutex> lock(mtx_);
            not_full_.wait(lock, [this] { return !is_full(); });

            buffer_[tail_] = item;
            tail_ = next(tail_);

            lock.unlock();

            not_empty_.notify_one();
        }

        bool try_push(const T& item) {
            std::unique_lock<std::mutex> lock(mtx_, std::try_to_lock);
            if (!lock || is_full()) {
                return false;
            }

            buffer_[tail_] = item;
            tail_ = next(tail_);

            lock.unlock();

            not_empty_.notify_one();

            return true;
        }

        void pop(T& item) {
            std::unique_lock<std::mutex> lock(mtx_);
            not_empty_.wait(lock, [this] { return !is_empty(); });

            item = buffer_[head_];
            head_ = next(head_);

            lock.unlock();

            not_full_.notify_one();
        }

        bool try_pop(T& item) {
            std::unique_lock<std::mutex> lock(mtx_, std::try_to_lock);
            if (!lock || is_empty()) {
                return false;
            }

            item = buffer_[head_];
            head_ = next(head_);

            lock.unlock();

            not_empty_.notify_one();

            return true;
        }

   private:

        [[nodiscard]] std::size_t next(std::size_t idx) const noexcept { return ((idx + 1) % capacity_); }

        [[nodiscard]] bool is_empty() const noexcept { return (head_ == tail_); }

        [[nodiscard]] bool is_full() const noexcept { return (next(tail_) == head_); }

   private:

        std::mutex mtx_;
        std::condition_variable not_empty_;
        std::condition_variable not_full_;

        std::size_t head_{0};
        std::size_t tail_{0};
        std::size_t capacity_;
        std::vector<T> buffer_;
};

int main() {
    Queue<int> q(5);

    // Push and pop normally
    q.push(10);

    int value;

    // pop returns void, so nothing nodiscard here
    q.pop(value);
    std::cout << "Popped value: " << value << "\n";

    // Example where nodiscard matters
    if (q.try_push(20)) {  // try_push returns bool, nodiscard used internally in queue helpers
        std::cout << "Push successful\n";
    } else {
        std::cout << "Push failed\n";
    }

    if (q.try_pop(value)) {  // try_pop returns bool
        std::cout << "Pop successful: " << value << "\n";
    } else {
        std::cout << "Pop failed\n";
    }

    // Compiler warning example
    q.try_push(30); // Warning! return value ignored (if compiler supports nodiscard propagation)
}
