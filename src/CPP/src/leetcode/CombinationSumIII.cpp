/*
 * [Source] https://leetcode.com/problems/combination-sum-iii/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Backtracking
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> partial;
        sumHelper(1, partial, k, n, res);
        return res;
    }

    void sumHelper(int st, vector<int>& partial, int size, int sum, vector<vector<int>>& res) {
        if ((int)partial.size() == size - 1) {
            if (sum >= st && sum <= 9) {
                partial.push_back(sum);
                res.push_back(partial);
                partial.pop_back();
            }
            return;
        }

        for (int i = st; i < sum; ++i) {
            partial.push_back(i);
            sumHelper(i + 1, partial, size, sum - i, res);
            partial.pop_back();
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<vector<int>> res = sol.combinationSum3(3, 7);
    vector<vector<int>> res = sol.combinationSum3(3, 9);
    for (vector<int>& vec : res) {
        for (int& num : vec)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
