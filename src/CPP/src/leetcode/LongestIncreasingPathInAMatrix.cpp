/*
 * [Source] https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
 * [Difficulty]: Hard
 * [Tag]: Depth-first Search
 * [Tag]: Topological Sort
 * [Tag]: Memorization
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// [Solution]: DFS on each cell. Record path length for accessed cell so that don't repeat compute.
// [Corner Case]: Need tag current cell as visited to avoid cycle
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        vector<vector<int>> longestPath(matrix.size(), vector<int>(matrix[0].size(), -1));

        int maxLen = 0;
        for (int i = 0; i < (int)matrix.size(); ++i) {
            for (int j = 0; j < (int)matrix[0].size(); ++j) {
                dfs(matrix, longestPath, i, j, INT_MIN, maxLen);
            }
        }
        return maxLen;
    }

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &longestPath, int x, int y, int preVal, int &maxLen) {
        if (x < 0 || x >= (int)matrix.size() || y < 0 || y >= (int)matrix[0].size())
            return 0;
        if (preVal >= matrix[x][y])
            return 0;
        if (longestPath[x][y] != -1)
            return longestPath[x][y];

        int pathLen = 0;
        int curVal = matrix[x][y];
        //matrix[x][y] = INT_MIN; // avoid cycle is that necessary?
        pathLen = max(dfs(matrix, longestPath, x - 1, y, curVal, maxLen), pathLen);
        pathLen = max(dfs(matrix, longestPath, x + 1, y, curVal, maxLen), pathLen);
        pathLen = max(dfs(matrix, longestPath, x, y - 1, curVal, maxLen), pathLen);
        pathLen = max(dfs(matrix, longestPath, x, y + 1, curVal, maxLen), pathLen);
        //matrix[x][y] = curVal;

        maxLen = max(pathLen + 1, maxLen);
        longestPath[x][y] = pathLen + 1;
        return pathLen + 1;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    cout << sol.longestIncreasingPath(matrix) << endl;

    return 0;
}
