#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/wildcard-matching/
// http://www.1point3acres.com/bbs/thread-220333-1-1.html

// [Solution]: if p[j] == '*', D[i][j] = D[x][j-1] where x from 0 to i. if D[i-1][x] is true
class SolutionDP {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));

        dp[0][0] = true;
        // if s is empty, p is *, it should still match
        for (int i = 0; i < pLen; ++i) {
            if (p[i] == '*')
                dp[0][i + 1] = dp[0][i];
            else
                break; // all nexts are false
        }

        for (int i = 0; i < sLen; ++i) {
            for (int j = 0; j < pLen; ++j) {
                if (p[j] != '*') {
                    if (p[j] == '?' || s[i] == p[j]) {
                        dp[i + 1][j + 1] = dp[i][j];
                    } else {
                        dp[i + 1][j + 1] = false;
                    }
                } else {
                    for (int k = i + 1; k >= 0; --k) {
                        if (dp[k][j]) {
                            dp[i + 1][j + 1] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[sLen][pLen];
    }
};

// [Solution]: if previous strings are match, and a star appears, no need to compare back to positions before this star
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        int sp = 0, pp = 0;
        int star = -1, match = 0;
        while (sp < sLen) {
            if (pp < pLen && (p[pp] == '?' || p[pp] == s[sp])) {
                ++pp;
                ++sp;
            } else if (pp < pLen && p[pp] == '*') {
                star = pp++;
                match = sp;
            } else if (star != -1) {
                pp = star + 1;
                sp = ++match;
            } else {
                return false;
            }
        }
        while (p[pp] == '*')
            ++pp;
        return pp == pLen;
    }
};

int main() {
    Solution sol;

    cout << sol.isMatch("", "**") << endl;
    cout << sol.isMatch("", "*?") << endl;
    cout << sol.isMatch("cab", "c*a*b") << endl;
    cout << sol.isMatch("cabb", "c*a*b") << endl;
    cout << sol.isMatch("cabab", "c*a*b") << endl;
    cout << sol.isMatch("cabab", "c*c*") << endl;

    return 0;
}
