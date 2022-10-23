#include "NumberOfWays.hpp"

#include <vector>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter17 {
    size_t NumberOfWays::numberOfWays(size_t m, size_t n) {
        if (m == 0 || n == 0)
            return 0;

        vector<vector<size_t>> waysToIJ(m, vector<size_t>(n, 0));
        for (size_t i = 0; i != m; ++i) {
            for (size_t j = 0; j != n; ++j) {
                if (i == 0 || j == 0) {
                    waysToIJ[i][j] = 1;
                    continue;
                }

                size_t fromUp = waysToIJ[i - 1][j];
                size_t fromLeft = waysToIJ[i][j - 1];

                waysToIJ[i][j] = fromUp + fromLeft;
            }
        }

        return waysToIJ[m - 1][n - 1];
    }

    bool NumberOfWays::test() {
        size_t res = numberOfWays(5, 5);

        if (res != 70) {
            cout << "Should be: 70" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter17
} // epi
