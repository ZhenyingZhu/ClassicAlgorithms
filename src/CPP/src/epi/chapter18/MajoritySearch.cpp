#include "MajoritySearch.hpp"

#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::string;
using std::istringstream;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter18 {
    string MajoritySearch::majoritySearch(istringstream *inputStream) {
        string candidate, in;
        int count = 0;
        while (*inputStream >> in) {
            if (count == 0)
                candidate = in;

            if (in == candidate) {
                ++count;
            } else {
                --count;
            }
        }

        return candidate;
    }

    bool MajoritySearch::test() {
        string input = "b a c a a b a a c a";
        istringstream inputStream(input);

        string res = majoritySearch(&inputStream);
        if (res != "a") {
            cout << "Should be: a" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter18
} // epi
