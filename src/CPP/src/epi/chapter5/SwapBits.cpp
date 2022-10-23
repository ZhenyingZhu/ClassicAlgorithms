#include "../../epi/chapter5/SwapBits.hpp"

#include <climits>
#include <stdexcept>
#include <iostream>

#include "../../SmartPtr.h"
#include "../../SolutionCollection.h"

using std::invalid_argument;
using std::cout;
using std::endl;

namespace epi {
namespace chapter5 {
    long SwapBits::swapBits(long x, int i, int j) {
        int maxLength = sizeof(x) * CHAR_BIT;
        if (i < 0 || i >= maxLength) {
            throw invalid_argument("Bit position invalid.");
        }
        if (j < 0 || j >= maxLength) {
            throw invalid_argument("Bit position invalid.");
        }

        if (((x >> i) & 1) != ((x >> j) & 1)) {
            unsigned long bit_mask = (1L << i) | (1L << j);
            x ^= bit_mask;
        }

        return x;
    }

    bool SwapBits::test() {
        try {
            swapBits(16, 136, 10);
            return false;
        } catch (invalid_argument &ex) {
            cout << ex.what() << endl;
        }

        if (swapBits(16, 1, 4) == 2 &&
                swapBits(16, 1, 3) == 16)
            return true;

        return false;
    }
} // chapter5
} // eip
