#include "tpool.hpp"

namespace {

void allocate_on_stack()
{
    const alg::adt::thread_pool pool_0 {0};
    const alg::adt::thread_pool pool_5 {5};
    const alg::adt::thread_pool pool_9 {9};
}

void allocate_on_heap()
{
    const auto pool_0 = std::make_unique<alg::adt::thread_pool>(0);
    const auto pool_5 = std::make_unique<alg::adt::thread_pool>(5);
    const auto pool_9 = std::make_unique<alg::adt::thread_pool>(9);
}

}

namespace alg::adt::test {

void tpool()
{
    ::allocate_on_stack();
    ::allocate_on_heap();
}

}
