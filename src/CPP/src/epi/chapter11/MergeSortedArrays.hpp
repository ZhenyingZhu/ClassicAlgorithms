#ifndef SRC_EPI_CHAPTER11_MERGESORTEDARRAYS_HPP_
#define SRC_EPI_CHAPTER11_MERGESORTEDARRAYS_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter11 {
    class MergeSortedArrays : myutils::Solution {
    public:
        struct IteratorCurrentAndEnd;

        MergeSortedArrays():
            Solution("EPI Chapter 11.1",
                     "Merge sorted files",
                     "Use min heap to store the first element of "
                     "each file. Pop an element and refill with "
                     "the file that contains it.") { }

        ~MergeSortedArrays() { }

        std::vector<int> mergeSortedArrays(const std::vector<std::vector<int>> &sortedArrays);

        bool test();

    };

  } // chapter11
} // epi

#endif /* SRC_EPI_CHAPTER11_MERGESORTEDARRAYS_HPP_ */
