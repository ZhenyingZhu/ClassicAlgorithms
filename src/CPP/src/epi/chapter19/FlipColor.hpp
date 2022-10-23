#ifndef SRC_EPI_CHAPTER19_FLIPCOLOR_HPP_
#define SRC_EPI_CHAPTER19_FLIPCOLOR_HPP_

#include "../../Solution.h"

#include <vector>
#include <deque>

namespace epi {
  namespace chapter19 {
    class FlipColor : public myutils::Solution {
    public:
        struct Coordinate;

        FlipColor():
            Solution("EPI Chapter 19.2",
                     "Painting a Boolean matrix",
                     "Given a matrix, flip all reachable cells from a given cell. Use BFS.") { }

        ~FlipColor() { }

        void flipColor(int x, int y, std::vector<std::deque<bool>> &matrix);

        bool test();

    };

  } // chapter19
} // epi

#endif /* SRC_EPI_CHAPTER19_FLIPCOLOR_HPP_ */
