#ifndef SRC_EPI_CHAPTER14_ADDINTERVAL_HPP_
#define SRC_EPI_CHAPTER14_ADDINTERVAL_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter14 {
    class AddInterval : public myutils::Solution {
    public:
        struct Interval;

        AddInterval():
            Solution("EPI Chapter 14.5",
                     "Merging intervals",
                     "find first overlaping interval; 2. compute "
                     "until last overlapping interval; 3. replace "
                     "those intervals with the new interval.") { }

        ~AddInterval() { }

        void addInterval(std::vector<Interval> &disjointIntervals, Interval newInterval);

        bool test();

    };

  } // chapter14
} // epi

#endif /* SRC_EPI_CHAPTER14_ADDINTERVAL_HPP_ */
