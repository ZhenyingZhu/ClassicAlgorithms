#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// [Source]: special case https://leetcode.com/problems/matchsticks-to-square/
// http://www.1point3acres.com/bbs/thread-225081-1-1.html

class Solution {
public:
    vector<vector<int>> distribute(vector<int> &nums, int k) {
        int sum = 0;
        for (int &num : nums)
            sum += num;
        if (sum % k > 0)
            return {};
        sort(nums.begin(), nums.end(), greater<int>());

        int target = sum / k;
        vector<vector<int>> res;
        while (!nums.empty()) {
//for (int num : nums) cout << num << " "; cout << endl;
            vector<int> tmp = helper(nums, target);
            if (tmp.empty())
                return {}; // cannot form target
            res.push_back(tmp);
        }
        return res;
    }

    vector<int> helper(vector<int> &nums, int target) {
        vector<bool> used(nums.size(), false);
        if (!dfs(nums, 0, used, target))
            return {}; // cannot construct target

        vector<int> left;
        vector<int> bucket;
        for (int i = 0; i < (int)used.size(); ++i) {
            if (used[i])
                bucket.push_back(nums[i]);
            else
                left.push_back(nums[i]);
        }
        swap(left, nums);
        return bucket;
    }

    bool dfs(vector<int> &nums, int idx, vector<bool> &used, int target) {
        if (target < 0)
            return false;
        if (target == 0)
            return true;

        for (int i = idx; i < (int)used.size(); ++i) {
            used[i] = true;
            if (dfs(nums, i + 1, used, target - nums[i]))
                return true;
            used[i] = false;
        }
        return false;
    }
};

int main() {
    Solution sol;

    //vector<int> nums = {1,1,1,1,2,1,5};
    //vector<int> nums = {4,4,4,3,3};
    vector<int> nums = {5,5,5,5,4,4,4,4,3,3,3,3};
    for (vector<int> &vec : sol.distribute(nums, 4)) {
        for (int &num : vec)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
