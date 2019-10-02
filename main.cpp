#include "adt/test_tpool.hpp"
#include "numeric/test_randomize.hpp"

#include <iostream>

namespace {

class log final {
public:
    log() { std::clog << "---------- START TEST SUITES ----------" << '\n'; }
   ~log() { std::clog << "---------- ENDED TEST SUITES ----------" << '\n'; }
};

}

int main()
{
    log suites;

    alg::randomize::test::random();
    alg::randomize::test::array();
    alg::adt::test::tpool();
}
