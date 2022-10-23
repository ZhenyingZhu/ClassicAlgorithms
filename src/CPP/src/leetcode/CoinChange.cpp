/*
 * [Source] https://leetcode.com/problems/coin-change/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// [Solution]: DP
// [Corner Case]: when not able to create, need to return -1. Some amount cannot be computed, need skip those amounts
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> coinsNeed(amount + 1, -1);
        coinsNeed[0] = 0;
        for (int amt = 1; amt <= amount; ++amt) {
            int cnt = INT_MAX;
            for (int& denom : coins) {
                if (amt - denom >= 0 && coinsNeed[amt - denom] != -1)
                    cnt = min(cnt, coinsNeed[amt - denom] + 1);
            }
            if (cnt != INT_MAX)
                coinsNeed[amt] = cnt;
        }
        return coinsNeed[amount];
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<int> coins = {1, 2, 5};
    //cout << sol.coinChange(coins, 11) << endl;
    vector<int> coins = {2};
    cout << sol.coinChange(coins, 3) << endl;

    return 0;
}
