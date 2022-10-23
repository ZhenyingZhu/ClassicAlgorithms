#ifndef SRC_EPI_CHAPTER11_ONLINEMEDIAN_HPP_
#define SRC_EPI_CHAPTER11_ONLINEMEDIAN_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>
#include <sstream>

namespace epi {
  namespace chapter11 {
    class OnlineMedian : myutils::Solution {
    public:
        OnlineMedian():
            Solution("EPI Chapter 11.5",
                     "Compute the median of online data",
                     "Use a max and a min heap. Keep both "
                     "heaps have the same size.") { }

        ~OnlineMedian() { }

        std::vector<float> onlineMedian(std::istringstream *sequence);

        bool test();

    };

  } // chapter11
} // epi

#endif /* SRC_EPI_CHAPTER11_ONLINEMEDIAN_HPP_ */
