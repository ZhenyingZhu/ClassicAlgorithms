#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// [Source]: https://leetcode.com/problems/remove-invalid-parentheses/
// http://www.1point3acres.com/bbs/thread-203234-1-1.html

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> res;
        helper(s, 0, 0, {'(', ')'}, res);
        return vector<string>(res.begin(), res.end());
    }

    void helper(string &s, int lastLeft, int lastRight, vector<char> pars, unordered_set<string> &res) {
        int cnt = 0;
        for (int i = lastRight; i < (int)s.length(); ++i) {
            if (s[i] == pars[0])
                ++cnt;
            else if (s[i] == pars[1])
                --cnt;

            if (cnt >= 0)
                continue;

            for (int j = lastLeft; j <= i; ++j) {
                if (s[j] == pars[1]) {
                    string newCandidate = s.substr(0, j) + s.substr(j + 1);
                    helper(newCandidate, j, i, pars, res);
                }
            }
            return;
        }

        string reverseS = s;
        reverse(reverseS.begin(), reverseS.end());
        if (pars[0] == '(') {
            helper(reverseS, 0, 0, {')', '('}, res);
        } else {
            res.insert(reverseS);
        }
    }
};

int main() {
    Solution sol;

    //string par = "(a)())()";
    //string par = "(a(b(c)";
    string par = "(a)(b(c)";
    for (string &can : sol.removeInvalidParentheses(par))
        cout << can << endl;

    return 0;
}
