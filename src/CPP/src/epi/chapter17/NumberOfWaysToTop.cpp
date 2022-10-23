#include "NumberOfWaysToTop.hpp"

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::min;
using std::max;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter17 {
    size_t NumberOfWaysToTop::numberOfWaysToTop(unsigned int top, unsigned int maxStep) {
        vector<size_t> numSteps(top + 1);
        numSteps[0] = 1;

        for (size_t stair = 1; stair <= top; ++stair) {
            for (size_t step = 1; step <= maxStep && step <= stair; ++step) {
                numSteps[stair] += numSteps[stair - step];
            }
        }

        return numSteps[top];
    }

    bool NumberOfWaysToTop::test() {
        int res = numberOfWaysToTop(4, 2);

        if ( res != 5 ) {
            cout << "Should be: 5" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter17
} // epi
