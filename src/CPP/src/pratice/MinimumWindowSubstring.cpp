#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

// https://leetcode.com/problems/minimum-window-substring/
// http://www.1point3acres.com/bbs/thread-227305-1-1.html

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charCnt;
        for (char &c : t)
            charCnt[c]++;

        int minSt = 0;
        int minLen = INT_MAX;
        int st = 0;
        int appeared = 0;
        for (int i = 0; i < (int)s.length(); ++i) {
            if (!charCnt.count(s[i]))
                continue;

            if (charCnt[s[i]] > 0)
                ++appeared;
            charCnt[s[i]]--;

            while (appeared == (int)t.length()) {
                if (charCnt.count(s[st])) {
                    ++charCnt[s[st]];
                    if (charCnt[s[st]] > 0)
                        --appeared;
                }
                if (minLen > i - st + 1) {
                    minLen = i - st + 1;
                    minSt = st;
                }
                ++st;
            }
        }

        if (minLen == INT_MAX)
            return "";
        return s.substr(minSt, minLen);
    }
};

int main() {
    Solution sol;

    cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;

    return 0;
}
