/*
 * [Source] https://leetcode.com/problems/rotate-array/
 * [Difficulty]: Easy
 * [Tag]: Array
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Use O(k) space
// [Corner Case]:
class SolutionCopyToTmp {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;

        vector<int> tmp(nums.begin() + len - k, nums.end());
        for (int i = len - 1; i >= k; --i)
            nums[i] = nums[i - k];
        for (int i = 0; i < k; ++i)
            nums[i] = tmp[i];
    }
};

// [Solution]: In place, use reverse
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;

        reverse(nums.begin(), nums.begin() + len - k);
        reverse(nums.begin() + len - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {1,2};
    sol.rotate(nums, 3);
    for (int num:nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
