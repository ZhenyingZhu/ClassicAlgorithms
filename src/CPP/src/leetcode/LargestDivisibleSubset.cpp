/*
 * [Source] https://leetcode.com/problems/largest-divisible-subset/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 * [Tag]: Math
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Use DP with length of the subset.
// [Corner Case]:
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> preNumIdx(nums.size());
        vector<int> subsetLen(nums.size());

        int endIdx = -1, endLen = 0; // the last element of the subset
        for (int i = 0; i < (int)nums.size(); ++i) {
            int maxLen = 1;
            int pre = -1;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0) {
                    int len = subsetLen[j] + 1;
                    if (len > maxLen) {
                        pre = j;
                        maxLen = len;
                    }
                }
            }
            subsetLen[i] = maxLen;
            preNumIdx[i] = pre;

            if (maxLen > endLen) {
                endLen = maxLen;
                endIdx = i;
            }
        }

        vector<int> res;
        while (endIdx != -1) {
            res.push_back(nums[endIdx]);
            endIdx = preNumIdx[endIdx];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {2, 4, 6, 12, 16};
    for (int &num : sol.largestDivisibleSubset(nums))
        cout << num << " ";
    cout << endl;

    return 0;
}
