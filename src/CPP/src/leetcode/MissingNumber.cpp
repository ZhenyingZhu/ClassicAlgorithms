/*
 * [Source] https://leetcode.com/problems/missing-number/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Add all numbers up and compare to the expected value.
// [Corner Case]:
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expected = 0, actually = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            expected += i;
            actually += nums[i];
        }
        expected += (int)nums.size();

        return expected - actually;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
