#include <iostream>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-225639-1-1.html

class Solution {
public:
    bool canUniqueDecode(string s) {
        return helper(s, 0);
    }

    bool helper(string &s, int st) {
        if (st == (int)s.length()) {
            return true;
        }

        int decodeWays = 0;
        int num = 0;
        for (int i = st; i < (int)s.length() && isdigit(s[i]); ++i) {
            num = 10 * num + s[i] - '0';
            if (num == 0)
                return false;

            if (helper(s, i + num + 1)) {
                ++decodeWays;
            }
        }

        return decodeWays == 1;
    }
};

int main() {
    Solution sol;

    //cout << sol.canUniqueDecode("2aa3abc") << endl;
    //cout << sol.canUniqueDecode("2aa3ab") << endl;
    //cout << sol.canUniqueDecode("10aaaaaaaaaa") << endl;
    cout << sol.canUniqueDecode("135small6bosses") << endl;

    return 0;
}

