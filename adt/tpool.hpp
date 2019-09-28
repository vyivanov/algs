#include <mutex>
#include <queue>
#include <vector>
#include <thread>
#include <cstddef>
#include <functional>
#include <condition_variable>

namespace alg::adt {

class thread_pool final {

public:

    using task_t = std::function<void()>;

    explicit thread_pool(const std::size_t size) noexcept;
    ~thread_pool();

    thread_pool(const thread_pool& pool) = delete;
    thread_pool(thread_pool&& pool) = delete;

    thread_pool& operator=(const thread_pool& pool) = delete;
    thread_pool& operator=(thread_pool&& pool) noexcept = delete;

    bool push(task_t&& task) noexcept;

private:

    bool m_run;

    std::mutex               m_mtx  ;
    std::condition_variable  m_cv   ;
    std::vector<std::thread> m_pool ;
    std::queue<task_t>       m_tasks;

};

}
