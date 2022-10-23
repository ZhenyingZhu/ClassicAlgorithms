#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Source]: https://leetcode.com/problems/combination-sum/
// http://www.1point3acres.com/bbs/thread-226078-1-1.html

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            partial.push_back(candidates[i]);
            helper(candidates, i, partial, target - candidates[i], res);
            partial.pop_back();
        }
    }
};

int main() {
    Solution sol;

    vector<int> candidates = {2, 3, 6, 7};
    for (vector<int> &vec : sol.combinationSum(candidates, 7)) {
        for (int &n : vec)
            cout << n << ", ";
        cout << endl;
    }

    return 0;
}
