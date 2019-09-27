#include <mutex>
#include <queue>
#include <thread>
#include <functional>
#include <condition_variable>

namespace alg::adt {

class thread_pool final {

public:

    using task_t = std::function<void()>;

    explicit thread_pool(const std::size_t size);
    ~thread_pool();

    bool push(task_t&& task);

private:

    bool m_run;

    std::mutex               m_mtx;
    std::condition_variable  m_cv;
    std::vector<std::thread> m_pool;
    std::queue<task_t>       m_tasks;

};

}
