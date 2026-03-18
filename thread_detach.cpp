// Thread Pools
// -Pre-create a pool of worker threads
// -Tasks are submitted to the pool
// -Workers pick tasks and run them like detached threads, but safely
// -Program never crashes because threads are managed centrally
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <iostream>

class ThreadPool {
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable cv;
    bool stop = false;

public:
    ThreadPool(size_t n) {
        for(size_t i=0; i<n; ++i) {
            workers.emplace_back([this]() {
                while(true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(queue_mutex);
                        cv.wait(lock, [this]{ return stop || !tasks.empty(); });
                        if(stop && tasks.empty()) return;
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task(); // execute task safely
                }
            });
        }
    }

    void enqueue(std::function<void()> task) {
        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            tasks.push(task);
        }
        cv.notify_one();
    }

    ~ThreadPool() {
        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            stop = true;
        }
        cv.notify_all();
        for(auto &t : workers) t.join();
    }
};

int main() {
    ThreadPool pool(4);
    pool.enqueue([](){ std::cout << "Background Task 1\n"; });
    pool.enqueue([](){ std::cout << "Background Task 2\n"; });
}



// #include <future>
// #include <iostream>
// int compute(int x) { return x*x; }
// int main() {
//     std::future<int> f = std::async(std::launch::async, compute, 10);
//     std::cout << "Doing other stuff...\n";
//     std::cout << "Result: " << f.get() << "\n";  // waits safely}
