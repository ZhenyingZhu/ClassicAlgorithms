#ifndef SRC_EPI_CHAPTER12_SEARCHSMALLEST_HPP_
#define SRC_EPI_CHAPTER12_SEARCHSMALLEST_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter12 {
    class SearchSmallest : myutils::Solution {
    public:
        SearchSmallest():
            Solution("EPI Chapter 12.3",
                     "Search smallest element in a cyclically sorted array",
                     "if st < ed, return st; if st >= ed, if md > st, in "
                     "the right; if md < st, in the left; if md == st, "
                     "if md > ed, in the right; if md == ed, traverse.") { }

        ~SearchSmallest() { }

        int searchSmallest(const std::vector<int> &A);

        bool test();

    };

  } // chapter12
} // epi

#endif /* SRC_EPI_CHAPTER12_SEARCHSMALLEST_HPP_ */
