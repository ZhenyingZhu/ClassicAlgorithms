#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/search-for-a-range/
// http://www.1point3acres.com/bbs/thread-225497-1-1.html

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
            return {-1, -1};

        int st = searchLower(nums, target, 0, nums.size() - 1);
        if (st == -1)
            return {-1, -1};

        int ed = searchUpper(nums, target, st, nums.size() - 1);
        return {st, ed};
    }

    int searchLower(vector<int> &nums, int target, int st, int ed) {
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            if (nums[md] < target) {
                st = md;
            } else {
                ed = md;
            }
        }
        if (nums[st] == target)
            return st;
        if (nums[ed] == target)
            return ed;
        return -1;
    }

    int searchUpper(vector<int> &nums, int target, int st, int ed) {
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            if (nums[md] > target) { // when num[md] == target, needs going right
                ed = md;
            } else {
                st = md;
            }
        }
        if (nums[ed] == target)
            return ed;
        return st;
    }
};
