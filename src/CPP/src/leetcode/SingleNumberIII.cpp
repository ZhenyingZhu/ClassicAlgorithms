/*
 * [Source] https://leetcode.com/problems/single-number-iii/
 * [Difficulty]: Medium
 * [Tag]: Bit Manipulation
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: First pass XOR all numbers to find XOR of results. The 1 bits in the XOR mean the different bits in two results. So XOR all numbers in the array that have this bit set to 1 can find one result.
// [Corner Case]:
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() % 2 != 0)
            return {};

        int xorSum = 0;
        for (int& num : nums)
            xorSum ^= num;

        int firstDiff = 1;
        int tmp = xorSum;
        while ( (tmp & 1) == 0 ) {
            firstDiff = firstDiff << 1;
            tmp = tmp >> 1;
        }

        int firstVal = 0;
        for (int& num : nums) {
            if ( (num & firstDiff) > 0 )
                firstVal ^= num;
        }

        int secondVal = xorSum ^ firstVal;
        return {firstVal, secondVal};
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> res = sol.singleNumber(nums);
    for (int& n : res)
        cout << n << " ";
    cout << endl;

    return 0;
}
