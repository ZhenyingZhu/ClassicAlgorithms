#ifndef SRC_EPI_CHAPTER17_NUMBEROFWAYS_HPP_
#define SRC_EPI_CHAPTER17_NUMBEROFWAYS_HPP_

#include "../../Solution.h"

#include <string>

namespace epi {
  namespace chapter17 {
    class NumberOfWays : public myutils::Solution {
    public:
        NumberOfWays():
            Solution("EPI Chapter 17.3",
                     "Count the number of ways to traverse a 2D array",
                     "N(i,j)=min(N(i-1,j), N(i,j-1)) + 1.") { }

        ~NumberOfWays() { }

        size_t numberOfWays(size_t m, size_t n);

        bool test();

    };

  } // chapter17
} // epi

#endif /* SRC_EPI_CHAPTER17_NUMBEROFWAYS_HPP_ */
