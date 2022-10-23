#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/decode-ways/
// http://www.1point3acres.com/bbs/thread-225949-1-1.html

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;

        int len = s.length();
        vector<int> dp(len + 1, 0);
        dp[0] = 1;

        if (!isdigit(s[0]) || s[0] == '0')
            return 0;
        dp[1] = 1;

        for (int i = 1; i < len; ++i) {
            if (!isdigit(s[i]))
                return 0;

            if (s[i] != '0') {
                dp[i + 1] = dp[i];
            }

            int num = computeNum(s, i - 1, i);
            if (num <= 26 && num >= 10) {
                dp[i + 1] += dp[i - 1];
            }

            if (dp[i + 1] == 0)
                return 0;
        }

        return dp.back();
    }

    int computeNum(string &s, int st, int ed) {
        int num = 0;
        for (int i = st; i <= ed; ++i) {
            num = num * 10 + s[i] - '0';
        }
        return num;
    }
};

int main() {
    Solution sol;

    cout << sol.numDecodings("12") << endl;
    cout << sol.numDecodings("10") << endl;
    cout << sol.numDecodings("101") << endl;
    cout << sol.numDecodings("01") << endl;
    cout << sol.numDecodings("100") << endl;
    cout << sol.numDecodings("30") << endl;

    return 0;
}
