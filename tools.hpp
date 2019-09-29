#pragma once

#include <sstream>
#include <iostream>
#include <exception>

#define STRONG_ASSERT(expression, message)  \
    do {                                    \
        if (false == (expression)) {        \
            std::stringstream msg;          \
            msg << "tests:"                 \
                << __FILE__                 \
                << __LINE__                 \
                << __PRETTY_FUNCTION__      \
                << #expression              \
                << message;                 \
            std::clog << msg.str();         \
            std::terminate();               \
        }                                   \
    }                                       \
    while (false)

#define TEST() \
    alg::test entry(__PRETTY_FUNCTION__)

namespace alg {

class test final {
public:
    explicit test(const std::string func) {
        std::clog
            << ++test::count
            << '\x20' << "->"
            << '\x20' << func
        ;
    }
    ~test() {
        std::clog
            << '\x20' << "->"
            << '\n'
        ;
    }
private:
    static inline int count = 0;
};

}
