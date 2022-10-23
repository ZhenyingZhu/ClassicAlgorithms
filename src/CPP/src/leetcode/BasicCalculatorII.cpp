/*
 * [Source] https://leetcode.com/problems/basic-calculator-ii/
 * [Difficulty]: Medium
 * [Tag]: String
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// [Solution]: When * or / comes, first compute. At the end, compute all + and -. Notice cannot compute in the order of stack. Need compute 1+2-3 from left to right. So the right thing to do is actually when next operator is not higher than previous operator, compute previous operator first. Otherwise compute next first.
// [Corner Case]:
class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if (len == 0)
            return 0;

        stack<long> vals;
        stack<char> ops;
        int i = 0;
        while (i < len) {
            switch(s[i]) {
                case ' ' : ++i;
                           break;
                case '+' :
                case '-' :
                case '*' :
                case '/' : ops.push(s[i++]);
                           break;
                default  : {
                               long val = 0;
                               while (s[i] >= '0' && s[i] <= '9') {
                                   val = val * 10 + s[i++] - '0';
                               }
                               computeMultiple(val, vals, ops);
                               break;
                           }
            }
        }

        computeAddition(vals, ops);
        return vals.top();
    }

    void computeMultiple(long val, stack<long>& vals, stack<char>& ops) {
        if (vals.empty() || ops.top() == '+' || ops.top() == '-') {
            vals.push(val);
            return;
        }

        while (!ops.empty() && (ops.top() == '*' || ops.top() == '/') ) {
            char op = ops.top();
            ops.pop();

            long pre = vals.top();
            vals.pop();
            val = op == '*' ? pre * val : pre / val;
        }
        vals.push(val);
    }

    void computeAddition(stack<long>& oriVals, stack<char>& oriOps) {
        stack<long> vals;
        while (!oriVals.empty()) {
            vals.push(oriVals.top());
            oriVals.pop();
        }
        stack<char> ops;
        while (!oriOps.empty()) {
            ops.push(oriOps.top());
            oriOps.pop();
        }

        long val = vals.top();
        vals.pop();
        while (!ops.empty()) {
            char op = ops.top();
            ops.pop();
cout << op << endl;

            long nxt = vals.top();
            vals.pop();
            val = op == '+' ? val + nxt : val - nxt;
cout << nxt << op << val << endl;
        }
        oriVals.push(val);
    }
};

// [Solution]: Always use two stacks. When find a op with lower priority then previous os, use another stack to get all ops that are higher than the up comming one, and compute.
/* Java solution

 */

int main() {
    Solution sol;
    cout << sol.calculate(" 13+5 / 2*3 ") << endl;
    //cout << sol.calculate(" 1-1+1 ") << endl;
    //cout << sol.calculate("0-2147483647") << endl;

    return 0;
}
