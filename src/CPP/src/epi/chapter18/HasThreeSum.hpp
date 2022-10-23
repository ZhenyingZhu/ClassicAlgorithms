#ifndef SRC_EPI_CHAPTER18_HASTHREESUM_HPP_
#define SRC_EPI_CHAPTER18_HASTHREESUM_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter18 {
    class HasThreeSum : public myutils::Solution {
    public:
        HasThreeSum():
            Solution("EPI Chapter 18.4",
                     "The 3-sum problem",
                     "Sort the array. For each A(i), solve 3-sum problem for sum - A(i), "
                     "by start from the sum of beginning and ending, and then move either one.") { }

        ~HasThreeSum() { }

        bool hasThreeSum(std::vector<int> array, int sum);

        bool test();

    };

  } // chapter18
} // epi

#endif /* SRC_EPI_CHAPTER18_HASTHREESUM_HPP_ */
