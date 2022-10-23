#include <iostream>
#include <stack>

using namespace std;

// [Source]: https://leetcode.com/problems/longest-valid-parentheses/#/description
// http://www.1point3acres.com/bbs/thread-226221-1-1.html

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty())
            return 0;

        int maxLen = 0;

        stack<int> leftParPos;
        leftParPos.push(-1);
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == '(') {
                leftParPos.push(i);
            } else if (s[i] == ')') {
                if (leftParPos.size() == 1) {
                    // more ) than (, need clear the stack and replace -1 as this pos
                    while (!leftParPos.empty())
                        leftParPos.pop();
                    leftParPos.push(i);
                    continue;
                }

                leftParPos.pop();
                maxLen = max(maxLen, i - leftParPos.top());
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sol;

    cout << sol.longestValidParentheses("()((())") << endl;
    cout << sol.longestValidParentheses("()())") << endl;
    cout << sol.longestValidParentheses("()(())") << endl;
    cout << sol.longestValidParentheses(")()())()()(") << endl;

    return 0;
}
