/*
 * [Source] https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Two Pointers
 * [Tag]: Binary Search
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int idx1 = 0, idx2 = numbers.size() - 1;
        while (idx1 < idx2) {
            int sum = numbers[idx1] + numbers[idx2];
            if (sum == target) {
                return {idx1 + 1, idx2 + 1};
            } else if (sum < target) {
                ++idx1;
            } else {
                --idx2;
            }
        }

        return {-1, -1}; // should not reach here
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {2, 7, 11, 15};
    vector<int> res = sol.twoSum(nums, 9);
    cout << res[0] << "," << res[1] << endl;

    return 0;
}
