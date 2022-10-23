/*
 * [Source] https://leetcode.com/problems/repeated-substring-pattern/
 * [Difficulty]: Easy
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: Double the string and find the string itself.
// [Corner Case]:
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        string tmp = str + str;
        size_t pos = tmp.find(str, 1);
        return pos < str.length();
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.repeatedSubstringPattern("aba") << endl;

    return 0;
}
