/*
 * [Source] https://leetcode.com/problems/number-of-islands/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 * [Tag]: Breadth-first Search
 * [Tag]: Union Find
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int height = grid.size();
        if (height == 0)
            return 0;
        int width = grid[0].size();
        if (width == 0)
            return 0;

        int num = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == '1') {
                    ++num;
                    dfs(grid, i, j);
                }
            }
        }
        return num;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size() || grid[i][j] != '1')
            return;
        grid[i][j] = '*';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<string> vec = {"11000", "11000", "00100", "00011"};
    vector<vector<char>> grid;
    for (string& s : vec)
        grid.push_back(vector<char>(s.begin(), s.end()));
    
    cout << sol.numIslands(grid) << endl;

    return 0;
}
