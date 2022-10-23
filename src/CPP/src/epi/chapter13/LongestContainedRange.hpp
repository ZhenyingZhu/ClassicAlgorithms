#ifndef SRC_EPI_CHAPTER13_LONGESTCONTAINEDRANGE_HPP_
#define SRC_EPI_CHAPTER13_LONGESTCONTAINEDRANGE_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter13 {
    class LongestContainedRange : myutils::Solution {
    public:
        LongestContainedRange():
            Solution("EPI Chapter 13.10",
                     "Find the length of a longest contained interval",
                     "Use a set to record all integers. Then start from "
                     "any interger, check if its left and right intergers "
                     "are exist. If exist, update the subset and remove them.") { }

        ~LongestContainedRange() { }

        int longestContainedRange(const std::vector<int> &array);

        bool test();

    };

  } // chapter13
} // epi

#endif /* SRC_EPI_CHAPTER13_LONGESTCONTAINEDRANGE_HPP_ */
