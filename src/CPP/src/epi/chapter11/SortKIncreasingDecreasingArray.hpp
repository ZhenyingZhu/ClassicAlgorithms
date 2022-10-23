#ifndef SRC_EPI_CHAPTER11_SORTKINCREASINGDECREASINGARRAY_HPP_
#define SRC_EPI_CHAPTER11_SORTKINCREASINGDECREASINGARRAY_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter11 {
    class SortKIncreasingDecreasingArray : myutils::Solution {
    public:
        SortKIncreasingDecreasingArray():
            Solution("EPI Chapter 11.2",
                     "Sort an increasing-decreasing array",
                     "Sort it by first breaking it into k pieces, "
                     "then use merge sort to sort k subarray.") { }

        ~SortKIncreasingDecreasingArray() { }

        std::vector<int> sortKIncreasingDecreasingArray(const std::vector<int> &array);

        bool test();

    private:
        struct IteratorCurrentAndEnd;

        std::vector<int> mergeSortedArrays(const std::vector<std::vector<int>> &sortedArrays);

    };

  } // chapter11
} // epi

#endif /* SRC_EPI_CHAPTER11_SORTKINCREASINGDECREASINGARRAY_HPP_ */
