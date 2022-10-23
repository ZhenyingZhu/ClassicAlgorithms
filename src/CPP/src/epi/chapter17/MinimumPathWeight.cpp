#include "MinimumPathWeight.hpp"

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::min;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter17 {
    int MinimumPathWeight::minimumPathWeight(const vector<vector<int>> &triangle) {
        if (triangle.size() == 0 || triangle[0].size() == 0)
            return 0;

        vector<int> prevMinWeights = {triangle[0][0]};
        for (size_t row = 1; row != triangle.size(); ++row) {
            const vector<int> &thisRow = triangle[row];
            assert(thisRow.size() == row + 1);

            vector<int> currMinWights(thisRow.size(), 0);
            for (size_t col = 0; col != thisRow.size(); ++col) {
                if (col == 0)
                    currMinWights[col] = prevMinWeights[col] + thisRow[col];
                else if (col == thisRow.size() - 1)
                    currMinWights[col] = prevMinWeights[col - 1] + thisRow[col];
                else
                    currMinWights[col] = min(prevMinWeights[col], prevMinWeights[col - 1]) + thisRow[col];
            }

            prevMinWeights = currMinWights; // use swap to same operations
        }

        int min = prevMinWeights[0];
        for (int weight : prevMinWeights) {
            if (weight < min)
                min = weight;
        }

        return min;
    }

    bool MinimumPathWeight::test() {
        vector<vector<int>> triangle = {
                {2},
                {4, 4},
                {8, 5, 6},
                {4, 2, 6, 2},
                {1, 5, 2, 3, 4}
        };

        int res = minimumPathWeight(triangle);

        if ( res != 15 ) {
            cout << "Should be: 15" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter17
} // epi
