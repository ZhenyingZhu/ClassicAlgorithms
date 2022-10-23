#ifndef SRC_EPI_CHAPTER16_SOLVESUDOKU_HPP_
#define SRC_EPI_CHAPTER16_SOLVESUDOKU_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter16 {
    class SolveSudoku : public myutils::Solution {
    public:
        SolveSudoku():
            Solution("EPI Chapter 16.9",
                     "Implement a Sudoku solver",
                     "Recursive call to try all values and stop when invalid value shows.") { }

        ~SolveSudoku() { }

        bool solveSudoku(std::vector<std::vector<int>> &partialSudoku);

        bool test();

    private:
        const static int GRIDSIZE = 3;

        const static int TOTALSIZE = GRIDSIZE * GRIDSIZE;

        const int EMPTY = 0;

        bool isValid(std::vector<std::vector<int>> &partialSudoku, size_t x, size_t y, int val);

        bool solveSudokuHelper(std::vector<std::vector<int>> &partialSudoku, size_t x, size_t y);

    };

  } // chapter16
} // epi

#endif /* SRC_EPI_CHAPTER16_SOLVESUDOKU_HPP_ */
