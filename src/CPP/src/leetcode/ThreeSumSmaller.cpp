/*
 * [Source] https://leetcode.com/problems/3sum-smaller/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Two Pointers
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: While do 2 sum, count the smaller sums between st and ed when nums[st] + nums[ed] < target
// [Corner Case]:
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;

        sort(nums.begin(), nums.end());

        int count = 0;
        for (int i = 0; i <= (int)nums.size() - 3; ++i) {
            count += helper(nums, target - nums[i], i + 1);
        }
        return count;
    }

    int helper(vector<int> &nums, int target, int st) {
        int count = 0;
        int ed = nums.size() - 1;
        while (st < ed) {
            int sum = nums[st] + nums[ed];
            if (sum < target) {
                count += ed - st; // nums[pre], nums[st] and nums[st + 1 to ed]
                ++st;
            } else {
                --ed;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    //vector<int> nums = {-2, 0, 1, 3};
    //cout << sol.threeSumSmaller(nums, 2) << endl;
    vector<int> nums = {0, 1, 2, 3, 4};
    //for (int i = 3; i <= 9; ++i)
    int i = 6;
        cout << i << ": " << sol.threeSumSmaller(nums, i) << endl;

    return 0;
}
