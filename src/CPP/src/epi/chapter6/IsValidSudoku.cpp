#include "IsValidSudoku.hpp"

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::invalid_argument;
using std::to_string;
using std::sqrt;

namespace epi {
  namespace chapter6 {
    bool IsValidSudoku::hasDuplicate(const std::vector< std::vector<int> > &partialAssignment,
                                     int startLine, int endLine,
                                     int startRow, int endRow) {
        deque<bool> isPresent(partialAssignment.size() + 1, false);

        for (int i = startLine; i != endLine; ++i) {
            for (int j = startRow; j != endRow; ++j) {
                int val = partialAssignment[i][j];
                if (val < 0 || val > 9)
                    throw invalid_argument("Invalid cell value " + to_string(val));

                if (val == 0)
                    continue;

                if ( isPresent[val] )
                    return true;

                isPresent[val] = true;
            }
        }

        return false;
    }

    bool IsValidSudoku::isValidSudoku(const vector< vector<int> > &partialAssignment) {
        int size = partialAssignment.size();

        // check lines
        for (int i = 0; i != size; ++i) {
            if ( hasDuplicate(partialAssignment, i, i + 1, 0, size) )
                return false;
        }

        // check rows
        for (int j = 0; j != size; ++j) {
            if ( hasDuplicate(partialAssignment, 0, size, j, j + 1) )
                return false;
        }

        // check blocks
        int blockSize = sqrt(size);
        for (int m = 0; m < size; m += blockSize) {
            for (int n = 0; n < size; n += blockSize) {
                if ( hasDuplicate(partialAssignment, m, m + blockSize, n, n + blockSize) )
                    return false;
            }
        }

        return true;
    }

    bool IsValidSudoku::test() {
        vector< vector<int> > validSudoku = {
                {5, 3, 0, 0, 7, 0, 0, 0, 0},
                {6, 0, 0, 1, 9, 5, 0, 0, 0},
                {0, 9, 8, 0, 0, 0, 0, 6, 0},
                {8, 0, 0, 0, 6, 0, 0, 0, 3},
                {4, 0, 0, 8, 0, 3, 0, 0, 1},
                {7, 0, 0, 0, 2, 0, 0, 0, 6},
                {0, 6, 0, 0, 0, 0, 2, 8, 0},
                {0, 0, 0, 4, 1, 9, 0, 0, 5},
                {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };

        vector< vector<int> > invalidSudoku = {
                {5, 6, 0, 0, 7, 0, 0, 0, 0},
                {6, 0, 0, 1, 9, 5, 0, 0, 0},
                {0, 9, 8, 0, 0, 0, 0, 6, 0},
                {8, 0, 0, 0, 6, 0, 0, 0, 3},
                {4, 0, 0, 8, 0, 3, 0, 0, 1},
                {7, 0, 0, 0, 2, 0, 0, 0, 6},
                {0, 6, 0, 0, 0, 0, 2, 8, 0},
                {0, 0, 0, 4, 1, 9, 0, 0, 5},
                {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };

        if ( !isValidSudoku(validSudoku) )
            return false;

        if ( isValidSudoku(invalidSudoku) )
            return false;

        return true;
    }
  } // chapter6
} // epi
