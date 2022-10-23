#ifndef SRC_EPI_CHAPTER12_MATRIXSEARCH_HPP_
#define SRC_EPI_CHAPTER12_MATRIXSEARCH_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter12 {
    class MatrixSearch : myutils::Solution {
    public:
        MatrixSearch():
            Solution("EPI Chapter 12.6",
                     "Search in a 2D sorted array",
                     "Walk from top-right. If larger, "
                     "move left; If smaller, move down.") { }

        ~MatrixSearch() { }

        bool matrixSearch(const std::vector<std::vector<int>> &matrix, int x);

        bool test();

    };

  } // chapter12
} // epi

#endif /* SRC_EPI_CHAPTER12_MATRIXSEARCH_HPP_ */
