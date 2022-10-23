/*
 * [Source] https://leetcode.com/problems/basic-calculator/
 * [Difficulty]: Hard
 * [Tag]: Stack
 * [Tag]: Math
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// [Solution]: Use a stack.
// [Corner Case]: while checking each char, don't forget there are numbers with more than 1 digits...
class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if (len == 0)
            return 0;

        stack<int> vals;
        stack<char> ops;

        int i = 0;
        while (i < len) {
            switch(s[i]) {
                case ' ' : ++i;
                           break;
                case ')' : {
                               ++i;
                               ops.pop(); // should be )
                               int val = vals.top();
                               vals.pop();
                               compute(val, vals, ops);
                               break;
                           }
                case '(' : ++i;
                           ops.push('(');
                           break;
                case '+' : ++i;
                           ops.push('+');
                           break;
                case '-' : ++i;
                           ops.push('-');
                           break;
                default  : {
                               int val = 0;
                               while (i < len && s[i] >= '0' && s[i] <= '9') {
                                   val = 10 * val + s[i] - '0';
                                   ++i;
                               }
                               compute(val, vals, ops);
                               break;
                           }
            }
        }
        return vals.top();
    }

    void compute(int val, stack<int>& vals, stack<char>& ops) {
        if (ops.empty() || ops.top() == '(') {
            vals.push(val);
            return;
        }

        int pre = vals.top();
        vals.pop();

        char op = ops.top();
        ops.pop();
        if (op == '+') {
            vals.push(pre + val);
        } else {
            vals.push(pre - val);
        }
    }
};

// [Solution]: Not compute until reach the end or ')'
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.calculate("(11+(4+5+2)-3)+(6+8)") << endl;

    return 0;
}
