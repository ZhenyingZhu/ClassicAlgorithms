#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-218628-2-1.html
// http://www.1point3acres.com/bbs/thread-226130-1-1.html

class Solution {
public:
    int waysKnightCanJump(vector<vector<int>> &grid, int m, int n, int step) {
        dirs = { {0, -1}, {0, 1} };
        int ways = 0;
        dfs(grid, m, n, 0, step, ways);
        return ways;
    }

    void dfs(vector<vector<int>> &grid, int x, int y, int k, int step, int &ways) {
        if (k == step) {
            ++ways;
            return;
        }

        for (int i = 0; i < (int)dirs.size(); ++i) {
            int newX = x + dirs[i][0], newY = y + dirs[i][1];
            if (newX < 0 || newX >= (int)grid.size() || newY < 0 || newY >= (int)grid[0].size() || grid[newX][newY] == 1)
                continue;

            dfs(grid, newX, newY, k + 1, step, ways);
        }
    }

    vector<vector<int>> dirs;
};

class SolutionForPos {
    // Wrong solution. It compute how many cells could be after k moves, not how many ways could be
    int positionsKnightCanJump(int m, int n, int step) {
        vector<unordered_set<int>> visited(step); // since can jump back to previous cell. just don't repeat compute same cell for same steps
        unordered_set<int> targets;
        dirs = {
            {-1, -2}, {-1, 2}, {1, -2}, {1, 2},
            {-2, -1}, {-2, 1}, {2, -1}, {2, 1}
        };

        helper(m, n, 0, step, visited, targets);
        return targets.size();
    }

    void helper(int x, int y, int k, int step, vector<unordered_set<int>> &visited, unordered_set<int> &targets) {
        if (k == step) {
            targets.insert(getIdx(x, y));
            return;
        }

        if (visited[k].count(getIdx(x, y))) {
            return;
        }

        visited[k].insert(getIdx(x, y));
        for (vector<int> &dir : dirs) {
            int newX = x + dir[0], newY = y + dir[1];
            if (newX < 0 || newX >= 8 || newY < 0 || newY >= 8)
                continue;
            helper(newX, newY, k + 1, step, visited, targets);
        }
    }

    int getIdx(int x, int y) {
        return x * 8 + y;
    }

    vector<vector<int>> dirs;
};

int main() {
    Solution sol;

    vector<vector<int>> grid = { {0,1,0,0,0} };
    for (int k = 1; k <= 3; ++k)
        cout << sol.waysKnightCanJump(grid, 0, 2, k) << endl;

    return 0;
}
