#ifndef SRC_EPI_CHAPTER12_SEARCHENTRYEQUALTOITSINDEX_HPP_
#define SRC_EPI_CHAPTER12_SEARCHENTRYEQUALTOITSINDEX_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter12 {
    class SearchEntryEqualToItsIndex : myutils::Solution {
    public:
        SearchEntryEqualToItsIndex():
            Solution("EPI Chapter 12.2",
                     "Search a sorted array for entry equal to its index",
                     "If a cell has element that is already larger than its"
                     " index, all elements after it cannot be the answer.") { }

        ~SearchEntryEqualToItsIndex() { }

        int searchEntryEqualToItsIndex(const std::vector<int> &A);

        bool test();

    };

  } // chapter12
} // epi

#endif /* SRC_EPI_CHAPTER12_SEARCHENTRYEQUALTOITSINDEX_HPP_ */
