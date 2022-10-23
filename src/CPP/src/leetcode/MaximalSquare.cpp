/*
 * [Source] https://leetcode.com/problems/maximal-square/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Basically just find the minimal side length. It comes from 1. how many continuous 1s in the left, 2. how many in the top, 3. the side of [i-1][j-1].
// [Corner Case]:
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int height = matrix.size(), width = matrix[0].size();

        int maxRes = 0;
        vector<vector<int>> depth(height, vector<int>(width, 0));
        vector<vector<int>> length(height, vector<int>(width, 0));
        vector<vector<int>> side(height, vector<int>(width, 0));
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (i == 0) {
                    depth[i][j] = matrix[i][j] == '1' ? 1 : 0;
                } else if (matrix[i][j] == '1') {
                    depth[i][j] = depth[i - 1][j] + 1;
                } else {
                    depth[i][j] = 0;
                }

                if (j == 0) {
                    length[i][j] = matrix[i][j] == '1' ? 1 : 0;
                } else if (matrix[i][j] == '1') {
                    length[i][j] = length[i][j - 1] + 1;
                } else {
                    length[i][j] = 0;
                }

                if (i == 0 || j == 0) {
                    side[i][j] = matrix[i][j] == '1' ? 1 : 0;
                } else {
                    side[i][j] = min( side[i - 1][j - 1] + 1, min(depth[i][j], length[i][j]) );
                }

                maxRes = max(side[i][j] * side[i][j], maxRes);
            }
        }

        return maxRes;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<string> vec = {"10100", "10111", "11111", "10010"};
    vector<vector<char>> matrix;
    for (string& s : vec) {
        matrix.push_back(vector<char>(s.begin(), s.end()));
    }
    cout << sol.maximalSquare(matrix) << endl;

    return 0;
}
