/*
 * [Source] https://leetcode.com/problems/circular-array-loop/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Understand the question wrong, and the solution is also wrong. for example 1,2,3,4,5.
// [Corner Case]:
class SolutionWrong {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return false;

        // eliminate negative number and too large number
        for (int i = 0; i < len; ++i)
            nums[i] = (nums[i] + len) % len;

        for (int i = len - 1; i >= 0; --i) {
            if (nums[i] == 0)
                continue;

            if (i + nums[i] < len)
                nums[i] += nums[i + nums[i]];
            if (nums[i] % len == 0)
                return true;
        }
        return false;
    }
};

// [Solution]: Use two pointers. Since it says can only move forward or backward.
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (nums[i] % len == 0) { // visited or back to itself
                nums[i] = 0;
                continue;
            }

            int slow = i, fast = next(slow, nums);
            // make sure same direction
            while (nums[i] * nums[slow] > 0 && nums[i] * nums[fast] > 0) {
                if (slow == fast) {
                    if (nums[slow] % len == 0)
                        break;
                    return true;
                }
                slow = next(slow, nums);
                fast = next(next(fast, nums), nums);
            }

            int run = i;
            while (nums[run] != 0) {
                nums[run] = 0;
                run = next(run, nums);
            }
        }
        return false;
    }

    int next(int idx, vector<int> &nums) {
        int len = nums.size();
        return (idx + len + nums[idx]) % len;
    }
};

int main() {
    Solution sol;

    //vector<int> nums = {2, -1, 1, 2, 2};
    vector<int> nums = {-1, 2};
    cout << sol.circularArrayLoop(nums) << endl;

    return 0;
}
