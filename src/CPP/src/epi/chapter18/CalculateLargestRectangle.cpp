#include "CalculateLargestRectangle.hpp"

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::stack;
using std::max;
using std::min;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter18 {
    int CalculateLargestRectangle::calculateLargestRectangle(const vector<int> &heights) {
        if (heights.empty() || heights.size() == 1)
            return 0;

        int maxRec = 0;
        stack<size_t> increasingIdx;
        for (size_t i = 0; i != heights.size(); ++i) {
            assert(heights[i] > 0);

            while ( !increasingIdx.empty() && heights[i] < heights[increasingIdx.top()] ) {
                size_t idx = increasingIdx.top();
                increasingIdx.pop();

                int height = heights[idx];
                int width = increasingIdx.empty() ? i : i - increasingIdx.top() - 1;
                maxRec = max(maxRec, height * width);
            }

            increasingIdx.push(i);
        }

        while ( !increasingIdx.empty() ) {
            size_t idx = increasingIdx.top();
            increasingIdx.pop();

            int height = heights[idx];
            int width = increasingIdx.empty() ? heights.size() : heights.size() - increasingIdx.top() - 1;
            maxRec = max(maxRec, height * width);
        }

        return maxRec;
    }

    bool CalculateLargestRectangle::test() {
        vector<int> heights = {1, 4, 2, 5, 6, 3, 2, 6, 6, 5, 3, 1, 3};

        int res = calculateLargestRectangle(heights);
        if (res != 20) {
            cout << "Should be: 20" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter18
} // epi
