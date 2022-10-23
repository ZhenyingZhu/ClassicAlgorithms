#include "ConvertBase.hpp"

#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <assert.h>

using std::string;
using std::cout;
using std::endl;
using std::invalid_argument;
using std::to_string;
using std::reverse;

namespace epi {
  namespace chapter7 {
    string ConvertBase::constructFromBase(int x, int base) {
        assert (x >= 0);

        string res("");

        do {
            if (x % base < 10)
                res += '0' + x % base;
            else
                res += 'A' + x % base - 10;
            x /= base;
        } while (x);

        reverse(res.begin(), res.end());

        return res;
    }

    string ConvertBase::convertBase(const string &s, int b1, int b2) {
        if (b1 < 2 || b1 > 16)
            throw invalid_argument("base " + to_string(b1) + " is not between 2 and 16.");
        if (b2 < 2 || b2 > 16)
            throw invalid_argument("base " + to_string(b2) + " is not between 2 and 16.");

        const string VALIDSTR("ABCDEF");

        int inputInDecimal(0);

        bool isNagetive(false);

        string::const_iterator iter = s.begin();
        if (*iter == '-') {
            isNagetive = true;
            ++iter;
        }

        for (; iter != s.end(); ++iter) {
            if (isdigit(*iter))
                inputInDecimal = inputInDecimal * b1 + *iter - '0';
            else if (VALIDSTR.find(*iter) != string::npos)
                inputInDecimal = inputInDecimal * b1 + *iter - 'A' + 10;
            else
                throw invalid_argument(s + " include invalid character.");

            if (inputInDecimal < 0)
                throw invalid_argument(s + " is larger than INT_MAX.");
        }

        string res = isNagetive ? "-" + constructFromBase(inputInDecimal, b2) : constructFromBase(inputInDecimal, b2);

        return res;
    }

    bool ConvertBase::test() {
        if (convertBase("-615", 7, 13) != "-1A7") {
            cout << "Convert 615(7) to base 13 is '" << convertBase("-615", 7, 13) << "'" << endl;
            return false;
        }

        return true;
    }

  } // chapter7
} // epi
