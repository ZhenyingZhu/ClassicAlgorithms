/*
 * [Source] https://leetcode.com/problems/pacific-atlantic-water-flow/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 * [Tag]: Breadth-first Search
 */

#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

// [Solution]: From border, dfs the graph.
// [Corner Case]:
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};
        int h = matrix.size(), w = matrix[0].size();

        // -1: not visited, 0: visiting, 1 cannot reach border, 2 can reach border
        vector<vector<int>> toPacific(h, vector<int>(w, -1));
        for (int i = 0; i < h; ++i)
            dfs(i, 0, matrix, toPacific);
        for (int j = 1; j < w; ++j)
            dfs(0, j, matrix, toPacific);
for (vector<int> &vec : toPacific) {
    for (int & i : vec)
        cout << i << " ";
    cout << endl;
}

        vector<vector<int>> toAtlantic(h, vector<int>(w, -1));
        for (int i = 0; i < h; ++i)
            dfs(i, w - 1, matrix, toAtlantic);
        for (int j = 0; j < w - 1; ++j)
            dfs(h - 1, j, matrix, toAtlantic);
for (vector<int> &vec : toAtlantic) {
    for (int & i : vec)
        cout << i << " ";
    cout << endl;
}

        vector<pair<int, int>> res;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (toPacific[i][j] == 2 && toAtlantic[i][j] == 2)
                    res.push_back( {i, j} );
            }
        }
        return res;
    }

    void dfs(int x, int y, vector<vector<int>> &matrix, vector<vector<int>> &toBorder) {
        // visited
        if (toBorder[x][y] != -1)
            return;

        toBorder[x][y] = 2;
        vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for (vector<int> &dir : directions) {
            int newX = x + dir[0], newY = y + dir[1];
            if (newX < 0 || newX >= (int)matrix.size() || newY < 0 || newY >= (int)matrix[0].size() || matrix[newX][newY] < matrix[x][y])
                continue;
            dfs(newX, newY, matrix, toBorder);
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    /*
    vector<vector<int>> matrix = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };*/
    vector<vector<int>> matrix = {
        {1,2,3},{8,9,4},{7,6,5}
    };
    for (pair<int, int> &p : sol.pacificAtlantic(matrix))
        cout << "[" << p.first << "," << p.second << "] ";
    cout << endl;

    return 0;
}
