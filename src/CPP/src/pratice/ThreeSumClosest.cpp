#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// [Source]: https://leetcode.com/problems/3sum-closest/
// http://www.1point3acres.com/bbs/thread-224520-1-1.html

class SolutionTwoPointer {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int size = nums.size();
        if (size < 3)
            return 0;

        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;

        for (int i = 0; i < size - 2; ++i) {
            int targetSum = target - nums[i];
            int left = i + 1, right = size - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == targetSum)
                    return target;

                if (sum > targetSum) {
                    if (sum - targetSum < abs(minDiff)) {
                        minDiff = sum - targetSum;
                    }
                    --right;
                } else {
                    if (targetSum - sum < abs(minDiff)) {
                        minDiff = sum - targetSum;
                    }
                    ++left;
                }
            }
        }
        return target + minDiff;
    }
};

int main() {
    Solution sol;

    return 0;
}
