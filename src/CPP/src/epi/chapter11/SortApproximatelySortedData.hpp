#ifndef SRC_EPI_CHAPTER11_SORTAPPROXIMATELYSORTEDDATA_HPP_
#define SRC_EPI_CHAPTER11_SORTAPPROXIMATELYSORTEDDATA_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>
#include <sstream>

namespace epi {
  namespace chapter11 {
    class SortApproximatelySortedData : myutils::Solution {
    public:
        SortApproximatelySortedData():
            Solution("EPI Chapter 11.3",
                     "Sort an almost-sorted array",
                     "Use a min-heap to record k numbers, "
                     "and each time extract the min number out.") { }

        ~SortApproximatelySortedData() { }

        std::vector<int> sortApproximatelySortedData(std::istringstream *sequence, size_t k);

        bool test();

    };

  } // chapter11
} // epi

#endif /* SRC_EPI_CHAPTER11_SORTAPPROXIMATELYSORTEDDATA_HPP_ */
