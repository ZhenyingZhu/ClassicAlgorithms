#ifndef SRC_EPI_CHAPTER6_ROTATEMATRIX_HPP_
#define SRC_EPI_CHAPTER6_ROTATEMATRIX_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter6 {

    class RotateMatrix : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        RotateMatrix():
            Solution("EPI Chapter 6.18",
                     "Rotate a 2D Array 90 degree clockwise",
                     "In place 4 elements each time. Can also reassign pointers.") { }

        bool test();

        ~RotateMatrix() { }

        std::vector< std::vector<int> > rotateMatrixBruteForce(const std::vector< std::vector<int> > &squareMatrix);
        void rotateMatrix(std::vector< std::vector<int> > &squareMatrix);
    };

  } // chapter6
} // epi

#endif /* SRC_EPI_CHAPTER6_ROTATEMATRIX_HPP_ */
