/*
 * [Source] https://leetcode.com/problems/range-sum-query-2d-immutable/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: 
// [Corner Case]:
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if ( matrix.size() == 0 || matrix[0].size() == 0 ) {
            return;
        }

        areas_ = vector<vector<int>>( matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0) );
        for (size_t i = 1; i <= matrix.size(); ++i) {
            int rowSum = 0;
            for (size_t j = 1; j <= matrix[0].size(); ++j) {
                rowSum += matrix[i - 1][j - 1];
                areas_[i][j] = areas_[i - 1][j] + rowSum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 < 0 || row1 > (int)areas_.size())
            return 0;
        if ( col1 < 0 || areas_.size() == 0 || col1 > (int)areas_[0].size() )
            return 0;
        if (row2 < 0 || row2 > (int)areas_.size())
            return 0;
        if ( col2 < 0 || areas_.size() == 0 || col2 > (int)areas_[0].size() )
            return 0;

        // verify row1 and col1 are at left up corner

        int base = areas_[row2 + 1][col2 + 1];
        int left = areas_[row2 + 1][col1];
        int up = areas_[row1][col2 + 1];
        int upLeft = areas_[row1][col1];

        return base - left - up + upLeft;
    }

private:
    vector<vector<int>> areas_;
};

class Solution {
public:
    void test() {
        vector<vector<int>> matrix = {
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}
        };

        NumMatrix numMatrix(matrix);
        cout << numMatrix.sumRegion(0, 1, 2, 3) << endl;
        cout << numMatrix.sumRegion(1, 2, 3, 4) << endl;
        cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
        cout << numMatrix.sumRegion(1, 1, 2, 2) << endl;
        cout << numMatrix.sumRegion(1, 2, 2, 4) << endl;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    sol.test();

    return 0;
}
