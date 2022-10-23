#ifndef SRC_EPI_CHAPTER16_GRAYCODE_HPP_
#define SRC_EPI_CHAPTER16_GRAYCODE_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter16 {
    class GrayCode : public myutils::Solution {
    public:
        GrayCode():
            Solution("EPI Chapter 16.10",
                     "Compute a Gray code",
                     "When bit number is 1, there is only 0 and 1. Bit number "
                     "is 2, use 0 add bit number 1 vector, and then use 1 add "
                     "the vector in reverse order.") { }

        ~GrayCode() { }

        std::vector<int> grayCode(size_t numBits);

        bool test();

    };

  } // chapter16
} // epi

#endif /* SRC_EPI_CHAPTER16_GRAYCODE_HPP_ */
