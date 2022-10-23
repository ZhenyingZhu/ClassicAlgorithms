/*
 * [Source] https://leetcode.com/problems/longest-palindromic-subsequence
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
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int l = 0; l < len; ++l) {
            for (int st = 0; st < len - l; ++st) {
                int ed = st + l;
                if (st == ed) {
                    dp[st][ed] = 1;
                } else {
                    int pLen = max(dp[st + 1][ed], dp[st][ed - 1]);
                    if (s[st] == s[ed]) {
                        if (st + 1 == ed) {
                            pLen = max(pLen, 2);
                        } else {
                            pLen = max(pLen, dp[st + 1][ed - 1] + 2);
                        }
                    }
                    dp[st][ed] = pLen;
                }
            }
        }
        return dp[0][len - 1];
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //cout << sol.longestPalindromeSubseq("cbbd") << endl;
    cout << sol.longestPalindromeSubseq("bbbab") << endl;

    return 0;
}
