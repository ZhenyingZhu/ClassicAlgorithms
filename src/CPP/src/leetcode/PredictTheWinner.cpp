/*
 * [Source] https://leetcode.com/problems/predict-the-winner/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 * [Tag]: Minmax
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// [Solution]: DP use an integer to present if a number is used or not, then value to store the first hand score and the second hand sore
// [Corner Case]:
class Solution {
public:
    struct Scores {
        int first;
        int second;
    };

    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() <= 1)
            return true;

        unordered_map<int, Scores> dp;
        vector<bool> used(nums.size(), false);
        Scores s = helper(nums, used, dp);
        return s.first >= s.second;
    }

    Scores helper(vector<int> &nums, vector<bool> &used, unordered_map<int, Scores> &dp) {
        int key = convert(used);
        if (dp.count(key))
            return dp[key];

        int frontIdx = 0;
        for (; frontIdx < (int)used.size() && used[frontIdx]; ++frontIdx);
        if (frontIdx == (int)used.size()) { // all number picked
            dp[key] = {0, 0};
            return {0, 0};
        }

        int backIdx = used.size() - 1;
        for (; backIdx >= 0 && used[backIdx]; --backIdx);
        if (backIdx == frontIdx) {
            dp[key] = {nums[frontIdx], 0};
            return {nums[frontIdx], 0};
        }

        used[frontIdx] = true;
        Scores pickFront = helper(nums, used, dp);
        int frontFirst = pickFront.second + nums[frontIdx], frontSecond = pickFront.first;
        used[frontIdx] = false;

        used[backIdx] = true;
        Scores pickBack = helper(nums, used, dp);
        int backFirst = pickBack.second + nums[backIdx], backSecond = pickBack.first;
        used[backIdx] = false;

        Scores tmp = {0, 0};
        if (frontFirst > backFirst) {
            tmp = {frontFirst, frontSecond};
        } else {
            tmp = {backFirst, backSecond};
        }

        dp[key] = tmp;
        return tmp;
    }

    int convert(vector<bool> &used) {
        int res = 0;
        for (int i = 0; i < (int)used.size(); ++i) {
            if (used[i])
                res |= 1 << i;
        }
        return res;
    }
};

// [Solution]: DP, D[i][j] is the max money first player can get. If pick i, next player's can pick i+1 or j. Since he is play wisely, we can only pick the min value. So D[i][j]= 1. num[i] + min(D[i+1][j-1], D[i+2][j]), or 2. num[j] + min(D[i+1][j-1], D[i][j-2]). Find the max.
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {1,5,233,7};
    cout << sol.PredictTheWinner(nums) << endl;

    return 0;
}
