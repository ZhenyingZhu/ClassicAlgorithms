/*
 * [Source] https://leetcode.com/problems/shortest-distance-from-all-buildings/
 * [Difficulty]: Hard
 * [Tag]: Breadth-first Search
 */

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <utility>

using namespace std;

// [Solution]: BFS from all buildings, and compute the sum of distances to all buildings for each cell. A trick here is use a passNum. At first it is 0 as the questions suggest. Then reduce it by 1 after each bfs. So that next bfs only walks on those cells that previous nodes can reach. DFS will timeout.
// [Corner Case]: Notice when a cell is not reachable from all building, it cannot pick as the place. But it doesn't means there is no result
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return -1;

        dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int passNum = 0;
        vector<vector<int>> totalDis(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < (int)grid.size(); ++i) {
            for (int j = 0; j < (int)grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    vector<vector<int>> distances(grid.size(), vector<int>(grid[0].size(), 0));
                    bfs(grid, i, j, distances, passNum);
                    passNum--;
                    sum(distances, totalDis);
                }
            }

        }

        int minDis = INT_MAX;
        for (int i = 0; i < (int)grid.size(); ++i) {
            for (int j = 0; j < (int)grid[0].size(); ++j) {
                if (totalDis[i][j] == 0)
                    continue;
                minDis = min(totalDis[i][j], minDis);
            }
        }
        return minDis == INT_MAX ? -1 : minDis;
    }

    void bfs(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &distances, int passNum) {
        queue<pair<int, int>> q;
        q.push({x, y});

        while (!q.empty()) {
            int curX = q.front().first, curY = q.front().second;
            int dis = distances[curX][curY];
            q.pop();
            for (vector<int> &dir : dirs) {
                int i = curX + dir[0], j = curY + dir[1];
                if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size() || grid[i][j] != passNum)
                    continue;
                grid[i][j] = passNum - 1; // passNum also used as mark visit
                distances[i][j] = dis + 1;
                q.push({i, j});
            }
        }
    }

    void sum(vector<vector<int>> &distances, vector<vector<int>> &totalDis) {
        for (int i = 0; i < (int)totalDis.size(); ++i) {
            for (int j = 0; j < (int)totalDis[0].size(); ++j) {
                if (distances[i][j] == 0)
                    totalDis[i][j] = 0; // not reachable. Even it is reachable previously, set it to 0
                else
                    totalDis[i][j] += distances[i][j];
            }
        }
    }

    vector<vector<int>> dirs;
};

// [Solution]:
class SolutionT {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        return 1;
    }
};

int main() {
    Solution sol;

    
    vector<vector<int>> grids = {
        {1,0,2,0,1},
        {0,0,0,0,0},
        {0,0,1,0,0}
    };
    
    //vector<vector<int>> grids = {{1, 2, 0}};

    cout << sol.shortestDistance(grids) << endl;

    return 0;
}
