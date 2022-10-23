/*
 * [Source] https://leetcode.com/problems/find-peak-element/
 * [Difficulty]: Medium
 * [Tag]: Binary Search
 * [Tag]: Array
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// [Solution]: If the mid is still increasing, there must be a peak afterward.
// [Corner Case]: only 1 element
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return INT_MIN;
        if (len == 1) // to asure isPeak and increasing check don't need consider this case
            return 0;

        int st = 0, ed = len - 1;
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            if (isPeak(md, nums))
                return md;

            if (increasing(md, nums)) {
                st = md;
            } else {
                ed = md;
            }
        }

        if (nums[st] > nums[ed]) {
            return st;
        } else {
            return ed;
        }
    }

private:
    bool isPeak(int md, const vector<int>& nums) {
        if (md == 0)
            return nums[md] > nums[md + 1];
        if (md == (int)nums.size() - 1)
            return nums[md] > nums[md - 1];
        return nums[md] > nums[md - 1] && nums[md] > nums[md + 1];
    }

    bool increasing(int md, const vector<int>& nums) {
        if (md == 0)
            return nums[md] < nums[md + 1];
        if (md == (int)nums.size())
            return false;
        return nums[md] > nums[md - 1] && nums[md] < nums[md + 1];
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/sortandsearch/FindPeakElement.java
 */

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 1};
    cout << sol.findPeakElement(nums) << endl;

    return 0;
}
