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
class semaphore_queue {
   public:
    semaphore_queue(std::size_t capacity)
        : sem_empty_(capacity), sem_full_(0), capacity_{capacity}, buffer_(capacity) {}

    void push(const T& item) {
        sem_empty_.acquire();

        std::unique_lock<std::mutex> lock(mtx_);

        buffer_[tail_] = item;
        tail_ = next(tail_);

        lock.unlock();

        sem_full_.release();
    }

    bool try_push(const T& item) {
        if (!sem_empty_.try_acquire()) {
            return false;
        }

        std::unique_lock<std::mutex> lock(mtx_);

        buffer_[tail_] = item;
        tail_ = next(tail_);

        lock.unlock();

        sem_full_.release();

        return true;
    }

    void pop(T& item) {
        sem_full_.acquire();

        std::unique_lock<std::mutex> lock(mtx_);

        item = buffer_[head_];
        head_ = next(head_);

        lock.unlock();

        sem_empty_.release();
    }

    bool try_pop(T& item) {
        if (!sem_full_.try_acquire()) {
            return false;
        }

        std::unique_lock<std::mutex> lock(mtx_);

        item = buffer_[head_];
        head_ = next(head_);

        lock.unlock();

        sem_empty_.release();

        return true;
    }

   private:
    [[nodiscard]] std::size_t next(std::size_t idx) const noexcept { return ((idx + 1) % capacity_); }

   private:
    std::mutex mtx_;
    std::counting_semaphore<> sem_empty_;
    std::counting_semaphore<> sem_full_;

    std::size_t head_{0};
    std::size_t tail_{0};
    std::size_t capacity_;
    std::vector<T> buffer_;
};

int main() {
    semaphore_queue<int> q(5);

    // Push an element
    q.push(10);

    // Pop an element
    int value;
    q.pop(value);
    std::cout << "Popped value: " << value << "\n";

    // Try push returns bool
    if (q.try_push(20)) {
        std::cout << "Push succeeded\n";
    } else {
        std::cout << "Push failed\n";
    }

    // Try pop returns bool
    if (q.try_pop(value)) {
        std::cout << "Pop succeeded: " << value << "\n";
    } else {
        std::cout << "Pop failed\n";
    }

    // Ignoring a return value that is nodiscard:
    // auto idx = q.next(0); // correct
    // q.next(0);            // warning if uncommented

    return 0;
}
