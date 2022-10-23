/*
 * [Source] https://leetcode.com/problems/dungeon-game/
 * [Difficulty]: Hard
 * [Tag]: Binary Search
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// [Solution]: From the end deduct to begining. Tracking how many HP is needed to get to next cell. Depends on the supply on current cell, t least 1, at most next cell required + current cell required.
// [Corner Case]:
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int height = dungeon.size(), width = dungeon[0].size();
        vector<vector<int>> minHPNeeded(height, vector<int>(width, 1));

        minHPNeeded[height - 1][width - 1] = getMinRequiredHP(dungeon[height - 1][width - 1], 1);
        for (int i = height - 2; i >= 0; --i)
            minHPNeeded[i][width - 1] = getMinRequiredHP(dungeon[i][width - 1], minHPNeeded[i + 1][width - 1]);
        for (int j = width - 2; j >= 0; --j)
            minHPNeeded[height - 1][j] = getMinRequiredHP(dungeon[height - 1][j], minHPNeeded[height - 1][j + 1]);

        for (int i = height - 2; i >= 0; --i) {
            for (int j = width - 2; j >= 0; --j) {
                int rightPathNeed = getMinRequiredHP(dungeon[i][j], minHPNeeded[i][j + 1]);
                int downPathNeed = getMinRequiredHP(dungeon[i][j], minHPNeeded[i + 1][j]);
                minHPNeeded[i][j] = min(rightPathNeed, downPathNeed);
            }
        }

        return minHPNeeded[0][0];
    }

private:
    int getMinRequiredHP(int currentCellSupply, int nextCellRequire) {
        if (currentCellSupply >= nextCellRequire)
            return 1;
        return nextCellRequire - currentCellSupply;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    cout << sol.calculateMinimumHP(dungeon) << endl;

    return 0;
}
