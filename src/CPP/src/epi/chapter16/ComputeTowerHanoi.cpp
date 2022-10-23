#include "ComputeTowerHanoi.hpp"

#include <array>
#include <stack>
#include <iostream>
#include <stdexcept>
#include <cassert>

using std::array;
using std::stack;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter16 {
    void ComputeTowerHanoi::computeTowerHanoiSteps(size_t moveNum, array<stack<int>, pegNum_> &pegs,
            size_t fromPeg, size_t toPeg, size_t usePeg) {
        if (moveNum == 0)
            return;

        computeTowerHanoiSteps(moveNum - 1, pegs, fromPeg, usePeg, toPeg);
        int moveId = pegs[fromPeg].top();
        pegs[fromPeg].pop();
        cout << "Move Ring" << moveId << " from Peg" << fromPeg << " to Peg" << toPeg << "." << endl;
        pegs[toPeg].push(moveId);
        computeTowerHanoiSteps(moveNum - 1, pegs, usePeg, toPeg, fromPeg);
    }

    void ComputeTowerHanoi::computeTowerHanoi(int numRings) {
        array<stack<int>, pegNum_> pegs;
        for (int i = numRings; i >= 1; --i)
            pegs[0].push(i);

        computeTowerHanoiSteps(numRings, pegs, 0, 2, 1);
    }

    bool ComputeTowerHanoi::test() {
        computeTowerHanoi(4);

        return true;
    }

  } // chapter16
} // epi
