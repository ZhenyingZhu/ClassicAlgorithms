#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// [Source]: https://leetcode.com/problems/paint-house-ii/
// http://www.1point3acres.com/bbs/thread-224947-1-1.html

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty())
            return 0;

        int firstMin = 0, secondMin = 0;
        int preColor = -1;
        for (int i = 0; i < (int)costs.size(); ++i) {
            int curFirstMin = INT_MAX, curColor = -1;
            for (int j = 0; j < (int)costs[0].size(); ++j) {
                int tmpVal;
                if (j == preColor) {
                    tmpVal = secondMin + costs[i][j];
                } else {
                    tmpVal = firstMin + costs[i][j];
                }
                if (tmpVal < curFirstMin) {
                    curFirstMin = tmpVal;
                    curColor = j;
                }
            }

            int curSecondMin = INT_MAX;
            for (int j = 0; j < (int)costs[0].size(); ++j) {
                if (j == curColor)
                    continue;

                int tmpVal;
                if (j == preColor) {
                    tmpVal = secondMin + costs[i][j];
                } else {
                    tmpVal = firstMin + costs[i][j];
                }
                if (tmpVal < curSecondMin) {
                    curSecondMin = tmpVal;
                }
            }

            firstMin = curFirstMin;
            secondMin = curSecondMin;
            preColor = curColor;
        }
        return firstMin;
    }
};

int main() {
    Solution sol;

    //vector<vector<int>> costs = {{99,1},{100,20}};
    vector<vector<int>> costs = {
        {{14,18,16},{18,4,9},{2,20,2},{4,19,10},{7,13,4},{11,4,17},{10,11,20},{8,3,16},{4,17,15},{8,7,3},{1,19,4},{12,11,18},{10,5,6},{14,19,19},{5,8,12},{12,16,13},{20,8,16},{17,15,2},{14,2,20},{2,6,14},{3,17,17},{17,8,3},{16,8,4},{7,14,8},{13,3,7},{15,11,14},{19,20,10},{4,2,6}}
        /*
        {11,20,4,3,19,3,18,17,6,8,18,18},{6,14,13,4,8,12,16,4,14,15,11,12},
        {8,1,4,20,19,9,12,11,13,12,1,3},{8,12,9,3,1,14,3,16,12,13,4,10},
        {17,1,1,5,17,10,20,15,3,9,18,3},{16,3,18,11,1,16,3,10,19,6,11,13}
        */
    };
    cout << sol.minCostII(costs) << endl;

    return 0;
}
