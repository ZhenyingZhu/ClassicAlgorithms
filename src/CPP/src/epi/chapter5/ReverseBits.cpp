#include "../../epi/chapter5/ReverseBits.hpp"

#include <climits>
#include <unordered_map>

#include "../../SmartPtr.h"
#include "../../SolutionCollection.h"

using std::make_pair;

namespace {
const int SIZE = sizeof(long) * CHAR_BIT / 4; // shorten it to 16 bits
}

namespace epi {
namespace chapter5 {
    void ReverseBits::swapTwoBits(long &x, int i, int j) {
        // This solution comes from chapter 5.2
        if ( (x >> i & 0x1) == (x >> j & 0x1) )
            return;

        long bitMask = (1U << i | 1U << j);
        x ^= bitMask;
    }

    long ReverseBits::reverseBitsBruteForce(long x, int length) {
        for (auto i = 0; i != length / 2; ++i)
            swapTwoBits(x, i, length - 1 - i);

        return x;
    }

    void ReverseBits::computeReverseTable(int length) {
        for (size_t i = 0; i != (1U << length); ++i) {
            precomputedReverse_.insert(
                    make_pair( i, reverseBitsBruteForce(i, length) )
                    );
        }

    }

    long ReverseBits::reverseBits(long x) {

        int keySize = SIZE / 4;
        computeReverseTable(keySize);

        long bitMask = (1U << keySize) - 1;
        long firstPart = precomputedReverse_[x & bitMask];
        long secondPart = precomputedReverse_[(x >> keySize) & bitMask];
        long thirdPart = precomputedReverse_[(x >> 2 * keySize) & bitMask];
        long forthPart = precomputedReverse_[(x >> 3 * keySize) & bitMask];

        return 0 ^ (firstPart << 3 * keySize)
                 ^ (secondPart << 2 * keySize)
                 ^ (thirdPart << keySize)
                 ^ forthPart;
    }

    bool ReverseBits::test() {
        for (long i = 0; i != 32; ++i)
            if ( reverseBits(i) != reverseBitsBruteForce(i, SIZE) )
                return false;

        return true;
    }
} // chapter5
} // eip
