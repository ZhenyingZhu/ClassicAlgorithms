#include "MinimumTotalWaitingTime.hpp"

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::sort;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter18 {
    int MinimumTotalWaitingTime::minimumTotalWaitingTime(vector<int> serviceTimes) {
        sort(serviceTimes.begin(), serviceTimes.end());

        int res = 0, prev = 0;
        for (size_t i = 0; i != serviceTimes.size() - 1; ++i) {
            prev += serviceTimes[i];
            res += prev;
        }

        return res;
    }

    bool MinimumTotalWaitingTime::test() {
        vector<int> serviceTimes = {2, 5, 1, 3};

        int res = minimumTotalWaitingTime(serviceTimes);

        if (res != 10) {
            cout << "Should be: 10" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter18
} // epi
