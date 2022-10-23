#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/combination-sum-iii/
// http://www.1point3acres.com/bbs/thread-226078-1-1.html

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;

        vector<int> partial;
        helper(1, n, k, partial, res);
        return res;
    }

    void helper(int st, int target, int size, vector<int> &partial, vector<vector<int>> &res) {
        if ((int)partial.size() + 1 == size) {
            if (target <= 9) {
                partial.push_back(target);
                res.push_back(partial);
                partial.pop_back();
            }
            return;
        }

        for (int i = st; i <= 9 && 2 * i + 1 <= target; ++i) {
            partial.push_back(i);
            helper(i + 1, target - i, size, partial, res);
            partial.pop_back();
        }
    }
};

int main() {
    Solution sol;

    for (vector<int> &vec : sol.combinationSum3(3, 9)) {
        for (int &n : vec)
            cout << n << ", ";
        cout << endl;
    }

    return 0;
}
