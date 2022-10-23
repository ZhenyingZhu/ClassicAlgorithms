/*
 * [Source] https://leetcode.com/problems/paint-house-ii/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// [Solution]: O(n*k*k)
// [Corner Case]:
class SolutionNKK {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty())
            return 0;

        int houses = costs.size(), colors = costs[0].size();
        vector<vector<int>> houseColorOnce(houses, vector<int>(colors, INT_MAX));
        for (int i = 0; i < colors; ++i)
            houseColorOnce[0][i] = costs[0][i];

        for (int house = 1; house < houses; ++house) {
            for (int color = 0; color < colors; ++color) {
                updateUseOnce(houseColorOnce, house, color, costs, colors);
            }
        }

        int minCost = INT_MAX;
        for (int color = 0; color < colors; ++color) {
            minCost = min( minCost, houseColorOnce.back()[color] );
        }
        return minCost;
    }

    void updateUseOnce(vector<vector<int>> &houseColorOnce, int house, int preColor, vector<vector<int>> &costs, int colors) {
        for (int color = 0; color < colors; ++color) {
            if (color == preColor)
                continue;
            houseColorOnce[house][color] = min(houseColorOnce[house][color], houseColorOnce[house - 1][preColor] + costs[house][color]);
        }
    }
};

// [Solution]: O(n*k). Actually no need to keep all previous results. Only need a smallest cost, a second smallest cost and the color that leads to smallest cost
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty())
            return 0;

        int houses = costs.size(), colors = costs[0].size();

        int prevMinCost = 0, prevSecondMinCost = 0;
        int prevMinColor = -1;
        for (int house = 0; house < houses; ++house) {
            int minCost = INT_MAX;
            int minColor = 0;
            for (int color = 0; color < colors; ++color) {
                int curCost = costs[house][color];
                if (color == prevMinColor) {
                    if (minCost > prevSecondMinCost + curCost) {
                        minCost = prevSecondMinCost + curCost;
                        minColor = color;
                    }
                } else {
                    if (minCost > prevMinCost + curCost) {
                        minCost = prevMinCost + curCost;
                        minColor = color;
                    }
                }
            }

            int secondMinCost = INT_MAX;
            for (int color = 0; color < colors; ++color) {
                if (color == minColor)
                    continue;
                int curCost = costs[house][color];
                if (color == prevMinColor) {
                    secondMinCost = min(secondMinCost, prevSecondMinCost + curCost);
                } else {
                    secondMinCost = min(secondMinCost, prevMinCost + curCost);
                }
            }

            prevMinCost = minCost;
            prevSecondMinCost = secondMinCost;
            prevMinColor = minColor;
        }
        return prevMinCost;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> costs = {
        {1,2,3},
        {2,3,4},
        {3,4,5},
        {4,5,6}
    };

    cout << sol.minCostII(costs) << endl;

    return 0;
}
