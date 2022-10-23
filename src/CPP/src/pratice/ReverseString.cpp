#include <iostream>

using namespace std;

// [Source]: https://leetcode.com/problems/reverse-string/
// http://www.1point3acres.com/bbs/thread-227554-1-1.html

class Solution {
public:
    string reverseString(string s) {
        int st = 0, ed = s.length() - 1;
        while (st < ed) {
            swap(s[st++], s[ed--]);
        }
        return s;
    }
};

int main() {
    Solution sol;

    cout << sol.reverseString("hello") << endl;
    cout << sol.reverseString("") << endl;

    return 0;
}
