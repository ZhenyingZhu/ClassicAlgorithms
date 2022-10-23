/*
 * [Source] https://leetcode.com/problems/output-contest-matches
 * [Difficulty]: Medium
 * [Tag]: Recursion
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    string findContestMatch(int n) {
        string res;
        helper(1, 2, n, res);
        return res;
    }

    void helper(int st, int total, int n, string &res) {
        res.push_back('(');
        if (total == n) {
            res += to_string(st) + "," + to_string(total + 1 - st);
        } else {
            helper(st, total * 2, n, res);
            res.push_back(',');
            helper(total + 1 - st, total * 2, n, res);
        }
        res.push_back(')');
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.findContestMatch(2) << endl;

    return 0;
}
