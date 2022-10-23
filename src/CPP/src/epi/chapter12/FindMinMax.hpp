#ifndef SRC_EPI_CHAPTER12_FINDMINMAX_HPP_
#define SRC_EPI_CHAPTER12_FINDMINMAX_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter12 {
    class FindMinMax : myutils::Solution {
    public:
        struct MinMax;

        FindMinMax():
            Solution("EPI Chapter 12.7",
                     "Find the min and max simultaneously",
                     "Store every two elements in order as min then max, "
                     "so that compare min with min and max with max to "
                     "save half comparasions.") { }

        ~FindMinMax() { }

        MinMax findMinMax(const std::vector<int> &vec);

        bool test();

    };

  } // chapter12
} // epi

#endif /* SRC_EPI_CHAPTER12_FINDMINMAX_HPP_ */
