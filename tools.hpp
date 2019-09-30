#pragma once

#include <ctime>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <exception>
#include <string_view>

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

#define TEST_SUITE() \
    alg::test_suite __ts__(__PRETTY_FUNCTION__)

#define TEST_CASE() \
    alg::test_case  __tc__(__PRETTY_FUNCTION__)

namespace alg {

class test_suite final {
public:
    explicit test_suite(const std::string_view func) noexcept {
        std::clog
            << ++test_suite::count
            << '\x20' << func
            << '\n';
    }
private:
    static inline int count = 0;
};

class test_case final {
public:
    explicit test_case(const std::string_view func) noexcept {
        std::clog
            << "\x20\x20"
            << ++test_case::count
            << '\x20' << "->"
            << '\x20' << func;
    }
    ~test_case() {
        std::clog
            << '\x20' << "->"
            << '\n';
    }
private:
    static inline int count = 0;
};

inline int random(const int min, const int max)
{
    std::srand(std::time(0));

    const float rand = std::rand();
    const float frac = rand / RAND_MAX;

    const int inc = std::round(frac * (max - min));

    return min + inc;
}

}
