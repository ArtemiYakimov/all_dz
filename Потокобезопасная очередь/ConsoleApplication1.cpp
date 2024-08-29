#include <iostream>
#include <chrono>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <thread>
#include <functional>
#include <atomic>

template <typename T>
class safe_queue {
private:
    std::queue<T> queue_;
    std::mutex mutex_;
    std::condition_variable cv_;

public:
    void push(const T& task) {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            queue_.push(task);
        }
        cv_.notify_one();
    }

    bool pop(T& task) {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return !queue_.empty(); });
        task = std::move(queue_.front());
        queue_.pop();
        return true;
    }
};

class thread_pool {
private:
    std::vector<std::thread> threads_;
    safe_queue<std::function<void()>> tasks_;

public:
    thread_pool() {
        const auto num_threads = std::thread::hardware_concurrency();
        for (size_t i = 0; i < num_threads; ++i) {
            threads_.emplace_back([this] { work(); });
        }
    }

    ~thread_pool() {
        for (auto& thread : threads_) {
            thread.join();
        }
    }

    template <typename F>
    void submit(F&& f) {
        tasks_.push(std::forward<F>(f));
    }

private:
    void work() {
        while (true) {
            std::function<void()> task;
            if (tasks_.pop(task)) {
                task();
            }
        }
    }
};

void test_function1() {
    std::cout << "test_function1" << std::endl;
}

void test_function2() {
    std::cout << "test_function2" << std::endl;
}

int main() {
    thread_pool pool;

    while (true) {
        pool.submit(test_function1);
        pool.submit(test_function2);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}

