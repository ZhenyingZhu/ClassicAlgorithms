#ifndef SRC_EPI_CHAPTER6_ISVALIDSUDOKU_HPP_
#define SRC_EPI_CHAPTER6_ISVALIDSUDOKU_HPP_

#include <vector>

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace epi {
  namespace chapter6 {
    class IsValidSudoku : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        IsValidSudoku():
            Solution("EPI Chapter 6.16",
                     "Sudoku checker program",
                     "Check function pass in start row, end row, start line, end line.") { }

        bool test();

        ~IsValidSudoku() { }

        bool isValidSudoku(const std::vector< std::vector<int> > &partialAssignment);

    private:
        bool hasDuplicate(const std::vector< std::vector<int> > &partialAssignment,
                          int startRow, int endRow,
                          int startLine, int endLine);
    };
  } // chapter6
} // epi

#endif /* SRC_EPI_CHAPTER6_ISVALIDSUDOKU_HPP_ */
