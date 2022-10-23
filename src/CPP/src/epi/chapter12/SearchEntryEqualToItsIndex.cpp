#include "SearchEntryEqualToItsIndex.hpp"

#include <vector>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::vector;
using std::length_error;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter12 {
    int SearchEntryEqualToItsIndex::searchEntryEqualToItsIndex(const vector<int> &A) {
        int st = 0, ed = A.size() - 1;

        while (st <= ed) {
            int md = st + (ed - st) / 2;
            if (A[md] == md) {
                return md;
            } else if (A[md] < md) {
                st = md + 1;
            } else {
                ed = md - 1;
            }
        }

        return -1;
    }

    bool SearchEntryEqualToItsIndex::test() {
        vector<int> input = {-2,0,2,3,6,7,9};

        int res1 = searchEntryEqualToItsIndex(input);
        if (res1 != 2 && res1 != 3) {
            cout << "Should be 2 or 3" << endl;
            cout << "Result " << res1 << endl;
            return false;
        }

        return true;
    }

  } // chapter12
} // epi
