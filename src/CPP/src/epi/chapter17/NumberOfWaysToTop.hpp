#ifndef SRC_EPI_CHAPTER17_NUMBEROFWAYSTOTOP_HPP_
#define SRC_EPI_CHAPTER17_NUMBEROFWAYSTOTOP_HPP_

#include "../../Solution.h"

namespace epi {
  namespace chapter17 {
    class NumberOfWaysToTop : public myutils::Solution {
    public:
        NumberOfWaysToTop():
            Solution("EPI Chapter 17.10",
                     "Count the number of moves to climb stairs",
                     "Advance at most k steps, to climb to n stairs. "
                     "Use an array with n length.") { }

        ~NumberOfWaysToTop() { }

        size_t numberOfWaysToTop(unsigned int top, unsigned int maxStep);

        bool test();

    };

  } // chapter17
} // epi

#endif /* SRC_EPI_CHAPTER17_NUMBEROFWAYSTOTOP_HPP_ */
