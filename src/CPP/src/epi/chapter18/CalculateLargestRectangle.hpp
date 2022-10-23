#ifndef SRC_EPI_CHAPTER18_CALCULATELARGESTRECTANGLE_HPP_
#define SRC_EPI_CHAPTER18_CALCULATELARGESTRECTANGLE_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter18 {
    class CalculateLargestRectangle : public myutils::Solution {
    public:
        CalculateLargestRectangle():
            Solution("EPI Chapter 18.8",
                     "Compute the largest rectangle under the skyline",
                     "Use a stack to store increase build indexes. If meet "
                     "a lower build than the last building in the stack, compute "
                     "rectangles until the top of the stack is lower.") { }

        ~CalculateLargestRectangle() { }

        int calculateLargestRectangle(const std::vector<int> &heights);

        bool test();

    };

  } // chapter18
} // epi

#endif /* SRC_EPI_CHAPTER18_CALCULATELARGESTRECTANGLE_HPP_ */
