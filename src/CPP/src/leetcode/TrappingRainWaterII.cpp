/*
 * [Source] https://leetcode.com/problems/trapping-rain-water-ii/
 * [Difficulty]: Hard
 * [Tag]: Breadth-first Search
 * [Tag]: Heap
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

// [Solution]: From border, every time pick the shortest cell, raise the water plane use its height. BFS to its neighbors to see if they can fill some water under current water plane.
// [Corner Case]:
class Solution {
public:
    struct HeightCoordinate {
        int height;
        int x, y;
    };

    struct Greater {
        bool operator()(const HeightCoordinate &hc1, const HeightCoordinate &hc2) {
            return hc1.height > hc2.height;
        }
    };

    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty())
            return 0;
        int height = heightMap.size(), width = heightMap[0].size();

        priority_queue<HeightCoordinate, vector<HeightCoordinate>, Greater> shortCells;
        // push borders into queue
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        for (int i = 0; i < height; ++i) {
            shortCells.push( {heightMap[i][0], i, 0} );
            visited[i][0] = true;
            shortCells.push( {heightMap[i][width - 1], i, width - 1} );
            visited[i][width - 1] = true;
        }
        for (int j = 0; j < width; ++j) {
            shortCells.push( {heightMap[0][j], 0, j} );
            visited[0][j] = true;
            shortCells.push( {heightMap[height - 1][j], height - 1, j} );
            visited[height - 1][j] = true;
        }

        int totalWater = 0;
        int waterPlane = 0;
        // bfs
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!shortCells.empty()) {
            HeightCoordinate cell = shortCells.top();
            shortCells.pop();
            waterPlane = max(cell.height, waterPlane);

            for (vector<int> &dir : directions) {
                int x = cell.x + dir[0], y = cell.y + dir[1];
                if (x < 0 || x == height || y < 0 || y == width || visited[x][y])
                    continue;

                int height = heightMap[x][y];
                if (height < waterPlane) {
cout << x << "," << y << ": " << waterPlane << "-" << height << endl;
                    totalWater += waterPlane - height;
                }
                shortCells.push( {height, x, y} );
                visited[x][y] = true;
            }
        }

        return totalWater;
    }
};

// [Solution]: Not only four adjenct cells, but all the path to the border.
class SolutionWrong {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty())
            return 0;

        int height = heightMap.size(), width = heightMap[0].size();
        vector<vector<int>> minHeightOfSuround(height, vector<int>(width, INT_MAX));
        verticalSurround(heightMap, 0, height, width, minHeightOfSuround);
        verticalSurround(heightMap, height - 1, -1, width, minHeightOfSuround);
        horizentalSurround(heightMap, 0, width, height, minHeightOfSuround);
        horizentalSurround(heightMap, width - 1, -1, height, minHeightOfSuround);

        int water = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
cout << i << "," << j << ": " << minHeightOfSuround[i][j] << " " << heightMap[i][j] << endl;
                water += minHeightOfSuround[i][j] - heightMap[i][j];
            }
        }
        return water;
    }

    void verticalSurround(vector<vector<int>> &heightMap, int st, int ed, int cols, vector<vector<int>> &suround) {
        int unit = ed - st > 0 ? 1 : -1;
        for (int i = 0; i < cols; ++i) {
            int h = 0;
            for (int j = st; j != ed; j += unit) {
                h = max(heightMap[j][i], h);
                suround[j][i] = min(h, suround[j][i]);
            }
        }
    }

    void horizentalSurround(vector<vector<int>> &heightMap, int st, int ed, int rows, vector<vector<int>> &suround) {
        int unit = ed - st > 0 ? 1 : -1;
        for (int i = 0; i < rows; ++i) {
            int h = 0;
            for (int j = st; j != ed; j += unit) {
                h = max(heightMap[i][j], h);
                suround[i][j] = min(h, suround[i][j]);
            }
        }
    }
};

int main() {
    Solution sol;

    vector<vector<int>> heightMap = {
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}
    };
    cout << sol.trapRainWater(heightMap) << endl;

    return 0;
}
