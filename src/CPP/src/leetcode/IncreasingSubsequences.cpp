/*
 * [Source] https://leetcode.com/problems/increasing-subsequences/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// [Solution]: Backtracking
// [Corner Case]:
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() <= 1)
            return res;

        vector<int> partial;
        helper(nums, 0, partial, res);
        return res;
    }

    void helper(vector<int> &nums, int idx, vector<int> &partial, vector<vector<int>> &res) {
        if (partial.size() >= 2)
            res.push_back(partial);

        unordered_set<int> used;
        for (int i = idx; i < (int)nums.size(); ++i) {
            if (used.count(nums[i]))
                continue;

            if (partial.empty() || partial.back() <= nums[i]) {
                used.insert(nums[i]);

                partial.push_back(nums[i]);
                helper(nums, i + 1, partial, res);
                partial.pop_back();
            }
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {4,6,7,7};
    for (vector<int> &vec : sol.findSubsequences(nums)) {
        for (int &i : vec)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
