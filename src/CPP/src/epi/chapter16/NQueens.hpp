#ifndef SRC_EPI_CHAPTER16_NQUEENS_HPP_
#define SRC_EPI_CHAPTER16_NQUEENS_HPP_

#include "../../Solution.h"

#include <vector>
#include <memory>

namespace epi {
  namespace chapter16 {
    class NQueens : public myutils::Solution {
    public:
        NQueens():
            Solution("EPI Chapter 16.2",
                     "Generate all nonattacking placements of n-Queens",
                     "Use an array to record the positions. Place a queen on "
                     "first column and recursive to check for other columns.") { }

        ~NQueens() { }

        std::vector<std::vector<int>> nQueens(size_t n);

        bool test();

    private:
        bool isValid(const std::vector<int> &colPlacement);

        void solveNQueens(size_t n, size_t row, const std::unique_ptr<std::vector<int>> &colPlacement,
                std::vector<std::vector<int>> &result);

    };

  } // chapter16
} // epi

#endif /* SRC_EPI_CHAPTER16_NQUEENS_HPP_ */
