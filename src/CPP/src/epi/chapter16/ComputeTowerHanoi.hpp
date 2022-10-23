#ifndef SRC_EPI_CHAPTER16_COMPUTETOWERHANOI_HPP_
#define SRC_EPI_CHAPTER16_COMPUTETOWERHANOI_HPP_

#include "../../Solution.h"

#include <array>
#include <stack>

namespace epi {
  namespace chapter16 {
    class ComputeTowerHanoi : public myutils::Solution {
    public:
        ComputeTowerHanoi():
            Solution("EPI Chapter 16.1",
                     "The Towers of Hanoi problem",
                     "Use recursion. Use 1. number of rings need "
                     "to move, 2. stacks, 3. from peg, 4. to peg, "
                     "5. use peg as arguments.") { }

        ~ComputeTowerHanoi() { }

        void computeTowerHanoi(int numRings);

        bool test();

    private:
        const static size_t pegNum_ = 3;

        void computeTowerHanoiSteps(size_t moveNum, std::array<std::stack<int>, pegNum_> &pegs,
                size_t fromPeg, size_t toPeg, size_t usePeg);

    };

  } // chapter16
} // epi

#endif /* SRC_EPI_CHAPTER16_COMPUTETOWERHANOI_HPP_ */
