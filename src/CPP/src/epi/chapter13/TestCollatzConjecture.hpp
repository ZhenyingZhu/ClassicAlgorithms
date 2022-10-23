#ifndef SRC_EPI_CHAPTER13_TESTCOLLATZCONJECTURE_HPP_
#define SRC_EPI_CHAPTER13_TESTCOLLATZCONJECTURE_HPP_

#include "../../Solution.h"

namespace epi {
  namespace chapter13 {
    class TestCollatzConjecture : myutils::Solution {
    public:
        TestCollatzConjecture():
            Solution("EPI Chapter 13.13",
                     "Test the Collatz conjecture",
                     "Test all numbers from 1 to n. Use a hash"
                     " set to record tested value. Only test "
                     "odd value because even value / 2 must "
                     "has tested. Stop when the tmp value is "
                     "smaller than the current test value.") { }

        ~TestCollatzConjecture() { }

        bool testCollatzConjecture(int n);

        bool test();

    };

  } // chapter13
} // epi

#endif /* SRC_EPI_CHAPTER13_TESTCOLLATZCONJECTURE_HPP_ */
