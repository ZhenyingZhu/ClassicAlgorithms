#ifndef SRC_EPI_CHAPTER17_MINIMUMPATHWEIGHT_HPP_
#define SRC_EPI_CHAPTER17_MINIMUMPATHWEIGHT_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter17 {
    class MinimumPathWeight : public myutils::Solution {
    public:
        MinimumPathWeight():
            Solution("EPI Chapter 17.8",
                     "Find the minimum weight path in a triangle",
                     "For each row, compute from left to right and record "
                     "the min weight path to this cell in an array.") { }

        ~MinimumPathWeight() { }

        int minimumPathWeight(const std::vector<std::vector<int>> &triangle);

        bool test();

    };

  } // chapter17
} // epi

#endif /* SRC_EPI_CHAPTER17_MINIMUMPATHWEIGHT_HPP_ */
