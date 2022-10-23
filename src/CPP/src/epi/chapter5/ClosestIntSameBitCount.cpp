#include "../../epi/chapter5/ClosestIntSameBitCount.hpp"

#include <iostream>
#include <stdexcept>

#include "../../SmartPtr.h"
#include "../../SolutionCollection.h"

using std::invalid_argument;

namespace epi {
namespace chapter5 {
    size_t ClosestIntSameBitCount::countBit(unsigned long x) {
        size_t res(0);
        while (x) {
            x &= x - 1;
            ++res;
        }

        return res;
    }

    unsigned long ClosestIntSameBitCount::closestIntBruteForce(unsigned long x) {
        if (x == 0 || ~x == 0)
            throw invalid_argument("All bits are 0 or 1.");

        unsigned long step(1);
        size_t weight(countBit(x));
        while ( step != (~0UL) ) {
            if ( countBit(x + step) == weight )
                return x + step;
            if ( countBit(x - step) == weight )
                return x - step;
            ++step;
        }

        return x; // Should not happen
    }

    unsigned long ClosestIntSameBitCount::closestIntLinearSearch(unsigned long x) {
        for (int i = 0; i != 31; ++i) {
            if (((x >> i) & 1) != ((x >> (i + 1)) & 1)) {
                unsigned long bit_mask = (1UL << i) | (1UL << (i + 1));
                return x ^= bit_mask;
            }
        }

        throw invalid_argument("All bits are 0 or 1.");
    }

    unsigned long ClosestIntSameBitCount::closestIntSameBitCount(unsigned long x) {
        if (x == 0 || ~x == 0)
            throw invalid_argument("All bits are 0 or 1.");

        unsigned long mask = x ^ (x >> 1);
        mask &= ~(mask - 1); // last bit
        mask |= (mask << 1);

        return x ^ mask;
    }

    bool ClosestIntSameBitCount::test() {
        for (unsigned long x = 0; x != 255UL; ++x) {
            try {
                if ( closestIntSameBitCount(x) != closestIntBruteForce(x) ) {
                    std::cout << closestIntSameBitCount(x) << " "
                              << closestIntBruteForce(x) << std::endl;
                    return false;
                }
            } catch (invalid_argument &ex) {
                std::cout << ex.what() << std::endl;
            }
        }

        return true;
    }

} // chapter5
} // eip
