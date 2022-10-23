#include "InterconvertIntStr.hpp"

#include <string>
#include <iostream>
#include <stdexcept>
#include <climits>
#include <algorithm>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::reverse;
using std::vector;
using std::invalid_argument;

namespace epi {
  namespace chapter7 {
    string InterconvertIntStr::intToString(int x) {
        if (x == 0)
            return "0";

        if (x == INT_MIN)
            return "-2147483648";

        string res("");

        bool isNegative(false);
        if (x < 0) {
            isNegative = true;
            x = -x; // INT_MIN cannot convert due to overflow
        }

        do {
            res += x % 10 + '0';
            x /= 10;
        } while (x);

        if (isNegative)
            res += '-';

        reverse(res.begin(), res.end());

        return res;
    }

    int InterconvertIntStr::stringToInt(const string &s) {
        if (s == "-2147483648")
            return INT_MIN; // will overflow when -x

        int res = 0;

        string::const_iterator iter = s.begin();

        bool isNegative(false);
        if (*iter == '-') {
            isNegative = true;
            ++iter;
        }

        for (; iter != s.end(); ++iter) {
            res = res * 10 + (*iter - '0');
            if (res < 0)
                throw invalid_argument("Input overflow.");
        }

        return isNegative ? -res: res;
    }

    bool InterconvertIntStr::test() {
        vector<int> vec = {0, -10, 123, INT_MAX, INT_MIN};
        for (int i : vec) {
            string res = intToString(i);
            if (stringToInt(res) != i) {
                cout << "input is: " << i << endl;
                cout << "Converted string is: " << res  << endl;
                cout << "Convert back is: " << stringToInt(res) << endl;
                return false;
            }
        }

        return true;
    }


  } // chapter7
} // epi
