#include "LongestNondecreasingSubsequenceLength.hpp"

#include <vector>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter17 {
    int LongestNondecreasingSubsequenceLength::findNextIdxOfLastNotGreater(vector<int> &tails, int ed, int value) {
        int st = 0;
        while (st < ed - 1) {
            int md = st + (ed - st) / 2;
            if (tails[md] == value) {
                return md + 1;
            } else if (tails[md] < value) {
                st = md;
            } else {
                ed = md;
            }
        }

        if (tails[st] > value) {
            return st;
        }
        return ed;
    }

    int LongestNondecreasingSubsequenceLength::longestNDSLen(const vector<int> &array) {
        if (array.empty())
            return 0;

        vector<int> tails(array.size(), 0);
        tails[0] = array[0];
        int len = 1;

        for (size_t i = 1; i != array.size(); ++i) {
            if (array[i] >= tails[len - 1]) {
                tails[len++] = array[i];
            } else {
                int idx = findNextIdxOfLastNotGreater(tails, len - 1, array[i]);
                tails[idx] = array[i];
            }
        }

        return len;
    }

    bool LongestNondecreasingSubsequenceLength::test() {
        vector<int> array = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9};
        int res = longestNDSLen(array);

        if (res != 4) {
            cout << "Should be: 4" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter17
} // epi
