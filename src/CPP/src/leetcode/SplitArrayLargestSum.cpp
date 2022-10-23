/*
 * [Source] https://leetcode.com/problems/split-array-largest-sum/
 * [Difficulty]: Hard
 * [Tag]: Binary Search
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// [Solution]: Standard DP.
// [Corner Case]:
class SolutionTimeout {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<int> sums(nums.size() + 1);
        sums[0] = 0;
        for (int i = 1; i <= (int)nums.size(); ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        // the max of the N sums before idx
        vector<vector<int>> maxNSumBeforeIdx(m, vector<int>(nums.size()));
        // 1 sum before idx
        for (int i = 0; i < (int)nums.size(); ++i)
            maxNSumBeforeIdx[0][i] = sums[i + 1];

        for (int n = 1; n < m; ++n) {
            for (int i = n; i < (int)nums.size(); ++i) {
                int minMaxSum = INT_MAX;
                for (int st = n; st <= i; ++st) {
                    int prevMaxSum = maxNSumBeforeIdx[n - 1][st - 1];
                    int curSum = sums[i + 1] - sums[st];
                    int maxSum = max(curSum, prevMaxSum);
                    minMaxSum = min(maxSum, minMaxSum);
                }
                maxNSumBeforeIdx[n][i] = minMaxSum;
            }
        }
        return maxNSumBeforeIdx.back().back();
    }
};

// [Solution]: Use binary on guess result.
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int maxNum = 0, sum = 0;
        for (int &num : nums) {
            maxNum = max(num, maxNum);
            sum += num;
        }

        return binarySearch(nums, m, maxNum, sum);
    }

    int binarySearch(vector<int> &nums, int pieces, long lowSum, long highSum) {
        while (lowSum + 1 < highSum) {
            long midSum = (lowSum + highSum) / 2;
            if (sumTooSmall(nums, pieces, midSum))
                lowSum = midSum;
            else
                highSum = midSum;
        }

        if (!sumTooSmall(nums, pieces, lowSum))
            return lowSum;
        return highSum;
    }

    bool sumTooSmall(vector<int> &nums, int pieces, long targetSum) {
        int pieceCnt = 0;
        int sum = 0;
        for (int &num : nums) {
            sum += num;
            if (sum > targetSum) {
                ++pieceCnt;
                sum = num;

                // only this amount of pieces, there are still some numbers left that need to be sum up
                if (pieceCnt > pieces)
                    return true;
            }
        }
        // the last piece
        if (pieceCnt + 1 > pieces)
            return true;
        // if pieceCnt is smaller than pieces, it means we can divide some pieces into more pieces
        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {7, 2, 5, 10, 8};
    cout << sol.splitArray(nums, 2) << endl;

    return 0;
}
