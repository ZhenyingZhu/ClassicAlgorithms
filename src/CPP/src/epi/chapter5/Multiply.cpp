#include "../../epi/chapter5/Multiply.hpp"

#include <iostream>

namespace epi {
namespace chapter5 {

    unsigned Multiply::add(unsigned a, unsigned b) {
        unsigned tmpa = a, tmpb = b, k = 1, c = 0, res = 0;
        while (tmpa || tmpb) { // indicate if can stop
            unsigned ak = a & k, bk = b & k; // get current bit
            unsigned tmpc = (ak & bk) | (ak & c) | (bk & c);
            res |= ak ^ bk ^ c;
            c = tmpc << 1;  k <<= 1; tmpa >>= 1; tmpb >>= 1;
        }
        return (res | c);
    }

    unsigned Multiply::multiply(unsigned x, unsigned y) {
        unsigned res = 0;
        while (x) {
            if (x & 1) {
                res = add(res, y);
            }
            x >>= 1; y <<= 1;
        }
        return res;
    }

    bool Multiply::test() {
        for (unsigned i = 0; i != 10; ++i) {
            for (unsigned j = i; j != 10; ++j) {
                if ( multiply(i, j) != i * j ) {
                    std::cout << i << "*" << j << "!=" << multiply(i, j) << std::endl;
                    return false;
                }
            }
        }

        return true;
    }

} // chapter 5
} // eip
