/*
 * [Source] https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
 * [Difficulty]: Medium
 * [Tag]: Math
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Use medium, so that half of the numbers add, and another half minus
// [Corner Case]:
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        int md = nums[nums.size() / 2];

        int sum = 0;
        for (int &num : nums) {
            sum += abs(num - md);
        }
        return sum;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {1,2,3};
    cout << sol.minMoves2(nums) << endl;

    return 0;
}
