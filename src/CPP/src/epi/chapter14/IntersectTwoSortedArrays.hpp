#ifndef SRC_EPI_CHAPTER14_INTERSECTTWOSORTEDARRAYS_HPP_
#define SRC_EPI_CHAPTER14_INTERSECTTWOSORTEDARRAYS_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter14 {
    class IntersectTwoSortedArrays : public myutils::Solution {
    public:
        IntersectTwoSortedArrays():
            Solution("EPI Chapter 14.1",
                     "Compute the intersection of two sorted arrays",
                     "Use two pointers point to current entries in two arrays. "
                     "Increase the pointer which is smaller than the others "
                     "until find same entries.") { }

        ~IntersectTwoSortedArrays() { }

        std::vector<int> intersectTwoSortedArrays(const std::vector<int> &array1, const std::vector<int> &array2);

        bool test();

    };

  } // chapter14
} // epi

#endif /* SRC_EPI_CHAPTER14_INTERSECTTWOSORTEDARRAYS_HPP_ */
