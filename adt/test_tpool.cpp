#include "tools.hpp"
#include "tpool.hpp"

namespace {

void allocate_on_stack()
{
    TEST();

    const alg::adt::thread_pool pool_1 {1};
    const alg::adt::thread_pool pool_5 {5};
}

void allocate_on_heap()
{
    TEST();

    const auto pool_1 = std::make_unique<alg::adt::thread_pool>(1);
    const auto pool_5 = std::make_unique<alg::adt::thread_pool>(5);
}

void invalid_args()
{
    TEST();

    try {
        const alg::adt::thread_pool pool_0 {0};
    }
    catch (const std::invalid_argument&) {
        ;;;
    }
    catch (...) {
        STRONG_ASSERT(false, "");
    }

    alg::adt::thread_pool pool {10};
    STRONG_ASSERT(pool.push({}) == false, "");
    STRONG_ASSERT(pool.push(nullptr) == false, "");
}

void execute()
{
    TEST();

    int x_1 = 0;
    int x_2 = 0;

    alg::adt::thread_pool pool {5};

    const auto task_1 = [&x_1]() { ++x_1; };
    const auto task_2 = std::bind([](int& var) { ++var; }, std::ref(x_2));

    for (int i = 0; i < 100; ++i) {
        STRONG_ASSERT(pool.push(task_1) == true, "");
        STRONG_ASSERT(pool.push(task_2) == true, "");
    }
}

}

namespace alg::adt::test {

void tpool()
{
    ::allocate_on_stack();
    ::allocate_on_heap();
    ::invalid_args();
    ::execute();
}

}
