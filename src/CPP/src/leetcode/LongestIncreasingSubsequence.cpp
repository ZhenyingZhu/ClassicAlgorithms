/*
 * [Source] https://leetcode.com/problems/longest-increasing-subsequence/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 * [Tag]: Binary Search
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// [Solution]: Create an array indicates the last element of each length. Then we can do binary search.
// [Corner Case]:
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lastEles(nums.size() + 1, INT_MAX);
        lastEles[0] = INT_MIN;

        int len = 0;
        for (int& num : nums) {
            int idx = findLastSmaller(lastEles, num);
            lastEles[idx + 1] = num;
            len = max(idx + 1, len);
        }

        return len;
    }

    int findLastSmaller(vector<int>& lastEles, int target) {
        int st = 0, ed = lastEles.size() - 1;
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            int mid = lastEles[md];
            if (mid >= target) {
                ed = md;
            } else {
                st = md;
            }
        }

        if (lastEles[ed] < target)
            return ed;
        return st;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << sol.lengthOfLIS(nums) << endl;

    return 0;
}
