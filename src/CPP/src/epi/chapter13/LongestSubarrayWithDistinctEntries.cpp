#include "LongestSubarrayWithDistinctEntries.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <sstream>
#include <queue>
#include <functional>
#include <iostream>
#include <stdexcept>

#include "../../MyUtils.h"

using std::string;
using std::vector;
using std::max;
using std::unordered_map;
using std::unordered_set;
using std::list;
using std::istringstream;
using std::priority_queue;
using std::function;
using std::invalid_argument;
using std::runtime_error;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter13 {
    int LongestSubarrayWithDistinctEntries::longestSubarrayWithDistinctEntries(const vector<int> &array) {
        unordered_map<int, size_t> lastOccurance;
        size_t start = 0, maxLen = 0;

        for (size_t i = 0; i != array.size(); ++i) {
            auto pair = lastOccurance.emplace(array[i], i);
            if (!pair.second) { // the element is already shown
                if (i >= start) {
                    maxLen = max(maxLen, i - start); // previous subarray

                    start = lastOccurance[array[i]] + 1;
                }
                lastOccurance[array[i]] = i;
            }
        }

        return max(maxLen, array.size() - start);
    }

    bool LongestSubarrayWithDistinctEntries::test() {
        vector<int> array = {'f','s','f','e','t','w','e','n','w','e'};

        int res = longestSubarrayWithDistinctEntries(array);
        int ans = 5;

        if (res != ans) {
            cout << "Should be " << ans << endl;
            cout << "Result " << res << endl;
            return false;
        }

        return true;
    }

  } // chapter13
} // epi
