#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// [Source]: https://leetcode.com/problems/basic-calculator/?tab=Description
// https://leetcode.com/problems/basic-calculator-ii/?tab=Description
// http://www.1point3acres.com/bbs/thread-229660-1-1.html

class Solution {
public:
    int calculate(string s) {
        unordered_map<char, int> priority;
        priority['+'] = 1;
        priority['-'] = 1;
        priority['*'] = 2;
        priority['/'] = 2;
        priority['('] = 0;

        stack<char> ops;
        stack<int> vals;
        int i = 0;
        while (i < (int)s.length()) {
            if (s[i] == ' ') {
                ++i;
                continue;
            }

            if (s[i] == '(') {
                ops.push(s[i++]);
                continue;
            }

            if (s[i] == ')') {
                while (ops.top() != '(') {
                    compute(ops, vals);
                }

                ops.pop(); // pop (
                ++i;
                continue;
            }

            if (isdigit(s[i])) {
                int val = 0;
                while (i < (int)s.length() && isdigit(s[i])) {
                    val = val * 10 + s[i++] - '0';
                }
                vals.push(val);
            } else {
                char op = s[i++];
                while (!ops.empty() && priority[op] <= priority[ops.top()]) {
                    compute(ops, vals);
                }
                ops.push(op);
            }
        }

        while (!ops.empty())
            compute(ops, vals);
        return vals.top();
    }

    void compute(stack<char> &ops, stack<int> &vals) {
        char op = ops.top();
        ops.pop();

        int val2 = vals.top();
        vals.pop();
        int val1 = vals.top();
        vals.pop();
        cout << val1 << op << val2 << endl;

        int val;
        switch(op) {
            case '+': val = val1 + val2;
                      break;
            case '-': val = val1 - val2;
                      break;
            case '*': val = val1 * val2;
                      break;
            case '/': val = val1 / val2;
                      break;
            default : cout << "Unrecognize op" << endl;
                      val = 0;
        }

        vals.push(val);
    }
};

int main() {
    Solution sol;

    //cout << sol.calculate("1 + 3*(2+3*2)") << endl;
    cout << sol.calculate("1*2-3/4+5*6-7*8+9/10") << endl;

    return 0;
}
