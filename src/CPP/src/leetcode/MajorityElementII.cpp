/*
 * [Source] https://leetcode.com/problems/majority-element-ii/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// [Solution]: The idea is to count the freq of numbers above average. If the result is c1 and c2, then other numbers are cx, and c1, c2 must show at lease 1 more times than cx. So when c1 apprears, c1++, when c2 appears, c2++, others, both c1 and c2--.
// [Corner Case]:
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1)
            return nums;

        vector<int> candidates(2, INT_MAX);
        vector<int> counts(2, 0);

        for (int i = 0; i < size; ++i) {
            if (nums[i] == candidates[0]) {
                ++counts[0];
            } else if (nums[i] == candidates[1]) {
                ++counts[1];
            } else if (counts[0] == 0) {
                candidates[0] = nums[i];
                ++counts[0];
            } else if (counts[1] == 0) {
                candidates[1] = nums[i];
                ++counts[1];
            } else {
                --counts[0];
                --counts[1];
            }
        }

        counts[0] = 0;
        counts[1] = 0;
        for (int i = 0; i < size; ++i) {
            if (nums[i] == candidates[0])
                ++counts[0];
            else if (nums[i] == candidates[1])
                ++counts[1];
        }

        vector<int> res;
        if (counts[0] > size / 3)
            res.push_back(candidates[0]);
        if (counts[1] > size / 3)
            res.push_back(candidates[1]);
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<int> nums = {1, 2, 3, 2, 3, 4, 4, 3, 4, 4};
    vector<int> nums = {8, 8, 7, 7, 7};
    //vector<int> nums = {1, 2, 3, 2, 3, 4, 4, 3, 4, 4};
    for (int& i : sol.majorityElement(nums))
        cout << i << " ";
    cout << endl;

    return 0;
}
