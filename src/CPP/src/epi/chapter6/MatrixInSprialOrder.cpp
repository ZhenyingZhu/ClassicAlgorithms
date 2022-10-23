#include "MatrixInSprialOrder.hpp"

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <array>
#include <climits>

#include "../../MyUtils.h"

using std::cout;
using std::endl;
using std::vector;
using myutils::vec_to_string;
using std::ceil;
using std::min;
using std::array;

namespace epi {
  namespace chapter6 {
      void MatrixInSprialOrder::matrixLayerInClockwise(const vector< vector<int> > &squareMatrix,
                                                       int offset, vector<int> &spiralOrdering) {
          int lines = squareMatrix.size(), rows = squareMatrix[0].size();

          // to avoid taking care of one line case, always proceed to the very end
          for (int i = offset; i < rows - offset; ++i)
              spiralOrdering.push_back( squareMatrix[offset][i] );

          for (int j = offset + 1; j < lines - offset; ++j)
              spiralOrdering.push_back( squareMatrix[j][rows - offset - 1] );

          // to avoid add the same line back
          if (offset == lines - offset - 1)
              return;

          for (int m = rows - offset - 2; m >= offset; --m)
              spiralOrdering.push_back( squareMatrix[lines - offset - 1][m] );

          for (int n = lines - offset - 2; n >= offset + 1; --n)
              spiralOrdering.push_back( squareMatrix[n][offset] );
      }

      vector<int> MatrixInSprialOrder::matrixInSprialOrder(const vector< vector<int> > &squareMatrix) {
          vector<int> spiralOrdering;

          int lines = squareMatrix.size(), rows = squareMatrix[0].size();
          int iterateTimes = ceil( 0.5 * min(lines, rows) );
          for (int i = 0; i != iterateTimes; ++i) {
              matrixLayerInClockwise(squareMatrix, i, spiralOrdering);
          }

          return spiralOrdering;
      }

      vector<int> MatrixInSprialOrder::matrixInSprialOrderDirectVector(vector< vector<int> > squareMatrix) {
          const array< array<int, 2>, 4 > kShift = {{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} }};
          int dir = 0, x = 0, y = 0;

          int lines = squareMatrix.size(), rows = squareMatrix[0].size();

          vector<int> spiralOrdering;

          for (int i = 0; i != lines * rows; ++i) {
              spiralOrdering.push_back( squareMatrix[x][y] );
              squareMatrix[x][y] = INT_MAX;

              int nextX = x + kShift[dir][0], nextY = y + kShift[dir][1];

              if (nextX < 0 || nextX >= lines || nextY < 0 || nextY >= rows || squareMatrix[nextX][nextY] == INT_MAX)
                  dir = (dir + 1) % 4;

              x += kShift[dir][0];
              y +=kShift[dir][1];
          }

          return spiralOrdering;
      }

      bool MatrixInSprialOrder::test() {
          vector< vector<int> > matrix1 = {
                  {1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9}
          };

          vector< vector<int> > matrix2 = {
                  {1, 2, 3, 4},
                  {5, 6, 7, 8},
                  {9, 10, 11, 12},
                  {13, 14, 15, 16}
          };

          vector< vector<int> > matrix3 = {
                  {1, 2, 3, 4},
                  {5, 6, 7, 8},
                  {9, 10, 11, 12}
          };

          vector< vector<int> > matrix4 = {
                  {1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9},
                  {10, 11, 12}
          };

          vector< vector<int> > matrix5 = {
                  {1, 2, 3, 4, 5},
                  {6, 7, 8, 9, 10},
                  {11, 12, 13, 14, 15}
          };

          vector< vector<int> > matrix6 = {
                  {1, 2, 3, 4, 5},
                  {6, 7, 8, 9, 10},
                  {11, 12, 13, 14, 15},
                  {16, 17, 18, 19, 20}
          };

          vector< vector<vector<int>> > matrixs = {matrix1, matrix2, matrix3, matrix4, matrix5, matrix6};

          for (vector<vector<int>> matrix : matrixs) {
              vector<int> res1 = matrixInSprialOrder(matrix);
              vector<int> res2 = matrixInSprialOrderDirectVector(matrix);
              if (res1 != res2) {
                  cout << "Should be: " << vec_to_string(res2) << endl;
                  cout << "Result: " << vec_to_string(res1) << endl;
                  return false;
              }
          }

          return true;
      }

  } // chapter6
} // epi
