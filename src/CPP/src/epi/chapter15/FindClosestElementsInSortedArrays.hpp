#ifndef SRC_EPI_CHAPTER15_FINDCLOSESTELEMENTSINSORTEDARRAYS_HPP_
#define SRC_EPI_CHAPTER15_FINDCLOSESTELEMENTSINSORTEDARRAYS_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter15 {
    class FindClosestElementsInSortedArrays : public myutils::Solution {
    public:
        FindClosestElementsInSortedArrays():
            Solution("EPI Chapter 15.6",
                     "Find the closest entries in three sorted arrays",
                     "Get first entries from trhee arrays. Count the distance. "
                     "Then remove the smallest entry and add its successor from its array.") { }

        ~FindClosestElementsInSortedArrays() { }

        int findClosestElementsInSortedArrays(const std::vector<std::vector<int>> &sortedArrays);

        bool test();

    };

  } // chapter15
} // epi

#endif /* SRC_EPI_CHAPTER15_FINDCLOSESTELEMENTSINSORTEDARRAYS_HPP_ */
