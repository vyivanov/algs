#include "tools.hpp"
#include "randomize.hpp"

#include <vector>

namespace {

void random_range(const int min, const int max)
{
    TEST_CASE();

    for (int i = min; i < max; ++i) {
        const int value = alg::randomize::random(i, max);
        STRONG_ASSERT(i <= value && value <= max, "");
    }
}

void randomize_array()
{
    TEST_CASE();

    std::vector<int> ref;
    for (int i = -1000; i <= +1000; ++i) {
        ref.push_back(i);
    }
    std::vector<int> tbd = ref;

    alg::randomize::array(tbd);
    STRONG_ASSERT(tbd != ref, "");
}

}

namespace alg::randomize::test {

void random()
{
    TEST_SUITE();

    random_range(+1000, +5000);
    random_range(-5000, -1000);
    random_range(-2000, +2000);
}

void array()
{
    TEST_SUITE();

    randomize_array();
}

}
