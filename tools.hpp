#pragma once

#include <sstream>
#include <iostream>
#include <exception>

#define STRONG_ASSERT(expression, message)          \
    do {                                            \
        if (false == (expression)) {                \
            std::stringstream msg;                  \
            msg << "\ntests:\x20"                   \
                << __FILE__                         \
                << ":"                              \
                << __LINE__                         \
                << ":\x20"                          \
                << __PRETTY_FUNCTION__              \
                << ":\x20"                          \
                << "Assertion\x20'"                 \
                << #expression                      \
                << "'\x20"                          \
                << "failed.\x20Message:\x20'"       \
                << message                          \
                << "'.";                            \
            std::clog << msg.str() << "\n";         \
            std::terminate();                       \
        }                                           \
    }                                               \
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
