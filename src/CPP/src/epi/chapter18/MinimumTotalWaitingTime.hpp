#ifndef SRC_EPI_CHAPTER18_MINIMUMTOTALWAITINGTIME_HPP_
#define SRC_EPI_CHAPTER18_MINIMUMTOTALWAITINGTIME_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter18 {
    class MinimumTotalWaitingTime : public myutils::Solution {
    public:
        MinimumTotalWaitingTime():
            Solution("EPI Chapter 18.2",
                     "Schedule to minimize waiting time",
                     "Sort the array.") { }

        ~MinimumTotalWaitingTime() { }

        int minimumTotalWaitingTime(std::vector<int> serviceTimes);

        bool test();

    };

  } // chapter18
} // epi

#endif /* SRC_EPI_CHAPTER18_MINIMUMTOTALWAITINGTIME_HPP_ */
