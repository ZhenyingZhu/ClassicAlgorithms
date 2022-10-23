/*
 * [Source] https://leetcode.com/problems/factor-combinations/
 * [Difficulty]: Medium
 * [Tag]: Backtracking
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Backtracking
// [Corner Case]: Notice the number itself should not included in the result
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        if (n <= 1)
            return {};

        vector<vector<int>> res;
        vector<int> prev;
        helper(n, prev, 2, res);
        res.pop_back(); // the last result is n itself
        return res;
    }

    void helper(int target, vector<int> &prev, int fac, vector<vector<int>> &res) {
        if (target == 1) {
            res.push_back(prev);
            return;
        }

        for (int i = fac; i <= target; ++i) {
            if (target % i == 0) {
                prev.push_back(i);
                helper(target / i, prev, i, res);
                prev.pop_back();
            }
        }
    }
};

int main() {
    Solution sol;

    for (vector<int> &vec : sol.getFactors(12)) {
        for (int &n : vec)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}
