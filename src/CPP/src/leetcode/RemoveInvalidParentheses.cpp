/*
 * [Source] https://leetcode.com/problems/remove-invalid-parentheses/
 * [Difficulty]: Hard
 * [Tag]: Depth-first Search
 * [Tag]: Breadth-first Search
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// [Solution]: Brute force DFS, iterate through all possible value, and then pick those longest results.
// [Corner Case]: Since there are other chars, need to make sure 1. not out of length, 2. those chars need to be removed for each try
class SolutionSelf {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> valid;

        vector<char> pre;
        helper(s, 0, pre, 0, 0, valid);

        int maxLen = 0;
        for (int i = 0; i < (int)valid.size(); ++i) {
            maxLen = max((int)valid[i].length(), maxLen);
        }

        vector<string> res;
        for (int i = 0; i < (int)valid.size(); ++i) {
            if ( (int)valid[i].length() == maxLen && find(res.begin(), res.end(), valid[i]) == res.end() )
                res.push_back(valid[i]);
        }
        return res;
    }

    void helper(string& s, int idx, vector<char>& pre, int lCnt, int rCnt, vector<string>& res) {
        if (lCnt < rCnt)
            return;

        if (idx >= (int)s.length()) {
            if (lCnt == rCnt) {
                res.push_back( string(pre.begin(), pre.end()) );
            }
            return;
        }

        int curLen = pre.size();

        while (idx < (int)s.length() && s[idx] != '(' && s[idx] != ')') {
            pre.push_back(s[idx]);
            ++idx;
        }

        // not add parenthese
        helper(s, idx + 1, pre, lCnt, rCnt, res);

        if (idx < (int)s.length()) {
            // add parenthese
            if (s[idx] == '(') {
                pre.push_back('(');
                helper(s, idx + 1, pre, lCnt + 1, rCnt, res);
            } else {
                pre.push_back(')');
                helper(s, idx + 1, pre, lCnt, rCnt + 1, res);
            }
        }

        pre.erase(pre.begin() + curLen, pre.end());
    }
};

// [Solution]: DFS
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftCnt = 0, rightCnt = 0; // invalid Parentheses that need to remove
        for (char &c : s) {
            if (c == '(') {
                ++leftCnt;
            } else if (c == ')') {
                if (leftCnt > 0)
                    --leftCnt;
                else
                    ++rightCnt;
            }
        }
        
        unordered_set<string> res;
        string prev;
        dfs(s, 0, prev, leftCnt, rightCnt, 0, res);
        return vector<string>(res.begin(), res.end());
    }

private:
    void dfs(string &s, int idx, string &prev, int leftCnt, int rightCnt, int openCnt, unordered_set<string> &res) {
        if (idx == (int)s.length()) {
            if (leftCnt == 0 && rightCnt == 0 && openCnt == 0)
                res.insert(prev);
            return;
        }

        // leftCnt is the left parenthese that should remove, openCnt is the number of ( that have not paired
        if (leftCnt < 0 || rightCnt < 0 || openCnt < 0)
            return;

        if (s[idx] == '(') {
            // not add (
            dfs(s, idx + 1, prev, leftCnt - 1, rightCnt, openCnt, res);
            // add
            prev.push_back('(');
            dfs(s, idx + 1, prev, leftCnt, rightCnt, openCnt + 1, res);
            prev.pop_back();
        } else if (s[idx] == ')') {
            dfs(s, idx + 1, prev, leftCnt, rightCnt - 1, openCnt, res);
            prev.push_back(')');
            dfs(s, idx + 1, prev, leftCnt, rightCnt, openCnt - 1, res);
            prev.pop_back();
        } else {
            prev.push_back(s[idx]);
            dfs(s, idx + 1, prev, leftCnt, rightCnt, openCnt, res);
            prev.pop_back();
        }
    }
};

int main() {
    Solution sol;

    vector<string> res = sol.removeInvalidParentheses("()())()");
    //vector<string> res = sol.removeInvalidParentheses("n");
    for (string& str : res)
        cout << str << endl;

    return 0;
}
