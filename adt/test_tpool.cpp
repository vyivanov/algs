#include "tpool.hpp"
#include <iostream>
namespace alg::adt::test {

void tpool() {
    alg::adt::thread_pool pool_0(0);
    alg::adt::thread_pool pool_5(5);
    alg::adt::thread_pool pool_9(9);

    for (int i = 0; i < 10; ++i) {
        pool_5.push([i]() { std::cout << i; } );
    }
}

}
