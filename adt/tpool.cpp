#include "tpool.hpp"

namespace alg::adt {

thread_pool::thread_pool(const std::size_t size) : m_run(true) {
    for (std::size_t i = 0; i < size; ++i) {
        m_pool.emplace_back(
            [this]() -> void {
                while (true) {
                    const auto& [run, task] = [this]() -> std::pair<bool, task_t> {
                        std::unique_lock<std::mutex> lock {m_mtx};
                        m_cv.wait(lock, [this]() -> bool { return false == m_tasks.empty() || false == m_run; });
                        if (false == m_run) {
                            return {false, task_t()};
                        }
                        const task_t task = m_tasks.front();
                        m_tasks.pop();
                        return {true, task};
                    }();
                    if (run) {
                        if (task) {
                            task();
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        );
    }
}

thread_pool::~thread_pool() {
    {
        std::lock_guard<std::mutex> lock {m_mtx};
        m_run = false;
    }
    m_cv.notify_all();
    for (std::thread& worker: m_pool) {
        worker.join();
    }
}

bool thread_pool::push(task_t&& task) {
    {
        std::lock_guard<std::mutex> lock {m_mtx};
        m_tasks.push(task);
    }
    m_cv.notify_one();
    return true;
}

}
