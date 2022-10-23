#include "IsPatternContainedInGrid.hpp"

#include <vector>
#include <unordered_set>
#include <tuple>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::unordered_set;
using std::tuple;
using std::get;
using std::hash;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter17 {
    struct IsPatternContainedInGrid::TupleHash {
        size_t operator() (const tuple<int, int, Offset> &intTuple) const {
            return hash<int>()(get<0>(intTuple) ^ 1021 * get<1>(intTuple) ^ 1048573 * get<2>(intTuple));
        }
    };

    bool IsPatternContainedInGrid::patternChecker(int x, int y, Offset offset,
            const vector<vector<int>> &grid, const vector<int> &pattern,
            unordered_set<tuple<int, int, Offset>, TupleHash> &failedCells) {
        if (offset == (int)pattern.size())
            return true;

        if (x < 0 || x >= (int)grid.size() || y < 0 || y >= (int)grid[0].size())
            return false;

        tuple<int, int, Offset> intTuple{x, y, offset};
        if (failedCells.find(intTuple) != failedCells.end())
            return false;

        if (grid[x][y] != pattern[offset] ||
           ( !patternChecker(x - 1, y, offset + 1, grid, pattern, failedCells) &&
             !patternChecker(x + 1, y, offset + 1, grid, pattern, failedCells) &&
             !patternChecker(x, y - 1, offset + 1, grid, pattern, failedCells) &&
             !patternChecker(x, y + 1, offset + 1, grid, pattern, failedCells) )
        ) {
            failedCells.emplace(intTuple);
            return false;
        }

        return true;
    }

    bool IsPatternContainedInGrid::isPatternContainedInGrid(const vector<vector<int>> &grid, const vector<int> &pattern) {
        unordered_set<tuple<int, int, Offset>, TupleHash> failedCells;
        return patternChecker(0, 0, 0, grid, pattern, failedCells);
    }

    bool IsPatternContainedInGrid::test() {
        vector<vector<int>> grid = {
                {1, 2, 3},
                {3, 4, 5},
                {5, 6, 7}
        };
        vector<int> pattern = {1, 3, 4, 6};

        if ( !isPatternContainedInGrid(grid, pattern) ) {
            cout << "Should able to find" << endl;

            return false;
        }

        return true;
    }

  } // chapter17
} // epi
