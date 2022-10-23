#include "../../epi/chapter5/Divide.hpp"

#include <iostream>

namespace {
int SIZE = 32;
}

namespace epi {
namespace chapter5 {
    unsigned Divide::divide(unsigned x, unsigned y) {
        unsigned res(0);
        int power = SIZE;
        unsigned long long y_power = static_cast<unsigned long long>(y) << power;

        while (x >= y) {
            while (y_power > x) {
                y_power >>= 1;
                --power;
            }

            res += 1U << power;
            x -= y_power;
        }

        return res;
    }

    bool Divide::test() {
        for (unsigned i = 10; i != 0; --i) {
            for (unsigned j = i; j != 0; --j) {
                if ( (i / j) != divide(i, j) ) {
                    std::cout << i << "/" << j << "=" << divide(i, j) << std::endl;
                    return false;
                }
            }
        }

        return true;
    }
} // chapter5
} // eip
