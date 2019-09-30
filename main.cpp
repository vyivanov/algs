#include "adt/test_tpool.hpp"

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
    ::log suites;

    alg::adt::test::tpool();
}
