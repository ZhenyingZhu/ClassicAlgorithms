#include "GetMaxTrappedWater.hpp"

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::max;
using std::min;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter18 {
    int GetMaxTrappedWater::getMaxTrappedWater(const vector<int> &heights) {
        if (heights.empty() || heights.size() == 1)
            return 0;

        int st = 0, ed = heights.size() - 1;
        int maxWater = 0;
        while (st < ed) {
            assert(heights[st] > 0 && heights[ed] > 0);

            int width = ed - st;
            int minHeight = 0;
            if (heights[st] < heights[ed]) {
                minHeight = heights[st++];
            } else if (heights[st] > heights[ed]) {
                minHeight = heights[ed--];
            } else {
                minHeight = heights[st];
                ++st;
                --ed;
            }

            maxWater = max(maxWater, minHeight * width);
        }

        return maxWater;
    }

    bool GetMaxTrappedWater::test() {
        vector<int> heights = {1,2,1,3,4,4,5,6,2,1,3,1,3,2,1,2,4,1};

        int res = getMaxTrappedWater(heights);
        if (res != 48) {
            cout << "Should be: 48" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter18
} // epi
