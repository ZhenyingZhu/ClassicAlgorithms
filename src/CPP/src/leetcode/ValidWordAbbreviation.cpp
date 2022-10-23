/*
 * [Source] https://leetcode.com/problems/valid-word-abbreviation/
 * [Difficulty]: Easy
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: don't forget move idx 1 ahead when finish compare a char
// [Corner Case]: abbr contains invalid number like 01
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int cnt = 0;
        int idx = 0;
        for (int i = 0; i < (int)abbr.length(); ++i) {
            if (isdigit(abbr[i])) {
                // invalid number
                if (cnt == 0 && abbr[i] == '0')
                    return false;
                cnt = cnt * 10 + abbr[i] - '0';
            } else {
cout << cnt << " ";
cout << word[idx + cnt] << " " << abbr[i] << endl;
                idx += cnt;
                cnt = 0;
                if (idx >= (int)word.length() || word[idx] != abbr[i]) {
                    return false;
                }
                ++idx;
            }
        }
        return idx + cnt == (int)word.length();
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //cout << sol.validWordAbbreviation("internationalization", "i12iz4n") << endl;
    cout << sol.validWordAbbreviation("a", "01") << endl;

    return 0;
}
