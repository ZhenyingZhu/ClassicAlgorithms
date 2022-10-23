/*
 * [Source] https://leetcode.com/problems/max-consecutive-ones-ii/
 * [Difficulty]: Medium
 * [Tag]: Two Pointers
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Use first part and second part. If there are more than one 0 between, first becomes 0.
// [Corner Case]: all 1 array
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;

        int first = 0, second = 0;
        int zeroCnt = 0;
        for (int &num : nums) {
            if (num == 1) {
                if (zeroCnt > 1)
                    first = 0;
                zeroCnt = 0;

                ++second;
            } else {
                res = max(res, first + 1 + second);

                first = second;
                second = 0;

                ++zeroCnt;
            }
        }

        // if the array is all 1, no place to flip 0
        return min((int)nums.size(), max(res, first + 1 + second));
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<int> nums = {1,0,1,1,0};
    //vector<int> nums = {1,1};
    vector<int> nums = {0,1,1,1,0,0,1,1,1,1};
    cout << sol.findMaxConsecutiveOnes(nums) << endl;

    return 0;
}
