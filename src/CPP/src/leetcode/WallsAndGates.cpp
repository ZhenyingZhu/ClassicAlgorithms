/*
 * [Source] https://leetcode.com/problems/walls-and-gates/
 * [Difficulty]: Medium
 * [Tag]: Breadth-first Search
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// [Solution]: From each gate, do dfs until find a node that is either 1. obstactle, 2. gate, 3. a room that is not farther to another gate.
// [Corner Case]:
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty())
            return;

        dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int h = rooms.size(), w = rooms[0].size();
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (rooms[i][j] == 0)
                    dfs(rooms, i, j);
            }
        }
    }

    void dfs(vector<vector<int>> &rooms, int x, int y) {
        int dis = rooms[x][y];
        for (vector<int> &dir : dirs) {
            int i = x + dir[0], j = y + dir[1];
            if (i < 0 || i >= (int)rooms.size() || j < 0 || j >= (int)rooms[0].size())
                continue;
            if (rooms[i][j] <= dis + 1) // either this room is obstacle or a gate, or it is closer to another gate, or it is on the path back
                continue;
            rooms[i][j] = dis + 1;
            dfs(rooms, i, j);
        }
    }

    vector<vector<int>> dirs;
};

int main() {
    Solution sol;

    vector<vector<int>> rooms = {
        {INT_MAX, -1, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, -1},
        {0, -1, INT_MAX, INT_MAX}
    };

    sol.wallsAndGates(rooms);
    for (vector<int> &row : rooms) {
        for (int &i : row)
            cout << i << "\t";
        cout << endl;
    }

    return 0;
}
