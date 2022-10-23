/*
 * [Source] https://leetcode.com/problems/max-consecutive-ones/
 * [Difficulty]: Easy
 * [Tag]: Array
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int res = 0;
        for (int &num : nums) {
            if (num == 1)
                ++cnt;
            else {
                res = max(res, cnt);
                cnt = 0;
            }
        }
        return max(res, cnt);
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {1,1,0,1,1,1};
    cout << sol.findMaxConsecutiveOnes(nums) << endl;

    return 0;
}
