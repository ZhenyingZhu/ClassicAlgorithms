#include "../../epi/chapter5/Power.hpp"

#include <cmath>
#include <stdexcept>
#include <iostream>

using std::invalid_argument;
using std::cout;
using std::endl;

namespace epi {
namespace chapter5 {
    double Power::power(double x, int y) {
        if (x == 0.0 && y < 0) {
            throw invalid_argument("0 cannot power with negative.");
        }

        double res = 1.0;
        long long power = y;
        if (y < 0) {
            x = 1.0 / x;
            power = -power;
        }

        while (power) {
            if (power & 1) {
                res *= x;
            }
            x *= x;
            power >>= 1;
        }

        return res;
    }

    bool Power::test() {
        for (int i = -3; i != 4; ++i) {
            double j = 0.0;
            while (j <= 3.0) {
                try {
                    if ( abs(power(j, i) - pow(j, i)) > 0.01 ) {
                        cout << j << "^" << i << "=" << power(j, i) << endl;
                        return false;
                    }
                } catch (invalid_argument &ex) {
                    cout << ex.what() << endl;
                }

                j += 0.5;
            }
        }

        return true;
    }
} // chapter5
} // eip
