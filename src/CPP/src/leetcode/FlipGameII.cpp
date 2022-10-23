/*
 * [Source] https://leetcode.com/problems/flip-game-ii/
 * [Difficulty]: Medium
 * [Tag]: Backtracking
 */

#include <iostream>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    bool canWin(string s) {
        for (int i = 1; i < (int)s.length(); ++i) {
            if (s[i] == '+' && s[i] == s[i - 1]) {
                s[i - 1] = '-';
                s[i] = '-';
                if (!canWin(s))
                    return true;
                s[i] = '+';
                s[i - 1] = '+';
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    cout << sol.canWin("+++++") << endl;

    return 0;
}
