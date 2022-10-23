#ifndef SRC_EPI_CHAPTER17_LONGESTNONDECREASINGSUBSEQUENCELENGTH_HPP_
#define SRC_EPI_CHAPTER17_LONGESTNONDECREASINGSUBSEQUENCELENGTH_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter17 {
    class LongestNondecreasingSubsequenceLength : public myutils::Solution {
    public:
        LongestNondecreasingSubsequenceLength():
            Solution("EPI Chapter 17.12",
                     "Find the longest nondecreasing subsequence",
                     "Use an array to record for each length, the last element. For element i, "
                     "use binary search to find the previous element, which is the last not greater "
                     "element, and update length array. Why can use binary search is because every "
                     "time the updated element must not smaller than the new element, and it is "
                     "already smaller than the next element.") { }

        ~LongestNondecreasingSubsequenceLength() { }

        int longestNDSLen(const std::vector<int> &array);

        bool test();

    private:
        int findNextIdxOfLastNotGreater(std::vector<int> &tails, int ed, int value);

    };

  } // chapter17
} // epi

#endif /* SRC_EPI_CHAPTER17_LONGESTNONDECREASINGSUBSEQUENCELENGTH_HPP_ */
