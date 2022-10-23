/*
 * [Source] https://leetcode.com/problems/detect-capital
 * [Difficulty]: Easy
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.length() == 1)
            return true;

        bool firstCap = isCap(word[0]);
        bool secondCap = isCap(word[1]);
        if (!firstCap && secondCap)
            return false;

        for (int i = 2; i < (int)word.length(); ++i) {
            if (secondCap ^ isCap(word[i]))
                return false;
        }
        return true;
    }

    bool isCap(char &c) {
        return (c >= 'A' && c <= 'Z');
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.detectCapitalUse("USA") << endl;
    cout << sol.detectCapitalUse("leetcode") << endl;
    cout << sol.detectCapitalUse("FlaG") << endl;

    return 0;
}
