#include "../../epi/chapter5/Reverse.hpp"

#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

namespace epi {
namespace chapter5 {
    long long Reverse::reverseBruteForce(int x) {
        int sig = (x < 0) ? -1 : 1;
        string res(to_string(x));
        std::reverse(res.begin(), res.end());
        return atoi(res.c_str()) * sig;
    }

    long long Reverse::reverse(int x) {
        bool is_negative = x < 0;
        long long res = 0, x_remaining = abs(x);

        while (x_remaining) {
            res = res * 10 + x_remaining % 10;
            x_remaining /= 10;
        }

        return is_negative ? -res : res;
    }

    bool Reverse::test() {
        for (int i = -100; i != 101; ++i) {
            if (reverse(i) != reverseBruteForce(i) ) {
                cout << i << " to " << reverse(i) << endl;
                return false;
            }
        }

        if ( reverse(INT_MAX) != 7463847412 ) {
            cout << INT_MAX << " to " << reverse(INT_MAX) << endl;
        }

        return true;
    }
} // chapter5
} // eip
