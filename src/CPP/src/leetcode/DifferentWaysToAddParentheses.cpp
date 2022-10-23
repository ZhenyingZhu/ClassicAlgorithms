/*
 * [Source] https://leetcode.com/problems/different-ways-to-add-parentheses/
 * [Difficulty]: Medium
 * [Tag]: Divide and Conquer
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

// [Solution]: Cannot use backtracking because both first part and last part are combinations. So use divide and conquer.
// [Corner Case]:
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.length() == 0)
            return {0};

        vector<int> operands;
        vector<char> operators;
        parseString(input, operands, operators);

        return computeHelper(operands, operators, 0, operands.size() - 1);
    }

    vector<int> computeHelper(vector<int>& operands, vector<char>& operators, size_t st, size_t ed) {
        if (st == ed)
            return {operands[st]};

        vector<int> res;
        for (size_t md = st; md < ed; ++md) {
            vector<int> leftVals = computeHelper(operands, operators, st, md);
            vector<int> rightVals = computeHelper(operands, operators, md + 1, ed);
            for (int& leftVal : leftVals) {
                for (int& rightVal : rightVals) {
                    res.push_back(compute(leftVal, operators[md], rightVal));
                }
            }
        }
        return res;
    }

    int compute(int a, char op, int b) {
        if (op == '#')
            return b;
        if (op == '+')
            return a + b;
        if (op == '-')
            return a - b;
        if (op == '*')
            return a * b;
        return 0; // just make compiler not warning
    }

    void parseString(string& input, vector<int>& operands, vector<char>& operators) {
        string ops("+-*");

        size_t i = 0;
        while (i < input.length()) {
            int tmp = 0;
            while (i < input.length() && isdigit(input[i])) {
                tmp = tmp * 10 + input[i] - '0';
                ++i;
            }
            operands.push_back(tmp);

            if (i < input.length() && ops.find(input[i]) != string::npos) {
                operators.push_back(input[i]);
            }
            ++i;
        }
    }

    // [Solution]: It is wrong. The problem here is that it always combine previous with either cur, or cur op next. But there is cases that pre combined with the whole left part.
    void computeHelper(vector<int>& operands, vector<char>& operators, int st, int pre, vector<int>& res) {
        // Notice it should work with operators that have # at the first cell
cout << st << " " << pre << endl;
        if (st == (int)operands.size()) {
            res.push_back(pre);
            return;
        }
        if (st == (int)operands.size() - 1) {
            res.push_back( compute(pre, operators[st], operands[st]) );
            return;
        }

        int withoutNext = compute(pre, operators[st], operands[st]);
        computeHelper(operands, operators, st + 1, withoutNext, res);

        int curNext = compute(operands[st], operators[st + 1], operands[st + 1]);
        int withNext = compute(pre, operators[st], curNext);
        computeHelper(operands, operators, st + 2, withNext, res);
    }

    // [Solution]: It is wrong. The problem is that it consider the combinations before current as only single one.
    vector<int> backtracking(vector<int>& operands, vector<char>& operators, int st, unordered_map<int, vector<int>>& idxCombinations) {
        // Notice it is work for operators without # at first cell.
cout << st << endl;
        if (st == (int)operands.size())
            return {};
        if (st == (int)operands.size() - 1)
            return {operands.back()};
        if (st == (int)operands.size() - 2)
            return {compute(operands[st], operators[st], operands[st + 1])};

        if (idxCombinations.find(st) != idxCombinations.end())
            return idxCombinations[st];

        vector<int> res;

        vector<int> withoutNext = backtracking(operands, operators, st + 1, idxCombinations);
cout << st << " withoutNext " << withoutNext.size() << endl;
        for (int& val : withoutNext)
            res.push_back(compute(operands[st], operators[st], val));

        int cur = compute(operands[st], operators[st], operands[st + 1]);
        vector<int> withNext = backtracking(operands, operators, st + 2, idxCombinations);
cout << st << " withNext " << withNext.size() << endl;
        for (int& val :withNext)
            res.push_back(compute(cur, operators[st + 1], val));

        idxCombinations[st] = res;
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //for (int& val : sol.diffWaysToCompute("2-1-1"))
    for (int& val : sol.diffWaysToCompute("2*3-4*5"))
        cout << val << endl;

    return 0;
}
