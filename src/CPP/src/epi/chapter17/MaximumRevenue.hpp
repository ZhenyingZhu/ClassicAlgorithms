#ifndef SRC_EPI_CHAPTER17_MAXIMUMREVENUE_HPP_
#define SRC_EPI_CHAPTER17_MAXIMUMREVENUE_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter17 {
    class MaximumRevenue : public myutils::Solution {
    public:
        MaximumRevenue():
            Solution("EPI Chapter 17.9",
                     "Pick up coins for maximum gain",
                     " Two players can only pick the first or last coin each time. "
                     "Let R(st, ed) means the max revenue one player can get, S(st, ed) "
                     "means the sum of coins. C[i] is the coin value.") { }

        ~MaximumRevenue() { }

        int maximumRevenue(const std::vector<int> &coins);

        bool test();

    };

  } // chapter17
} // epi

#endif /* SRC_EPI_CHAPTER17_MAXIMUMREVENUE_HPP_ */
