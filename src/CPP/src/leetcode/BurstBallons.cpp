/*
 * [Source] https://leetcode.com/problems/burst-balloons/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 * [Tag]: Divide and Conquer
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: dp[i][j] means the max coins can make from breaking ballons between i to j, with ballons from 0 to i-1 and j+1 to n-1 are still untouched.
//             So dp[i][j] = max of when break ballon k with all ballons from i to k-1 and k+1 to j are all breaked already, coins[i-1]*coins[k]*coins[j+1] + dp[i][k-1]+dp[k+1][j]
// [Corner Case]:
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> coins;
        coins.push_back(1);
        for (int& num : nums)
            coins.push_back(num);
        coins.push_back(1);

        vector<vector<int>> maxFromIToJ(coins.size(), vector<int>(coins.size(), 0));
        for (int i = 1; i < (int)coins.size() - 1; ++i) {
            for (int j = 1; j < (int)coins.size() - i; ++j) {
                int left = j, right = i + j - 1;
                int maxCoins = 0;
                for (int k = left; k <= right; ++k) {
                    maxCoins = max(coins[left - 1] * coins[k] * coins[right + 1] + maxFromIToJ[left][k - 1] + maxFromIToJ[k + 1][right], maxCoins);
                }
                maxFromIToJ[left][right] = maxCoins;
            }
        }

for (vector<int>& row : maxFromIToJ) {
    for (int& num : row)
        cout << num << '\t';
    cout << endl;
}
cout << endl;

        return maxFromIToJ[1][coins.size() - 2];
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {3,1,5,8};
    cout << sol.maxCoins(nums) << endl;

    return 0;
}
