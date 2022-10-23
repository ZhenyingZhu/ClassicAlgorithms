/*
 * [Source] https://leetcode.com/problems/move-zeroes/
 * [Difficulty]: Easy
 * [Tag]: Array
 * [Tag]: Two Pointers
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ed = -1;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0)
                nums[++ed] = nums[i];
        }

        ++ed;
        for (; ed < (int)nums.size(); ++ed)
            nums[ed] = 0;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);

    for (int& num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
