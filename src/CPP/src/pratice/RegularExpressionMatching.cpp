#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/regular-expression-matching/#/description
// http://www.1point3acres.com/bbs/thread-234909-1-1.html

// [Solution]: if p[i] = *, DP[i][j] = DP[i-2][x], where x+1 to j are all p[i-1].
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.length(), n = s.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < m; i++) {
            if (p[i] == '*' && dp[i - 1][0])
                dp[i + 1][0] = true;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i] == '*') {
                    int k = j;
                    for (; k >= 0 && (p[i - 1] == '.' || s[k] == p[i - 1]); k--) {
                        if (dp[i - 1][k + 1]) {
                            dp[i + 1][j + 1] = true;
                            break;
                        }
                    }
                    if (k >= -1 && dp[i - 1][k + 1])
                        dp[i + 1][j + 1] = true;

                    continue;
                }

                if (p[i] == '.' || p[i] == s[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    cout << sol.isMatch("aa", "a*") << endl;
    cout << sol.isMatch("ac", "ab*c") << endl;
    cout << sol.isMatch("abc", "ab*c") << endl;
    cout << sol.isMatch("abbc", "ab*c") << endl;
    cout << sol.isMatch("abcc", "ab*c") << endl;

    return 0;
}
