/*
 * [Source] https://leetcode.com/problems/minimum-size-subarray-sum/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Two Pointers
 * [Tag]: Binary Search
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// [Solution]: Use two pointers to implement sliding window.
// [Corner Case]: When result not exist, return 0.
class Solution {
public:
    int minSubArrayLenLinearTimeComplexity(int s, vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;

        int st = 0, ed = 1;
        int sum = 0;
        int minLen = INT_MAX;
        while (ed <= len) {
            sum += nums[ed - 1];
            while (sum >= s) {
                minLen = min(ed - st, minLen);
                sum -= nums[st];
                ++st;
            }
            ++ed;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }

// [Solution]: Use sum from 0 to j minus sum from 0 to i to compute the min len. It makes a sorted array from the original array. Then for each element, binary search its successors. O(nlogn).
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        vector<int> sums(len + 1);

        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sums[i] = sum;
            sum += nums[i];
        }
        sums[len] = sum;

        int minLen = INT_MAX;
        for (int i = 0; i < len; ++i) {
            int pos = binarySearch(s + sums[i], sums, i + 1);
            if (pos != INT_MAX) {
                minLen = min(pos - i, minLen);
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }

private:
    int binarySearch(int target, vector<int>& sums, int st) {
        int ed = sums.size() - 1;
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            if (sums[md] > target) {
                ed = md;
            } else if (sums[md] < target) {
                st = md;
            } else {
                return md;
            }
        }

        if (sums[st] >= target) {
            return st;
        } else if (sums[ed] >= target) {
            return ed;
        } else {
            return INT_MAX;
        }
    }
};

/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {2,3,1,2,4,3};
    cout << sol.minSubArrayLen(7, nums) << endl;

    return 0;
}
