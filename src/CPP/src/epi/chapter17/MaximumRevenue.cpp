#include "MaximumRevenue.hpp"

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
    int MaximumRevenue::maximumRevenue(const std::vector<int> &coins) {
        int coinSize = coins.size();

        vector<vector<int>> revenues(coinSize, vector<int>(coinSize, 0));
        for (int diag = 0; diag != coinSize; ++diag) {
            for (int cell = 0; cell != coinSize - diag; ++cell) {
                int st = cell, ed = diag + cell;
                if (st == ed) {
                    revenues[st][ed] = coins[st];
                } else if (st + 1 == ed) {
                    revenues[st][ed] = max(coins[st], coins[ed]);
                } else {
                    int pickFirst = coins[st] + min(revenues[st + 2][ed], revenues[st + 1][ed - 1]);
                    int pickLast = coins[ed] + min(revenues[st + 1][ed - 1], revenues[st][ed - 2]);
                    revenues[st][ed] = max(pickFirst, pickLast);
                }
            }
        }

        return revenues[0][coinSize - 1];
    }

    bool MaximumRevenue::test() {
        vector<int> coins1 = {10,25,5,1,10,5};

        int res = maximumRevenue(coins1);

        if ( res != 31 ) {
            cout << "Should be: 31" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        vector<int> coins2 = {25, 5, 10, 5, 10, 5, 10, 25, 1, 25, 1, 25, 1, 25, 5, 10};

        res = maximumRevenue(coins2);

        if ( res != 140 ) {
            cout << "Should be: 140" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter17
} // epi
