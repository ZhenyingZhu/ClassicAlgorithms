/*
 * [Source] https://leetcode.com/problems/unique-substrings-in-wraparound-string/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// [Solution]: Hardest part is to dedup. Use end char and the length to do that. So if previously bc showed up, now abc shows, only substr abc needs to count. No need to count b, c, and bc.
// [Corner Case]:
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (p.empty())
            return 0;

        vector<int> dp(p.size());
        unordered_map<char, int> endCharLasting;

        int cnt = 0;
        for (int i = 0; i < (int)p.size(); ++i) {
            if ( i == 0 ) {
                dp[i] = 1;
            } else if ( p[i] - p[i - 1] == 1 || (p[i] == 'a' && p[i - 1] == 'z') ) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }

            if (endCharLasting[p[i]] < dp[i]) {
                cnt += dp[i] - endCharLasting[p[i]];
                endCharLasting[p[i]] = dp[i];
            }
        }

        return cnt;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    //cout << sol.findSubstringInWraproundString("cac") << endl;
    cout << sol.findSubstringInWraproundString("zab") << endl;

    return 0;
}
