#ifndef SRC_EPI_CHAPTER17_ISPATTERNCONTAINEDINGRID_HPP_
#define SRC_EPI_CHAPTER17_ISPATTERNCONTAINEDINGRID_HPP_

#include "../../Solution.h"

#include <vector>
#include <unordered_set>
#include <tuple>

namespace epi {
  namespace chapter17 {
    class IsPatternContainedInGrid : public myutils::Solution {
    public:
        IsPatternContainedInGrid():
            Solution("EPI Chapter 17.5",
                     "Search for a sequence in a 2D array",
                     "Start from a cell, check if it could be a start of "
                     "a subarray. Use hash table to record previous results.") { }

        ~IsPatternContainedInGrid() { }

        bool isPatternContainedInGrid(const std::vector<std::vector<int>> &grid, const std::vector<int> &pattern);

        bool test();

    private:
        typedef int Offset;

        struct TupleHash;

        bool patternChecker(int x, int y, Offset offset,
                const std::vector<std::vector<int>> &grid, const std::vector<int> &pattern,
                std::unordered_set<std::tuple<int, int, Offset>, TupleHash> &failedCells);

    };

  } // chapter17
} // epi

#endif /* SRC_EPI_CHAPTER17_ISPATTERNCONTAINEDINGRID_HPP_ */
