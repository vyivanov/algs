#include "tools.hpp"
#include "tpool.hpp"

namespace {

void allocate_on_stack()
{
    TEST();

    try {
        const alg::adt::thread_pool pool_0 {0};
    }
    catch (const std::invalid_argument& /* ex */) {
        ;;;
    }
    const alg::adt::thread_pool pool_5 {5};
    const alg::adt::thread_pool pool_9 {9};
}

void allocate_on_heap()
{
    TEST();

    try {
        const auto pool_0 = std::make_unique<alg::adt::thread_pool>(0);
    }
    catch (const std::invalid_argument& /* ex */) {
        ;;;
    }
    const auto pool_5 = std::make_unique<alg::adt::thread_pool>(5);
    const auto pool_9 = std::make_unique<alg::adt::thread_pool>(9);
}

void nop_execution()
{
    // alg::adt::thread_pool pool_0 {0};
    // strong_assert(pool_0.push())
}

}

namespace alg::adt::test {

void tpool()
{
    ::allocate_on_stack();
    ::allocate_on_heap();
}

}
