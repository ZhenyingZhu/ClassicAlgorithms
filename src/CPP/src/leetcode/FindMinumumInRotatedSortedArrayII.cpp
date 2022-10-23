/*
 * [Source] https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 * [Difficulty]: Hard
 * [Tag]: Array
 * [Tag]: Binary Search
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: If min[md] == min[ed] scan st to ed.
// [Corner Case]: Since ed = md - 1, there might be a case when st is the result but exit the wile loop already
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
            return nums[0];

        int st = 0, ed = len - 1;
        while (st < ed) {
            int md = st + (ed - st) / 2;
            if (isMin(md, nums))
                return nums[md];

            if (nums[md] < nums[ed]) {
                ed = md - 1;
            } else if (nums[md] > nums[ed]) {
                st = md + 1;
            } else {
                return findMin(st, ed, nums);
            }
        }

        return nums[st];
    }

private:
    bool isMin(int idx, const vector<int>& nums) {
        int pre = idx == 0 ? nums.size() - 1 : idx - 1;
        return nums[idx] < nums[pre];
    }

    int findMin(int st, int ed, const vector<int>& nums) {
        int minVal = nums[st];
        for (int i = st + 1; i <= ed; ++i)
            minVal = min(nums[i], minVal);
        return minVal;
    }
};

// [Solution]: A better template to deal with BS
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/sortandsearch/FindMinimumInRotatedSortedArrayDup.java
 */

int main() {
    Solution sol;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << sol.findMin(nums) << endl;

    return 0;
}
