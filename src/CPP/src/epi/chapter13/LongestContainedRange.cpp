#include "LongestContainedRange.hpp"

#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::vector;
using std::unordered_set;
using std::max;
using std::runtime_error;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter13 {
    int LongestContainedRange::longestContainedRange(const vector<int> &array) {
        unordered_set<int> arrayEntries(array.begin(), array.end());

        int maxLen = 0;
        while (!arrayEntries.empty()) {
            int entry = *arrayEntries.begin();
            arrayEntries.erase(entry);

            int lowerBound = entry;
            while (arrayEntries.count(lowerBound - 1)) {
                arrayEntries.erase(--lowerBound);
            }

            int upperBound = entry;
            while (arrayEntries.count(upperBound + 1)) {
                arrayEntries.erase(++upperBound);
            }

            maxLen = max(maxLen, upperBound - lowerBound + 1);
        }

        return maxLen;
    }

    bool LongestContainedRange::test() {
        vector<int> array1 = {10,5,3,11,6,100,4};
        int res1 = longestContainedRange(array1);
        if (res1 != 4) {
            cout << "Should be 4" << endl;
            cout << "Result " << res1 << endl;
            return false;
        }

        vector<int> array2 = {3,-2,7,9,8,1,2,0,-1,5,8};
        int res2 = longestContainedRange(array2);
        if (res2 != 6) {
            cout << "Should be 6" << endl;
            cout << "Result " << res2 << endl;
            return false;
        }

        return true;
    }

  } // chapter13
} // epi
