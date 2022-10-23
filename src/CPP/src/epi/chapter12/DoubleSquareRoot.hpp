#ifndef SRC_EPI_CHAPTER12_DOUBLESQUAREROOT_HPP_
#define SRC_EPI_CHAPTER12_DOUBLESQUAREROOT_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter12 {
    class DoubleSquareRoot : myutils::Solution {
    public:
        typedef enum { EQ, SM, LR } Ordering;

        DoubleSquareRoot():
            Solution("EPI Chapter 12.5",
                     "Compute the real square root",
                     "Since st == md won't happen, binary "
                     "search with a double comparation.") { }

        ~DoubleSquareRoot() { }

        double squareRoot(double x);

        bool test();

    private:
        Ordering compare(double a, double b);

    };

  } // chapter12
} // epi

#endif /* SRC_EPI_CHAPTER12_DOUBLESQUAREROOT_HPP_ */
