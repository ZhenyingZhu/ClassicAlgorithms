/*
 * [Source] https://leetcode.com/problems/house-robber-ii/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// [Solution]: Maintain two arrays, first rob nums[0], second rob nums[1]. So even the first array actually not use nums[0], we can still get the same value from the second array.
// [Corner Case]:
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 2) {
            int val = 0;
            for (int& num : nums)
                val = max(num, val);
            return val;
        }

        vector<int> robFirst(nums.size()), notRobFirst(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                robFirst[i] = nums[i];
                notRobFirst[i] = 0;
            } else if (i == 1) {
                robFirst[i] = robFirst[0];
                notRobFirst[i] = nums[i];
            } else if (i == nums.size() - 1) {
                robFirst[i] = robFirst[i - 1];
                notRobFirst[i] = max(notRobFirst[i - 1], notRobFirst[i - 2] + nums[i]);
            } else {
                robFirst[i] = max(robFirst[i - 1], robFirst[i - 2] + nums[i]);
                notRobFirst[i] = max(notRobFirst[i - 1], notRobFirst[i - 2] + nums[i]);
            }
        }

        return max(robFirst[nums.size() - 1], notRobFirst[nums.size() - 1]);
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<int> nums = {1, 2, 3};
    //vector<int> nums = {10, 1, 1, 1, 100};
    //vector<int> nums = {10, 1, 1, 100};
    vector<int> nums = {1, 1, 100, 1, 50};
    cout << sol.rob(nums) << endl;

    return 0;
}
