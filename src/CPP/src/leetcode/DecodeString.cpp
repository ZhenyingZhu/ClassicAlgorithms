/*
 * [Source] https://leetcode.com/problems/decode-string/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 * [Tag]: Stack
 */

#include <iostream>
#include <string>

using namespace std;

// [Solution]: Use a reference int to make sure the index is increasing. Function call stack to implement the stack
// [Corner Case]: Note for each string part between [], there can be still some string left after repeat strings
class Solution {
public:
    string decodeString(string s) {
        if (s.length() == 0)
            return "";

        int idx = 0;
        return helper(s, idx);
    }

    string helper(string &s, int &idx) {
        // Each call of this function deal with abc123[efg], and if any string left, call it again
        string res;
        // First not repeat part
        while ( idx < (int)s.length() && s[idx] >= 'a' && s[idx] <= 'z' ) {
            res += s[idx++]; // it will points to a ] from parent call
        }

        // Then repeat part
        int repeat = 0;
        while ( idx < (int)s.length() && s[idx] >= '0' && s[idx] <= '9' ) {
            repeat = repeat * 10 + s[idx++] - '0';
        }

        string repeatPart;
        if ( idx < (int)s.length() && s[idx] == '[' ) {
            repeatPart = helper(s, ++idx);
            ++idx; // the ]
        }

        for (int i = 0; i < repeat; ++i) {
            res += repeatPart;
        }

        // If the string part in [] is not end, call another call
        if (idx < (int)s.length() && s[idx] != ']') {
            res += helper(s, idx);
        }

        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.decodeString("2[abc]3[cd]ef") << endl;

    return 0;
}
