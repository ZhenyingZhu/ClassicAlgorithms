#ifndef SRC_EPI_CHAPTER18_FINDMINIMUMVISITS_HPP_
#define SRC_EPI_CHAPTER18_FINDMINIMUMVISITS_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter18 {
    class FindMinimumVisits : public myutils::Solution {
    public:
        struct Interval;

        FindMinimumVisits():
            Solution("EPI Chapter 18.3",
                     "The interval covering problem",
                     "A list of closed intervals. Find a set of numbers "
                     "that all intervals have covered those numbers. Always "
                     "pick the right point of the first end interval.") { }

        ~FindMinimumVisits() { }

        std::vector<int> findMinimumVisits(std::vector<Interval> intervals);

        bool test();

    };

  } // chapter18
} // epi

#endif /* SRC_EPI_CHAPTER18_FINDMINIMUMVISITS_HPP_ */
