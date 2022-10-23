/*
 * [Source] https://leetcode.com/problems/best-meeting-point/
 * [Difficulty]: Hard
 * [Tag]: Math
 * [Tag]: Sort
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: It is Manhattan distance. So that median for both x and y is the point.
// [Corner Case]:
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int h = grid.size(), w = grid[0].size();
        vector<int> x, y;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] == 1) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }

        int xMinDis = getMin(x);
        int yMinDis = getMin(y);
        return xMinDis + yMinDis;
    }

    int getMin(vector<int> &pos) {
        sort(pos.begin(), pos.end());
        // use median as the meet point, as the to the points on both side a a point, the distances don't change, but we need all points to be on both side of a point.
        int i = 0, j = pos.size() - 1;
        int dis = 0;
        while (i < j) {
            dis += pos[j--] - pos[i++];
        }
        return dis;
    }
};

int main() {
    Solution sol;

    return 0;
}
