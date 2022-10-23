#ifndef SRC_EPI_CHAPTER14_UNIONOFINTERVALS_HPP_
#define SRC_EPI_CHAPTER14_UNIONOFINTERVALS_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter14 {
    class UnionOfIntervals : public myutils::Solution {
    public:
        struct Interval;

        UnionOfIntervals():
            Solution("EPI Chapter 14.6",
                     "Compute the union of intervals",
                     "sort intervals based on their left end. iterate "
                     "through them and find all intersected intervals "
                     "in a roll, add the union result into  the result.") { }

        ~UnionOfIntervals() { }

        std::vector<Interval> unionOfIntervals(std::vector<Interval> intervals);

        bool test();

    private:
        bool isIntersect(const Interval &interval1, const Interval &interval2);

    };

  } // chapter14
} // epi

#endif /* SRC_EPI_CHAPTER14_UNIONOFINTERVALS_HPP_ */
