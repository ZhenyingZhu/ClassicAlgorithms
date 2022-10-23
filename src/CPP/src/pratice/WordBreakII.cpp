#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

// [Source]: https://leetcode.com/problems/word-break-ii/
// http://www.1point3acres.com/bbs/thread-227554-1-1.html

class SolutionDFS {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        if (s.empty() || wordDict.empty())
            return {};

        unordered_set<string> dict;
        int minLen = INT_MAX, maxLen = 0;
        for (string &word : wordDict) {
            int len = word.length();
            minLen = min(minLen, len);
            maxLen = max(maxLen, len);
            dict.insert(word);
        }

        vector<string> partial;
        vector<string> res;
        helper(s, 0, partial, dict, minLen, maxLen, res);
        return res;
    }

    void helper(string &s, int st, vector<string> &partial, unordered_set<string> &dict, int minLen, int maxLen, vector<string> &res) {
        int sLen = s.length();
        if (st == sLen) {
            res.push_back(constructString(partial));
            return;
        }

        for (int len = minLen; len <= maxLen && st + len <= sLen; ++len) {
            string candidate = s.substr(st, len);
            if (dict.count(candidate)) {
                partial.push_back(candidate);
                helper(s, st + len, partial, dict, minLen, maxLen, res);
                partial.pop_back();
            }
        }
    }

    string constructString(vector<string> &partial) {
        if (partial.empty())
            return "";
        string res = partial[0];
        for (int i = 1; i < (int)partial.size(); ++i) {
            res += " " + partial[i];
        }
        return res;
    }
};

// [Solution]: DP
class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        if (s.empty() || wordDict.empty())
            return {};

        int minLen = INT_MAX, maxLen = 0;
        unordered_set<string> dict;
        for (string &word : wordDict) {
            minLen = min((int)word.length(), minLen);
            maxLen = max((int)word.length(), maxLen);
            dict.insert(word);
        }

        unordered_map<int, vector<string>> stVecMap;
        return helper(s, 0, dict, minLen, maxLen, stVecMap);
    }

    vector<string> helper(string &s, int st, unordered_set<string> &dict, int minLen, int maxLen, unordered_map<int, vector<string>> &stVecMap) {
        if (st == (int)s.length())
            return {""};
        if (stVecMap.count(st))
            return stVecMap[st];

        vector<string> res;
        for (int len = minLen; len <= maxLen && st + len <= (int)s.length(); ++len) {
            string candidate = s.substr(st, len);
            if (!dict.count(candidate))
                continue;

            vector<string> partials = helper(s, st + len, dict, minLen, maxLen, stVecMap);
            if (partials.empty())
                continue; // left part cannot form any word break
            for (string &partial : partials) {
                if (partial.empty())
                    res.push_back(candidate); // the last word
                else
                    res.push_back(candidate + " " + partial);
            }
        }
        stVecMap[st] = res;
        return res;
    }
};

int main() {
    Solution sol;

    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    for (string &str : sol.wordBreak("catsanddog", wordDict))
        cout << "|" << str << "|" << endl;

    return 0;
}
