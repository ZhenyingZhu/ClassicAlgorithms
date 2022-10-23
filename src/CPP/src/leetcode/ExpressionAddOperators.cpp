/*
 * [Source] https://leetcode.com/problems/expression-add-operators/
 * [Difficulty]: Hard
 * [Tag]: Divide and Conquer
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// [Solution]: Backing track(or so call DFS). The idea is that each recursive call deal with a number, add, minus or multiple with previous results. For multiple, maintain a varible that can be distract from result and compute this variable multiple current number and add back to the result
// [Corner Case]: numbers like 01, 002, are invalid
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.size() == 0)
            return res;

        helper(num, (long)target, 0, "", 0, res);
        return res;
    }

    void helper(string num, long target, long carry, string formular, long mulTemp, vector<string>& res) {
        // mulTemp is used to compute multiple. 1+2*3 = (1+2) - 2 + 2*3; 1*2*3 = (1*2) - (1*2) + 1*2*3
        // Actually carry here is useless, can removed
        if (num.size() == 0 && target == 0) {
            res.push_back(formular);
            return;
        }

        for (size_t i = 1; i <= 10 && i <= num.size(); ++i) { // INT_MAX length is 10
            if (num[0] == '0' && i > 1)
                return; // numbers start with 0 are invalid

            string operandStr = num.substr(0, i);
            long operand = stol(operandStr);

            string left = num.substr(i);
            if (formular.size() == 0) {
                helper(left, target - operand, operand, operandStr, operand, res); // the first number always add to the formular
            } else {
                helper(left, target - operand, carry + operand, formular + "+" + operandStr, operand, res);
                helper(left, target + operand, carry - operand, formular + "-" + operandStr, -operand, res);

                int newMulTemp = mulTemp * operand; // mulTemp is the value of previous continus multiple
                int mulCarry = carry - mulTemp + newMulTemp; // carry is the value of the whole previous fumular
                int mulTarget = target + mulTemp - newMulTemp; // notice mulCarry first minus mulTmp, which means target needs add it back
                helper(left, mulTarget, mulCarry, formular + "*" + operandStr, newMulTemp, res);
            }
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //for (string& str : sol.addOperators("123", 6)) {
    //for (string& str : sol.addOperators("232", 8)) {
    //for (string& str : sol.addOperators("105", 5)) {
    for (string& str : sol.addOperators("00", 0)) {
        cout << str << endl;
    }

    return 0;
}
