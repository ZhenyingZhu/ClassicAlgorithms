#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Source]: https://leetcode.com/problems/combination-sum-ii/
// http://www.1point3acres.com/bbs/thread-226078-1-1.html

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> partial;
        helper(candidates, 0, partial, target, res);
        return res;
    }

    void helper(vector<int> &candidates, int st, vector<int> &partial, int target, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(partial);
            return;
        }

        for (int i = st; i < (int)candidates.size() && candidates[i] <= target; ++i) {
            if (i > st && candidates[i] == candidates[i - 1])
                continue;

            partial.push_back(candidates[i]);
            helper(candidates, i + 1, partial, target - candidates[i], res);
            partial.pop_back();
        }
    }
};

int main() {
    Solution sol;

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    for (vector<int> &vec : sol.combinationSum2(candidates, 8)) {
        for (int &n : vec)
            cout << n << ", ";
        cout << endl;
    }

    return 0;
}
