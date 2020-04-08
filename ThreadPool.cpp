#include "ThreadPool.hpp"

// the destructor joins all threads
ThreadPool::~ThreadPool()
{
    this->stopAll();

    this->joinAll();
}

void ThreadPool::stopAll()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
}

void ThreadPool::joinAll()
{
    for (std::thread& worker : workers)
    {
        if(worker.joinable())
        {
            worker.join();
        }
    }
}
