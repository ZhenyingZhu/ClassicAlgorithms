#include <iostream>

using namespace std;

// [Source]: https://leetcode.com/problems/reverse-words-in-a-string/
// http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=212481

class Solution {
public:
    void reverseWords(string &s) {
        if (s.empty())
            return;

        removeTrailingSpaces(s);

        int st = 0;
        for (int i = 0; i < (int)s.length(); ++i) {
            if (s[i] == ' ') {
                reverse(s, st, i - 1);
                st = i + 1;
            }
        }
        reverse(s, st, s.length() - 1);

        reverse(s, 0, s.length() - 1);
    }

    void removeTrailingSpaces(string &s) {
        int len = s.length();
        // move pointer to first non space char
        int run = 0;
        while (run < len && s[run] == ' ')
            ++run;

        // copy characters to previous slots
        int cur = 0;
        while (run < len) {
            if (s[run] != ' ')
                s[cur++] = s[run++];
            else if (s[cur - 1] != ' ') // first char must not space
                s[cur++] = s[run++];
            else
                ++run;
        }

        // the last char might be a space
        if (cur > 0 && s[cur - 1] == ' ')
            --cur;
        s.erase(cur);
    }

    void reverse(string &s, int st, int ed) {
        while (st < ed) {
            swap(s[st++], s[ed--]);
        }
    }
};

int main() {
    Solution sol;
    string s = " ";
    sol.reverseWords(s);
    cout << s << "|" << endl;
}
