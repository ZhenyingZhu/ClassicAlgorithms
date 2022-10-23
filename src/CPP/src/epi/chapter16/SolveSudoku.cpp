#include "SolveSudoku.hpp"

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
  namespace chapter16 {
    bool SolveSudoku::isValid(vector<vector<int>> &partialSudoku, size_t x, size_t y, int val) {
        for (size_t i = 0; i != TOTALSIZE; ++i) {
            if (val == partialSudoku[i][y]) {
                return false;
            }
        }

        for (size_t j = 0; j != TOTALSIZE; ++j) {
            if (val == partialSudoku[x][j]) {
                return false;
            }
        }

        size_t gridX = x / GRIDSIZE, gridY = y / GRIDSIZE;
        for (size_t i = gridX * GRIDSIZE; i != gridX * GRIDSIZE + GRIDSIZE; ++i) {
            for (size_t j = gridY * GRIDSIZE; j != gridY * GRIDSIZE + GRIDSIZE; ++j) {
                if (val == partialSudoku[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool SolveSudoku::solveSudokuHelper(vector<vector<int>> &partialSudoku, size_t x, size_t y) {
        if (y == TOTALSIZE) {
            y = 0;
            ++x;
        }
        if (x == TOTALSIZE)
            return true;

        if (partialSudoku[x][y] != EMPTY)
            return solveSudokuHelper(partialSudoku, x, y + 1);

        for (int val = 1; val <= TOTALSIZE; ++val) {
            if (!isValid(partialSudoku, x, y, val))
                continue;

            partialSudoku[x][y] = val;
            if ( solveSudokuHelper(partialSudoku, x, y + 1) ) {
                return true;
            } else {
                partialSudoku[x][y] = EMPTY;
            }
        }

        return false;
    }

    bool SolveSudoku::solveSudoku(vector<vector<int>> &partialSudoku) {
        assert(partialSudoku.size() == TOTALSIZE && partialSudoku[0].size() == TOTALSIZE);
        return solveSudokuHelper(partialSudoku, 0, 0);
    }

    bool SolveSudoku::test() {
        vector<vector<int> > sudoku = {
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

        if (!solveSudoku(sudoku)) {
            cout << "Should be solveable" << endl;
            for (vector<int> &line : sudoku) {
                cout << vec_to_string(line) << endl;
            }

            return false;
        }

        return true;
    }

  } // chapter16
} // epi
