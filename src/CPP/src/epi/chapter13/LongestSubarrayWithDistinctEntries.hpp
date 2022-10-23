#ifndef SRC_EPI_CHAPTER13_LONGESTSUBARRAYWITHDISTINCTENTRIES_HPP_
#define SRC_EPI_CHAPTER13_LONGESTSUBARRAYWITHDISTINCTENTRIES_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter13 {
    class LongestSubarrayWithDistinctEntries : public myutils::Solution {
    public:
        LongestSubarrayWithDistinctEntries():
            Solution("EPI Chapter 13.9",
                     "Find the longest subarray with distinct entries",
                     "Moving window. Record the last idx of each element, "
                     "and a subarray start idx. When find a duplicate "
                     "element has idx after start idx, move start idx "
                     "after previous occurance of this element.") { }

        ~LongestSubarrayWithDistinctEntries() { }

        int longestSubarrayWithDistinctEntries(const std::vector<int> &array);

        bool test();

    };

  } // chapter13
} // epi

#endif /* SRC_EPI_CHAPTER13_LONGESTSUBARRAYWITHDISTINCTENTRIES_HPP_ */
