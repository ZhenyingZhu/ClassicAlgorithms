#ifndef SRC_EPI_CHAPTER11_KLARGESTINBINARYHEAP_HPP_
#define SRC_EPI_CHAPTER11_KLARGESTINBINARYHEAP_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>
#include <sstream>

namespace epi {
  namespace chapter11 {
    class KLargestInBinaryHeap : myutils::Solution {
    public:
        KLargestInBinaryHeap():
            Solution("EPI Chapter 11.6",
                     "Compute the k largest elements in a max-heap",
                     "the k elements must shows in the first k level "
                     "of BT of the heap. The input is an array. Use "
                     "index to determine the level.") { }

        ~KLargestInBinaryHeap() { }

        std::vector<int> kLargestInBinaryHeap(const std::vector<int> &array, size_t k);

        bool test();

    };

  } // chapter11
} // epi

#endif /* SRC_EPI_CHAPTER11_KLARGESTINBINARYHEAP_HPP_ */
