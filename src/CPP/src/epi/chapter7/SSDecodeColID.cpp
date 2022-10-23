#include "SSDecodeColID.hpp"

#include <string>
#include <iostream>
#include <stdexcept>
#include <climits>

using std::string;
using std::cout;
using std::endl;
using std::invalid_argument;

namespace epi {
  namespace chapter7 {
    int SSDecodeColID::sSDecodeColID(const string &col) {
        if (col.size() == 0)
            throw invalid_argument("Input string is empty.");

        const string VALIDSTR("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

        int res(0);
        for (string::const_iterator iter = col.begin(); iter != col.end(); ++iter) {
            if (VALIDSTR.find(*iter) == string::npos)
                throw invalid_argument("Input string contains invalid char.");

            res = res * 26 + *iter - 'A' + 1;
            if (res < 0)
                throw invalid_argument("Input string is larger than INT_MAX");
        }

        return res ;
    }

    bool SSDecodeColID::test() {
        if (sSDecodeColID("A") != 1) {
            cout << "A convert to " << sSDecodeColID("A") << endl;
            return false;
        }

        if (sSDecodeColID("ZZ") != 702) {
            cout << "ZZ convert to " << sSDecodeColID("ZZ") << endl;
            return false;
        }

        return true;
    }

  } // chapter7
} // epi
