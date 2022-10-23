/*
 * [Source] https://leetcode.com/problems/house-robber/
 * [Difficulty]: Easy
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// [Solution]: Backtracking use hash table. rob[i] means max profit when reach home i rob[i] = rob[i+1] + nums[i] or rob[i + 2]
// [Corner Case]: i+2 might exceed boundary
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        unordered_map<int, int> idxMoney;
        return rob(nums, 0, idxMoney);
    }

private:
    int rob(vector<int>& nums, int idx, unordered_map<int, int>& map) {
        if (idx >= (int)nums.size())
            return 0;

        int hash = idx;
        if (map.find(hash) != map.end())
            return map[hash];

        int notRobThisOne = rob(nums, idx + 1, map);
        int robThisOne = rob(nums, idx + 2, map) + nums[idx];
        int maxProf = max(notRobThisOne, robThisOne);
        map[hash] = maxProf;
        return maxProf;
    }
};

// [Solution]: DP. rob[i] = max(rob[i-1], rob[i-2]+nums[i])
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 2, 1};
    cout << sol.rob(nums) << endl;

    return 0;
}
