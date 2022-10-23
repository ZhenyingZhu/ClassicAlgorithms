/*
 * [Source] https://leetcode.com/problems/ones-and-zeroes/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if (strs.empty())
            return 0;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string &str : strs) {
            int zeros = 0, ones = 0;
            for (char &c : str) {
                if (c == '0')
                    ++zeros;
                else if (c == '1')
                    ++ones;
            }

            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    cout << sol.findMaxForm(strs, 5,3) << endl;

    return 0;
}
