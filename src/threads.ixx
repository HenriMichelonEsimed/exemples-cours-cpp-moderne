module;
import std;
import examples_inheritance;

export module examples_thread;

using namespace std;
using namespace example;

class Worker
{
public:
    Worker(int count = std::thread::hardware_concurrency())
    {
        count = std::max(1, count);
        for (auto i = 0; i < count; ++i)
        {
            threads.emplace_back([this](std::stop_token token)
            {
                run(token);
            });
        }
    }

    void submit(std::function<void()> task)
    {
        {
            auto l = std::scoped_lock(mutex);
            tasks.push(std::move(task));
        }
        cv.notify_one();
    }

    void stop()
    {
        for (auto& t : threads) {
            t.request_stop();
        }
        for (auto& t : threads) {
            t.join();
        }
    }

private:
    std::queue<std::function<void()>> tasks;
    std::mutex mutex;
    std::vector<std::jthread> threads;
    std::condition_variable_any cv;

    void run(std::stop_token token)
    {
        while (true)
        {
            std::function<void()> task;
            {
                auto lock = unique_lock(mutex);
                cv.wait(lock, token, [this]
                {
                   return !tasks.empty();
                });
                if (tasks.empty()) return;

                task = std::move(tasks.front());
                tasks.pop();
            }
            task();
        }
    }
};



export int exemple_threads() {
    cout << "Hello World!\n";

    Worker worker;
    auto coutLock = mutex{};

    for (auto i = 0; i < 5; ++i)
    {
        worker.submit([i, &coutLock] {
            for (auto j = 0; j < 5; ++j)
            {
                {
                    auto lock = lock_guard(coutLock);
                    cout << std::format("Thread #{} : {}", i, j) << endl;
                }
                this_thread::sleep_for(100ms);
            }
        });
    }
    worker.stop();
/*
    auto v = vector<jthread>{};
    v.reserve(5);

    cout << thread::hardware_concurrency() << endl;


    for (auto i = 0; i < 5; ++i)
    {
        v.emplace_back([i, &coutLock] {
            for (auto j = 0; j < 5; ++j)
            {
                {
                    auto lock = lock_guard(coutLock);
                    cout << std::format("Thread #{} : {}", i, j) << endl;
                }
                this_thread::sleep_for(100ms);
            }
        });
    }
*/
    return 0;
}