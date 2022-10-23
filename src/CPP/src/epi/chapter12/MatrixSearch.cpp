#include "MatrixSearch.hpp"

#include <vector>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::vector;
using std::invalid_argument;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter12 {
    bool MatrixSearch::matrixSearch(const vector<vector<int>> &matrix, int x) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            throw invalid_argument("Empty matrix");

        int row = 0, col = matrix[0].size() - 1;
        while (row < (int)matrix.size() && col >= 0) {
            if (matrix[row][col] == x)
                return true;
            else if (matrix[row][col] > x)
                --col;
            else
                ++row;
        }

        return false;
    }

    bool MatrixSearch::test() {
        vector<vector<int>> matrix = {
                {-1, 2, 4, 4, 6},
                {1, 5, 5, 9, 21},
                {3, 6, 6, 9, 22},
                {3, 6, 8, 10, 24},
                {6, 8, 9, 12, 25},
                {8, 10, 12, 13, 40}
        };

        if (matrixSearch(matrix, 7)) {
            cout << "7 should not exist" << endl;
            return false;
        }

        if (!matrixSearch(matrix, 8)) {
            cout << "8 is exist" << endl;
            return false;
        }

        return true;
    }

  } // chapter12
} // epi
