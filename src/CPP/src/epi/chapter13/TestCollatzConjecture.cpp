#include "TestCollatzConjecture.hpp"

#include <unordered_set>
#include <iostream>
#include <stdexcept>
#include <string>
#include "../../MyUtils.h"

using std::unordered_set;
using std::overflow_error;
using std::to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter13 {
    bool TestCollatzConjecture::testCollatzConjecture(int n) {
        unordered_set<long> verifiedNums;

        for (int i = 3; i <= n; i += 2) {
            unordered_set<long> sequence;
            long cur = i;

            while (cur >= (long)i) {
                if (!sequence.emplace(cur).second) {
                    // found a loop
                    return false;
                }

                if (cur % 2 == 1) {
                    if (!verifiedNums.emplace(cur).second) {
                        // verified, check next i
                        break;
                    }

                    long tmp = cur * 3 + 1;
                    if (tmp <= cur) {
                        throw overflow_error("Overflow " + to_string(cur));
                    }

                    cur = tmp;
                } else {
                    cur /= 2;
                }
            }
        }

        return true;
    }

    bool TestCollatzConjecture::test() {
        if (!testCollatzConjecture(20)) {
            cout << "It is a big science discovery!" << endl;
            return false;
        }

        return true;
    }

  } // chapter13
} // epi
