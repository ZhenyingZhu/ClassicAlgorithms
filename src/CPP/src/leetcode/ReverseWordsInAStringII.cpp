/*
 * [Source] https://leetcode.com/problems/reverse-words-in-a-string-ii/
 * [Difficulty]: Medium
 * [Tag]: String
 */

#include <iostream>

using namespace std;

// [Solution]: Reverse each part, then reverse the whole string to do it inplace.
// [Corner Case]:
class Solution {
public:
    void reverseWords(string &s) {
        if (s.length() <= 1)
            return;

        int st = 0;
        for (int ed = 1; ed < (int)s.length(); ++ed) {
            if (s[ed] == ' ') {
                reverse(s, st, ed - 1);
                st = ed + 1;
            }
        }
        reverse(s, st, s.length() - 1);
        reverse(s, 0, s.length() - 1);
    }

    void reverse(string &s, int st, int ed) {
        while (st < ed)
            swap(s[st++], s[ed--]);
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    string s = "the sky is blue";
    sol.reverseWords(s);
    cout << s << endl;

    return 0;
}
