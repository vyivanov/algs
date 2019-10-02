#include <ctime>
#include <cmath>
#include <vector>
#include <cstdlib>

namespace alg::randomize {

int random(const int min, const int max)
{
    std::srand(std::time(0));

    const float rand = std::rand();
    const float frac = rand / RAND_MAX;

    const int inc = std::round(frac * (max - min));

    return min + inc;
}

void array(std::vector<int>& a)
{
    const std::size_t size = a.size();

    for (int i = 0; i < size - 1; ++i)
    {
        const int j = random(i, size - 1);
        const int temp = a.at(j);

        a.at(j) = a.at(i);
        a.at(i) = temp;
    }
}

}
