#ifndef SRC_EPI_CHAPTER12_SQUAREROOT_HPP_
#define SRC_EPI_CHAPTER12_SQUAREROOT_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter12 {
    class SquareRoot : myutils::Solution {
    public:
        SquareRoot():
            Solution("EPI Chapter 12.4",
                     "Compute the integer square root",
                     "Binary search between 1 and x/2.") { }

        ~SquareRoot() { }

        int squareRoot(int k);

        bool test();

    };

  } // chapter12
} // epi

#endif /* SRC_EPI_CHAPTER12_SQUAREROOT_HPP_ */
