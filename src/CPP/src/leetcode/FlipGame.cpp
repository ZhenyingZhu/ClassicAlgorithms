/*
 * [Source] https://leetcode.com/problems/flip-game/
 * [Difficulty]: Easy
 * [Tag]: String
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        for (int i = 1; i < (int)s.length(); ++i) {
            if (s[i] == s[i - 1] && s[i] == '+') {
                string tmp = s;
                tmp[i - 1] = (s[i] == '+' ? '-' : '+'); // Understood the question wrong
                tmp[i] = tmp[i - 1];
                res.push_back(tmp);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    for (string &s : sol.generatePossibleNextMoves("++++"))
        cout << s << endl;

    return 0;
}
