#include <iostream>
#include <vector>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-226130-1-1.html
// Simimar to http://www.1point3acres.com/bbs/thread-218628-1-1.html

class Solution {
public:
    // 1 dimension, can move left or right
    int simplestCase(vector<int> &grid, int st, int k) {
        int n = grid.size();
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            if (grid[i] == 1)
                dp[0][i] = 0;
            else
                dp[0][i] = 1;
        }

        for (int step = 1; step <= k; ++step) {
            for (int i = 0; i < n; ++i) {
                if (grid[i] == 1) {
                    dp[step][i] = 0;
                    continue;
                }
                if (i > 0)
                    dp[step][i] += dp[step - 1][i - 1];
                if (i < n - 1)
                    dp[step][i] += dp[step - 1][i + 1];
            }
        }
        return dp[k][st];
    }

    // 2d, can move 8 directions
    int possiblesAfterKStep(vector<vector<int>> &grid, int stX, int stY, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
        vector<vector<vector<int>>> stepReach(k + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        for (int step = 0; step <= k; ++step) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1)
                        continue;

                    // initialize
                    if (step == 0) {
                        stepReach[step][i][j] = 1;
                        continue;
                    }

                    for (int d = 0; d < 8; ++d) {
                        int newI = i + dirs[d][0], newJ = j + dirs[d][1];
                        if (newI < 0 || newI >= m || newJ < 0 || newJ >= n || grid[newI][newJ] == 1)
                            continue;
                        stepReach[step][i][j] += stepReach[step - 1][newI][newJ];
                    }
                }
            }
        }
        return stepReach[k][stX][stY];
    }
};

int main() {
    Solution sol;

    vector<int> grid = {0,1,0,0,0};
    for (int k = 1; k <= 3; ++k) {
        cout << sol.simplestCase(grid, 2, k) << endl;
    }

    /*
    vector<vector<int>> grid = {
        {1,0,0},
        {0,0,0},
        {0,0,0}
    };
    cout << sol.possiblesAfterKStep(grid, 0, 2, 2) << endl;
    */

    return 0;
}
