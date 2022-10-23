/*
 * [Source] https://leetcode.com/problems/island-perimeter/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Check if the surroundhing cells are island. If so reduce the edge by 1
// [Corner Case]:

vector<int> dir = {1, 0, -1, 0, 1};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int cnt = 0;
        for (int i = 0; i < (int)grid.size(); ++i) {
            for (int j = 0; j < (int)grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    cnt += getEdges(i, j, grid);
                }
            }
        }
        return cnt;
    }

    int getEdges(int i, int j, vector<vector<int>> &grid) {
        int edges = 4;
        for (int idx = 0; idx < 4; ++idx) {
            int x = i + dir[idx], y = j + dir[idx + 1];
            if (x >= 0 && x < (int)grid.size() && y >= 0 && y < (int)grid[0].size() && grid[x][y] == 1)
                --edges;
        }
        return edges;
    }
    
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0,1,0,0}, {1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout << sol.islandPerimeter(grid) << endl;

    return 0;
}
