#include "RomanToInteger.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

using std::string;
using std::invalid_argument;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter7 {
    int RomanToInteger::romanToInteger(const string &s) {
        if (s.size() == 0)
            return 0;

        const string ROMANCHAR = "IVXLCDM";
        int ROMANNUM[] = {1, 5, 10, 50, 100, 500, 1000};

        int res = 0;
        int size = s.size();

        size_t cur = 0, pre = 0;
        for (int i = 0; i != size; ++i) {
            cur = ROMANCHAR.find(s[i]);
            if (cur == string::npos)
                throw invalid_argument(s + " is not a valid roman number.");

            res += ROMANNUM[cur];

            if (i > 0 && cur > pre)
                res -= 2 * ROMANNUM[pre];

            pre = cur;
        }

        return res;
    }

    bool RomanToInteger::test() {
        string r = "LIX";

        if (romanToInteger("LIX") != 59) {
            cout << romanToInteger("LIX") << endl;
            return false;
        }

        if (romanToInteger("IC") != 99) {
            cout << romanToInteger("IC") << endl;
            return false;
        }

        return true;
    }

  } // chapter7
} // epi
