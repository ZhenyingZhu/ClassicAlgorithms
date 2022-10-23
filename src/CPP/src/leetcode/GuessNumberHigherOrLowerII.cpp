/*
 * [Source] https://leetcode.com/problems/guess-number-higher-or-lower-ii/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// [Solution]: The idea is find the min money for guessing numbers between i to j. If we guess k, the worse case we need pay k + max(dp[i][k - 1], dp[k+1][j]). Find a k to make the result smallest.
// [Corner Case]:
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> moneyFromItoJ(n + 1, vector<int>(n + 1, 0));
        for (int ed = 2; ed <= n; ++ed) {
            // when st = ed, already find the result, money is 0
            // when st = ed - 1, always guess st. this cell is used by next DP
            moneyFromItoJ[ed - 1][ed] = ed - 1;

            for (int st = ed - 2; st >= 1; --st) {
                int totalMin = INT_MAX;
                for (int guess = st; guess < ed; ++guess) {
                    int tempMin = guess + max( moneyFromItoJ[st][guess - 1],  moneyFromItoJ[guess + 1][ed] );
                    totalMin = min(tempMin, totalMin);
                }
                moneyFromItoJ[st][ed] = totalMin;
            }
        }
        return moneyFromItoJ[1][n];
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.getMoneyAmount(4) << endl;

    return 0;
}
