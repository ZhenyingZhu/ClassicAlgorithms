#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/find-the-duplicate-number
// http://www.1point3acres.com/bbs/thread-226722-1-1.html

class SolutionLinkedList {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = next(0, nums), fast = next(slow, nums);
        while (slow != fast) {
            slow = next(slow, nums);
            fast = next(next(fast, nums), nums);
        }

        fast = 0;
        while (slow != fast) {
            fast = next(fast, nums);
            slow = next(slow, nums);
        }
        return slow;
    }

    int next(int idx, vector<int> &nums) {
        return nums[idx];
    }
};

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int left = 1, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (noDup(mid, nums)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (noDup(left, nums))
            return right;
        return left;
    }

    bool noDup(int num, vector<int> &nums) {
        int cnt = 0;
        for (int n : nums) {
            if (n <= num)
                cnt++;
        }

        return cnt <= num;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 3, 1, 1};
    cout << sol.findDuplicate(nums) << endl;

    return 0;
}
