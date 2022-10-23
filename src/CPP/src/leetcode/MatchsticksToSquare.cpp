/*
 * [Source] https://leetcode.com/problems/matchsticks-to-square/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// [Solution]: Sort the array from large to small. Then backtracking. Remove used elements and do it 3 times
// [Corner Case]:
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4)
            return false;

        long sum = 0;
        for (int &num : nums)
            sum += num;
        if (sum % 4 != 0)
            return false;

        sort(nums.begin(), nums.end(), greater<int>()); // sort so that remove sticks become easy
        long target = sum / 4;
        for (int i = 0; i < 3; ++i) {
            vector<int> sticks;
            if (!helper(nums, target, sticks, 0))
                return false;

            // remove used sticks from stick set
            vector<int> tmp;
            int stickPt = 0;
            for (int &num : nums) {
                if (stickPt < (int)sticks.size() && num == sticks[stickPt]) {
                    ++stickPt;
cout << num << " ";
                } else {
                    tmp.push_back(num);
                }
            }
cout << endl;
            swap(nums, tmp);
        }

        return true;
    }

    bool helper(vector<int> &nums, long target, vector<int> &sticks, int idx) {
        if (target == 0)
            return true;

        if (idx == (int)nums.size())
            return false;

        for (int i = idx; i < (int)nums.size(); ++i) {
            sticks.push_back(nums[i]);
            if ( helper(nums, target - nums[i], sticks, i + 1) )
                return true;
            sticks.pop_back();
        }
        return false;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    //vector<int> nums = {1,1,2,2,2};
    //vector<int> nums = {3,3,3,3,4};
    vector<int> nums = {5,5,5,5,4,4,4,4,3,3,3,3};
    cout << sol.makesquare(nums) << endl;

    return 0;
}
