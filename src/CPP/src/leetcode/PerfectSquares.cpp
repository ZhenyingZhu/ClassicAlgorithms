/*
 * [Source] https://leetcode.com/problems/perfect-squares/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Progarmming
 * [Tag]: Breadth-first Search
 * [Tag]: Math
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int numSquares(int n) {
        if (n <= 0)
            return 0;

        while (n % 4 == 0) // then each square in the result divide by 4 can be the new result
            n /= 4;

        if (n % 8 == 7) // http://math.stackexchange.com/questions/268402/prove-that-odd-perfect-square-is-congruent-to-1-modulo-8
            return 4;

        vector<int> candidates;
        for (int i = 1; i * i <= n; ++i)
            candidates.push_back(i * i);
        reverse(candidates.begin(), candidates.end());

        int least = 4; // Lagrange's four-square theorem
        vector<int> vec;
        helper(n, candidates, 0, vec, least);

        return least;
    }

    void helper(int sum, vector<int>& candidates, int idx, vector<int>& vec, int& least) {
        if (sum == 0) {
            for (int& num : vec)
                cout << num << "+";
            cout << endl;
            least = min(least, (int)vec.size());
            return;
        }

        if ((int)vec.size() > least)
            return;

        for (int i = idx; i < (int)candidates.size(); ++i) {
            if (candidates[i] > sum)
                continue;

            vec.push_back(candidates[i]);
            helper(sum - candidates[i], candidates, i, vec, least);
            vec.pop_back();
        }
    }
};

// [Solution]: Use BFS where squares are elements and level is the step
// [Solution]: Backpack
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.numSquares(12) << endl;
    cout << sol.numSquares(13) << endl;
    cout << sol.numSquares(1535) << endl;

    return 0;
}
