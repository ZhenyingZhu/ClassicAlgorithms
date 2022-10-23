/*
 * [Source] https://leetcode.com/problems/search-a-2d-matrix-ii/
 * [Difficulty]: Medium
 * [Tag]: Binary Search
 * [Tag]: Divide and Conquer
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;

        int height = matrix.size(), width = matrix[0].size();
        int x = height - 1, y = 0;
        while (x >= 0 && y < width) {
            if (matrix[x][y] == target)
                return true;

            if (matrix[x][y] > target) {
                --x;
            } else {
                ++y;
            }
        }

        return false;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    cout << (sol.searchMatrix(matrix, 5) ? "True":"False") << endl;
    cout << (sol.searchMatrix(matrix, 20) ? "True":"False") << endl;

    return 0;
}
