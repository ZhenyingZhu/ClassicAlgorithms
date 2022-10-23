/*
 * [Source] https://leetcode.com/problems/paint-house/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// [Solution]: Use a two demension DP. D[i][j]=min(D[i-1][x])+cost[i][j], where (x!=j)
// [Corner Case]:
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty())
            return 0;

        int num = costs.size(), colors = costs[0].size();
        vector<vector<int>> minSums( colors, vector<int>(num + 1, INT_MAX) );
        for (int i = 0; i < colors; ++i)
            minSums[i][0] = 0;

        for (int idx = 0; idx < num; ++idx) {
            for (int preColor = 0; preColor < colors; ++preColor) {
                update(minSums, preColor, idx, costs);
            }
        }

        int minCost = INT_MAX;
        for (int color = 0; color < colors; ++color) {
            minCost = min(minSums[color].back(), minCost);
        }
        return minCost;
    }

    void update(vector<vector<int>> &minSums, int preColor, int idx, vector<vector<int>> &costs) {
        for (int color = 0; color < (int)minSums.size(); ++color) {
            if (color == preColor)
                continue;
            minSums[color][idx + 1] = min(minSums[preColor][idx] + costs[idx][color], minSums[color][idx + 1]);
        }
    }
};

int main() {
    Solution sol;

    vector<vector<int>> costs = {
        {1, 2, 3},
        {4, 5, 6},
    };

    cout << sol.minCost(costs) << endl;

    return 0;
}
