#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// [Source]: https://leetcode.com/problems/shortest-distance-from-all-buildings
// http://www.1point3acres.com/bbs/thread-226130-1-1.html

class Solution {
public:
    int shortestDistance(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty())
            return -1;

        dirs = {-1, 0, 1, 0, -1};
        m = grid.size();
        n = grid[0].size();

        int passNum = 0;
        vector<vector<int>> distanceSum(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    bfs(grid, i, j, passNum, distanceSum);
                    --passNum;
                }
            }
        }

        int minDistance = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distanceSum[i][j] != 0 && grid[i][j] == passNum)
                    minDistance = min(minDistance, distanceSum[i][j]);
            }
        }
        return minDistance == INT_MAX ? -1 : minDistance;
    }

    void bfs(vector<vector<int>> &grid, int stX, int stY, int passNum, vector<vector<int>> &distanceSum) {
        queue<int> q;
        q.push( encode(stX, stY) );

        int distance = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                vector<int> coor = decode( q.front() );
                q.pop();

                int x = coor[0], y = coor[1];
                distanceSum[x][y] += distance;

                for (int d = 0; d < 4; ++d) {
                    int newX = x + dirs[d], newY = y + dirs[d + 1];
                    if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] != passNum)
                        continue;
                    grid[newX][newY]--;

                    int code = encode(newX, newY);
                    q.push(code);
                }
            }
            ++distance;
        }
    }

    int encode(int x, int y) {
        return x * n + y;
    }

    vector<int> decode(int code) {
        return {code / n, code % n};
    }

    vector<int> dirs;
    int m, n;
};

int main() {
    Solution sol;

    /*
    vector<vector<int>> grid = {
        {1,0,2,0,1},
        {0,0,0,0,0},
        {0,0,1,0,0}
    };
    */
    vector<vector<int>> grid = {
        {1,1},{0,1}
    };
    cout << sol.shortestDistance(grid) << endl;

    return 0;
}
