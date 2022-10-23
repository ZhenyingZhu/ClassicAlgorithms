/*
 * [Source] https://leetcode.com/problems/wiggle-subsequence/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 * [Tag]: Greedy
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Maintain two arrays. One is the previous longest subarray which need an increasing element at num i, another one need a decrease.
// [Corner Case]:
class SolutionSquare {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();

        int maxLen = 1;
        vector<int> increasing(nums.size(), 1);
        vector<int> decreasing(nums.size(), 1);
        for (int cur = 1; cur < (int)nums.size(); ++cur) {
            // checking decreasing to update increasing
            for (int incPre = 0; incPre < cur; ++incPre) {
                if (nums[incPre] < nums[cur]) {
                    increasing[cur] = max(decreasing[incPre] + 1, increasing[cur]);
                }
            }
            maxLen = max(increasing[cur], maxLen);

            // checking increasing to update decreasing
            for (int decPre = 0; decPre < cur; ++decPre) {
                if (nums[decPre] > nums[cur]) {
                    decreasing[cur] = max(increasing[decPre] + 1, decreasing[cur]);
                }
            }
            maxLen = max(decreasing[cur], maxLen);
        }

        return maxLen;
    }
};

// [Solution]: Notice if consective numbers are not increasing/decreasing, neither of them can be used as next wiggled elements until there is a turn. So only need to compare with the previous number.
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();

        int incLen = 1, decLen = 1;
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                incLen = decLen + 1;
            } else if (nums[i] < nums[i - 1]) {
                decLen = incLen + 1;
            }
        }

        return max(incLen, decLen);
    }
};

int main() {
    Solution sol;

    //vector<int> nums = {1,7,4,9,2,5};
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    cout << sol.wiggleMaxLength(nums) << endl;

    return 0;
}
