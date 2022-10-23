#ifndef SRC_EPI_CHAPTER13_FINDSMALLESTSEQUENTIALLYCOVERINGSUBSET_HPP_
#define SRC_EPI_CHAPTER13_FINDSMALLESTSEQUENTIALLYCOVERINGSUBSET_HPP_

#include "../../Solution.h"

#include <vector>
#include <string>

namespace epi {
  namespace chapter13 {
    class FindSmallestSequentiallyCoveringSubset : public myutils::Solution {
    public:
        struct Subarray;

        FindSmallestSequentiallyCoveringSubset():
            Solution("EPI Chapter 13.8",
                     "Find smallest subarray sequentially covering all values",
                     "Record 1. the shortest subarray length for each keyword; "
                     "2. the latest idx of each keyword. Then when find a new "
                     "keyword, use the previous keyword length and index to "
                     "compute the new length.") { }

        ~FindSmallestSequentiallyCoveringSubset() { }

        Subarray findSmallestSequentiallyCoveringSubset(const std::vector<std::string> &paragraph, const std::vector<std::string> &keywords);

        bool test();

    };

  } // chapter13
} // epi

#endif /* SRC_EPI_CHAPTER13_FINDSMALLESTSEQUENTIALLYCOVERINGSUBSET_HPP_ */
