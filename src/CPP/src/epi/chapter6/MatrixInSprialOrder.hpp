#ifndef SRC_EPI_CHAPTER6_MATRIXINSPRIALORDER_HPP_
#define SRC_EPI_CHAPTER6_MATRIXINSPRIALORDER_HPP_

#include <vector>

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace epi {
  namespace chapter6 {
    class MatrixInSprialOrder : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        MatrixInSprialOrder():
            Solution("EPI Chapter 6.17",
                     "Compute the spiral ordering of a 2D array",
                     "Divide and conque, or use a direction vector.") { }

        bool test();

        ~MatrixInSprialOrder() { }

        std::vector<int> matrixInSprialOrder(const std::vector< std::vector<int> > &squareMatrix);

        std::vector<int> matrixInSprialOrderDirectVector(std::vector< std::vector<int> > squareMatrix);

    private:
        void matrixLayerInClockwise(const std::vector< std::vector<int> > &squareMatrix, int offset, std::vector<int> &spiralOrdering);
    };
  } // chapter6
} // epi

#endif /* SRC_EPI_CHAPTER6_MATRIXINSPRIALORDER_HPP_ */
