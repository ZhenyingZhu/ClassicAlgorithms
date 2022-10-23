#include "NQueens.hpp"

#include <vector>
#include <memory>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::unique_ptr;
using std::abs;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter16 {
    bool NQueens::isValid(const vector<int> &colPlacement) {
        int colId = colPlacement.size() - 1;
        for (int i = 0; i != colId; ++i) {
            if (colPlacement[colId] == colPlacement[i])
                return false;

            if ( abs(colPlacement[colId] - colPlacement[i]) == (colId - i) )
                return false;
        }

        return true;
    }

    void NQueens::solveNQueens(size_t n, size_t row, const unique_ptr<vector<int>> &colPlacement,
            std::vector<std::vector<int>> &result) {
        if (row == n) {
            result.push_back(*colPlacement);
            return;
        }

        for (int col = 0; col != (int)n; ++col) {
            colPlacement->push_back(col);
            if (isValid(*colPlacement))
                solveNQueens(n, row + 1, colPlacement, result);
            colPlacement->pop_back();
        }
    }

    vector<vector<int>> NQueens::nQueens(size_t n) {
        vector<vector<int>> res;
        unique_ptr<vector<int>> ptr(new vector<int>);
        solveNQueens(n, 0, ptr, res);
        return res;
    }

    bool NQueens::test() {
        vector<vector<int>> res = nQueens(4);

        vector<int> ans1 = {1, 3, 0, 2};
        vector<int> ans2 = {2, 0, 3, 1};
        for (vector<int> vec : res) {
            if (vec != ans1 && vec != ans2) {
                cout << "Wrong ans " << endl;
                cout << vec_to_string(vec) << endl;

                return false;
            }
        }

        return true;
    }

  } // chapter16
} // epi
