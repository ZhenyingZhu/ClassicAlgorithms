#ifndef SRC_EPI_CHAPTER18_GETMAXTRAPPEDWATER_HPP_
#define SRC_EPI_CHAPTER18_GETMAXTRAPPEDWATER_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter18 {
    class GetMaxTrappedWater : public myutils::Solution {
    public:
        GetMaxTrappedWater():
            Solution("EPI Chapter 18.7",
                     "Compute the maximum water trapped by a pair of vertical lines",
                     "Always be the distance between st and ed multiple min(A[st], A[ed]),"
                     " so if A[st] < A[ed], st + 1, else ed - 1.") { }

        ~GetMaxTrappedWater() { }

        int getMaxTrappedWater(const std::vector<int> &heights);

        bool test();

    };

  } // chapter18
} // epi

#endif /* SRC_EPI_CHAPTER18_GETMAXTRAPPEDWATER_HPP_ */
