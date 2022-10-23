/*
 * [Source] https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
 * [Difficulty]: Easy
 * [Tag]: Math
 */

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

// [Solution]: Add one on n-1 elements equals to substract one from 1 element.
// [Corner Case]:
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minVal = INT_MAX;
        int sum = 0;
        for (int &num : nums) {
            minVal = min(minVal, num);
            sum += num;
        }

        return sum - (int)nums.size() * minVal;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {1,2,3};
    cout << sol.minMoves(nums) << endl;

    return 0;
}
