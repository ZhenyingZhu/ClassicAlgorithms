#include "UniformRandom.hpp"

#include <cmath>
#include <stdexcept>
#include <vector>
#include <iostream>

using std::abs;
using std::invalid_argument;
using std::vector;
using std::cout;
using std::endl;

namespace {
int delta(15);
}

namespace epi {
namespace chapter5 {

int UniformRandom::zeroOneRandom() {
    return rand() % 2;
}

int UniformRandom::uniformRandom(int lower, int upper) {
    if (lower > upper)
        throw invalid_argument(lower + " is larger than " + upper);

    if (lower == upper)
        return lower;

    int range(upper - lower + 1), res;

    do {
        res = 0;
        for (unsigned cover = 1; cover < unsigned(range); cover <<= 1)
            res = (res << 1) | zeroOneRandom();

        res += lower;
    } while (res > upper);

    return res;
}

bool UniformRandom::test() {
    int repeat = 100;
    int lower = -1;
    int upper = 6;

    vector<int> vec;

    for (int i = 0; i != upper -lower + 1; ++i)
        vec.push_back(0);

    for (size_t i = 0; i != unsigned((upper - lower + 1) * repeat); ++i) {
        int res = uniformRandom(lower, upper);
        if (vec[res - lower] == 0)
            cout << " " << res;
        ++vec[res - lower];
    }
    cout << endl;

    for (vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter) {
        if ( abs(*iter - repeat) > delta )
             return false;
    }
    return true;
}

} // chapter5
} // epi
