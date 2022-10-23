/*
 * [Source] https://leetcode.com/problems/generalized-abbreviation/
 * [Difficulty]: Medium
 * [Tag]: Backtracking
 * [Tag]: Bit Manipulation
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: the number is incurmulate even after 10. Notice to remove duplication, only need to abbr chars after the last number
// [Corner Case]:
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        res.push_back(word);
        helper("", word, 0, res);
        return res;
    }

    void helper(string prefix, string suffix, int repeat, vector<string> &res) {
        for (int i = 0; i < (int)suffix.length(); ++i) {
            if (i == 0) {
                string newSuffix = suffix.substr(1);
                res.emplace_back(prefix + to_string(repeat + 1) + newSuffix);
                helper(prefix, newSuffix, repeat + 1, res);
            } else {
                string num = repeat == 0 ? "" : to_string(repeat);
                string newPrefix = prefix + num + suffix.substr(0, i);
                string newSuffix = suffix.substr(i + 1);
                res.emplace_back(newPrefix + to_string(1) + newSuffix);
                helper(newPrefix, newSuffix, 1, res);
            }
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    for (string &str : sol.generateAbbreviations("word")) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
