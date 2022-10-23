#include "RotateMatrix.hpp"

#include <vector>
#include <iostream>
#include <algorithm>

#include "../../MyUtils.h"

using std::vector;
using std::cout;
using std::endl;
using std::swap;
using myutils::matrix_to_string;

namespace epi {
  namespace chapter6 {
    vector< vector<int> > RotateMatrix::rotateMatrixBruteForce(const vector< vector<int> > &squareMatrix) {
        vector<vector<int>> res;
        size_t size = squareMatrix.size();
        for (size_t i = 0; i != size; ++i) {
            res.push_back( vector<int>(size, 0) );
        }

        for (size_t m = 0; m != size; ++m) {
            for (size_t n = 0; n != size; ++n) {
                res[n][size - m - 1] = squareMatrix[m][n];
            }
        }

        return res;
    }

    void RotateMatrix::rotateMatrix(vector< vector<int> > &squareMatrix) {
        if ( squareMatrix.size() == 0 || squareMatrix.size() != squareMatrix[0].size() )
            return;

        int size = squareMatrix.size();

        for (int offset = 0; offset != size / 2; ++offset) {
            for (int i = offset; i != size - offset - 1; ++i) {
                swap(squareMatrix[offset][i], squareMatrix[i][size - offset - 1]);
                swap(squareMatrix[offset][i], squareMatrix[size - offset - 1][size - i - 1]);
                swap(squareMatrix[offset][i], squareMatrix[size - i - 1][offset]);
            }
        }
    }

    bool RotateMatrix::test() {
        vector< vector<int> > squareMatrix1 = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };

        vector< vector<int> > squareMatrix2 = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12},
                {13, 14, 15, 16}
        };

        vector< vector<vector<int>> > matrixs = {squareMatrix1, squareMatrix2};

        for (vector<vector<int>> matrix : matrixs) {
            vector<vector<int>> shouldBe = rotateMatrixBruteForce(matrix);
//            rotateMatrix(matrix);
//            if (matrix != shouldBe) {
//                cout << "Should be: " << endl;
//                cout << matrix_to_string(shouldBe) << endl;
//                cout << "Result: " << endl;
//                cout << matrix_to_string(matrix) << endl;
//                return false;
//            }

        }

        return true;
    }


  } // chapter6
} // epi
