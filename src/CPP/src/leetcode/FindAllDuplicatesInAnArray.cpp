/*
 * [Source] https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * [Difficulty]: Medium
 * [Tag]: Array
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.empty())
            return {};

        int idx = 0;
        while (idx < (int)nums.size()) {
            int num = nums[idx];
            if (num == idx + 1) {
                ++idx;
            } else if (nums[idx] == nums[num - 1]) {
                ++idx;
            } else {
                swap(nums[idx], nums[num - 1]);
            }
        }
for (int &n : nums) cout << n << " "; cout << endl;
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] != i + 1)
                res.push_back(nums[i]);
        }
        return res;
    }
};

// [Solution]: No need to bucket sort. Just tag that cell. The easist way is to set the cell number to be negative

int main() {
    Solution sol;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    for (int &i : sol.findDuplicates(nums))
        cout << i << " ";
    cout << endl;

    return 0;
}
