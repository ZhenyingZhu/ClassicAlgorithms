#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// [Source]: https://leetcode.com/problems/word-break/
// http://www.1point3acres.com/bbs/thread-225060-1-1.html

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        if (s.empty())
            return true;
        if (wordDict.empty())
            return false;

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int len = s.length();
        vector<bool> canBreak(len + 1, false);
        canBreak[0] = true;
        for (int ed = 0; ed < len; ++ed) {
            for (int st = ed; st >= 0; --st) {
                string candidate = s.substr(st, ed - st + 1);
                if (dict.count(candidate) && canBreak[st]) {
                    canBreak[ed + 1] = true;
                    break;
                }
            }
        }
        return canBreak[len];
    }
};

int main() {
    Solution sol;

    vector<string> wordDict = {"leet", "code"};
    cout << sol.wordBreak("leetcode", wordDict) << endl;

    return 0;
}
