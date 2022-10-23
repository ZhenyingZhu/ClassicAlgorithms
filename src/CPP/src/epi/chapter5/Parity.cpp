#include "../../epi/chapter5/Parity.hpp"

#include <iostream>
#include <climits>
#include <unordered_map>
#include <stdexcept>

#include "../../SmartPtr.h"
#include "../../SolutionCollection.h"

using std::cout;
using std::endl;
using std::unordered_map;
using std::make_pair;
using std::runtime_error;

using myutils::SmartPtr;
using myutils::SolutionCollection;

namespace epi {
namespace chapter5 {

short Parity::parityBruteForce(unsigned long x) {
    short res = 0;
    while (x) {
        res += x & 1;
        x >>= 1;
    }

    return res % 2;
}

short Parity::parityEliminateLastOne(unsigned long x) {
    short res = 0;
    while (x) {
        res ^= 1;
        x &= x - 1;
    }

    return res;
}

void Parity::computeParity(int length) {
    if (length >= 32 || length <= 0) {
        throw runtime_error("Key length should be between 1 to 31");
    }

    unsigned short maxValue(1U << length);
    for (unsigned short i = 0; i != maxValue; ++i) {
        short parity = parityBruteForce(long(i));
        precomputedParity.insert(make_pair<unsigned short, short>(short(i), short(parity)));
    }
}

short Parity::parityUseCache(unsigned long x, const int length) {
    const unsigned short mask( (1U << length) - 1);

    unsigned short firstPart = x & mask;
    unsigned short secondPart = (x >> length) & mask;
    unsigned short thirdPart = (x >> (2 * length)) & mask;
    unsigned short forthPart = (x >> (3 * length)) & mask;
    return short(precomputedParity[firstPart] ^
            precomputedParity[secondPart] ^
            precomputedParity[thirdPart] ^
            precomputedParity[forthPart]);
}

short Parity::parity(unsigned long x) {
    /* idea: parity of x = parity(first half of x XOR last half of x)
     * unsigned long here is 32 bits, which is same as int.
     * sizeof(long) = sizeof(int) = 4 * sizeof(char)
     * So that if shift 32 at the first time,
     * (x >> 32) == x cause (x ^= x) == 0
     */
    for (size_t i = sizeof(x) * CHAR_BIT / 2; i != 0; i /= 2) {
        x ^= (x >> i);
    }
    return x & 0x1;
}

bool Parity::test() {
    const int length = sizeof(int) * CHAR_BIT / 4;
    computeParity(length);

    for (int x = 0; x != 256; ++x) {
        if ( parityUseCache(x, length) != parityBruteForce(x) )
            return false;
    }

    return true;
}

} // chapter5
} // eip
