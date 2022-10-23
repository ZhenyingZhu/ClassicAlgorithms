/*
 * [Source] https://leetcode.com/problems/encode-string-with-shortest-length/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Store strings in DP cells. DP[i][j] means the encode of string from s[i] to s[j]. DP[i][j] = min(DP[i][k]+DP[k+1][j]) or n * DP[i][x], if s[i-x] is repeated
// [Corner Case]:
class Solution {
public:
    string encode(string s) {
        int len = s.length();
        vector<vector<string>> dp( len, vector<string>(len) );
        for (int width = 1; width <= len; ++width) { // the width of the substring
            for (int st = 0; st <= len - width; ++st) {
                int ed = st + width - 1;
                string full = s.substr(st, width);
                dp[st][ed] = collapse(s, st, width, dp);

                for (int md = st; md < ed; ++md) {
                    if (dp[st][md].length() + dp[md + 1][ed].length() < dp[st][ed].length()) {
                        dp[st][ed] = dp[st][md] + dp[md + 1][ed];
                    }
                }
            }
        }
for (auto &vec:dp) for (auto &s:vec) cout << s << "\t"; cout << endl;
        return dp[0][len - 1];
    }

    string collapse(string &s, int st, int width, vector<vector<string>> &dp) {
        string full = s.substr(st, width);
        int len = full.length();
        if (len <= 4)
            return full; // aaaa is no longer than 4[a]

        string tmp = full + full;
        int pos = tmp.find(full, 1); // abababab find abab returns 2, which means abab can be collapse to ab 2 times
        if (pos == len)
            return full; // cannot collapse
        return to_string(len / pos) + "[" + dp[st][st + pos - 1] + "]";
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.encode("abbbabbbcabbbabbbc") << endl;

    return 0;
}
