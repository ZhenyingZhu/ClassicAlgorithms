/*
 * [Source] https://leetcode.com/problems/target-sum/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// [Solution]: Brute force
// [Corner Case]:
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> sumCnt;
        sumCnt[0] = 1;
        for (int &num : nums) {
            unordered_map<int, int> tmpSumCnt;
            for (auto it = sumCnt.begin(); it != sumCnt.end(); ++it) {
                tmpSumCnt[it->first + num] += it->second;
                tmpSumCnt[it->first - num] += it->second;
            }
            swap(tmpSumCnt, sumCnt);
        }
        return sumCnt[S];
    }
};

// [Solution]: sum of the whole array = sum(positive) + sum(negative). Now to find sum(positive) - sum(negative) = S, so S + sum(total) = 2 * sum(positive). Now find how many ways to sum up to positive
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {1,1,1,1,1};
    cout << sol.findTargetSumWays(nums, 3) << endl;

    return 0;
}
