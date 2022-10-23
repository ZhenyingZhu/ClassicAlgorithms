/*
 * [Source] https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
 * [Difficulty]: Medium
 * [Tag]: Hash Table
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// [Solution]: Use hash table to store previous sum and use sums difference to check if equals k.
// [Corner Case]:
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> sumIdxMap;
        sumIdxMap[0] = -1;

        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            sum += nums[i];

            int target = sum - k;
            if (sumIdxMap.count(target)) {
                maxLen = max(i - sumIdxMap[target], maxLen);
            }

            if (!sumIdxMap.count(sum))
                sumIdxMap[sum] = i;
        }
        return maxLen;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {1, -1, 5, -2, 3};
    cout << sol.maxSubArrayLen(nums, 3) << endl;

    return 0;
}
