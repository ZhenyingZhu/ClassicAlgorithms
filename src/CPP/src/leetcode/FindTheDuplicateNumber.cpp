/*
 * [Source] https://leetcode.com/problems/find-the-duplicate-number/
 * [Difficulty]: Hard
 * [Tag]: Binary Search
 * [Tag]: Array
 * [Tag]: Two Pointer
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Use binary search on range not vector element.
class SolutionBS {
public:
    int findDuplicate(vector<int>& nums) {
        int st = 1, ed = nums.size() - 1; // range from 1 to n
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            if ( numCount(nums, md) > md )
                ed = md;
            else
                st = md;
        }

        if ( numCount(nums, st) > st )
            return st;
        return ed;
    }

    int numCount(vector<int>& nums, int target) {
        int cnt = 0;
        for (int& num : nums) {
            if (num <= target)
                ++cnt;
        }
        return cnt;
    }
};

// [Solution]: Well, sort and count. But it modify the array so not okay.
class SolutionSoEasy {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] == nums[i - 1])
                return nums[i];
        }
        return INT_MAX;
    }
};

// [Solution]: Take it as linked list, which link each number from nums[number]. Since range is 1 to n, it means nums[0] never link to itself. Also the duplicate element must create a cycle
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int slow = nums[0], fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5, 2};
    cout << sol.findDuplicate(nums) << endl;

    return 0;
}
