#ifndef SRC_EPI_CHAPTER12_SEARCHFIRSTOFK_HPP_
#define SRC_EPI_CHAPTER12_SEARCHFIRSTOFK_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter12 {
    class SearchFirstOfK : myutils::Solution {
    public:
        SearchFirstOfK():
            Solution("EPI Chapter 12.1",
                     "Search a sorted array for first occurrence of k",
                     "When find k, not stop but check if left element is "
                     "also k or not. If so, move upper to left to continue search.") { }

        ~SearchFirstOfK() { }

        int searchFirstOfK(const std::vector<int> &A, int k);

        bool test();

    };

  } // chapter12
} // epi

#endif /* SRC_EPI_CHAPTER12_SEARCHFIRSTOFK_HPP_ */
