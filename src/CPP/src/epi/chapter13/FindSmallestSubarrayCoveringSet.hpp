#ifndef SRC_EPI_CHAPTER13_FINDSMALLESTSUBARRAYCOVERINGSET_HPP_
#define SRC_EPI_CHAPTER13_FINDSMALLESTSUBARRAYCOVERINGSET_HPP_

#include "../../Solution.h"

#include <vector>
#include <string>
#include <unordered_set>
#include <sstream>

namespace epi {
  namespace chapter13 {
    class FindSmallestSubarrayCoveringSet : public myutils::Solution {
    public:
        struct Subarray;

        FindSmallestSubarrayCoveringSet():
            Solution("EPI Chapter 13.7",
                     "Find the smallest subarray covering all values",
                     "First method is moving window. Second method is linked list.") { }

        ~FindSmallestSubarrayCoveringSet() { }

        Subarray findSmallestSetMovingWindow(const std::vector<std::string> &paragraph, const std::unordered_set<std::string> &keywords);

        Subarray findSmallestSetLinkedList(std::istringstream *sin, const std::unordered_set<std::string> &queryStrings);

        bool test();

    };

  } // chapter13
} // epi

#endif /* SRC_EPI_CHAPTER13_FINDSMALLESTSUBARRAYCOVERINGSET_HPP_ */
