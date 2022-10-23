#include <iostream>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-225639-1-1.html

class Solution {
public:
    int minimumLength(string regex) {
        return helper(regex, 0, regex.length() - 1);
    }

    int helper(string &regex, int st, int ed) {
        if (st > ed)
            return 0;

        int i = st;
        int cnt = 0;
        while (i <= ed) {
            if (regex[i] == '(') {
                int braceEd = i + 1;
                while (braceEd <= ed && regex[braceEd] != ')') {
                    ++braceEd;
                }
                if (braceEd > ed) {
                    cout << "Invalid input" << endl;
                    return 0;
                }
                cnt += helper(regex, i + 1, braceEd - 1);
                i = braceEd;
            } else if (regex[i] == '|') {
                cnt = min(cnt, helper(regex, i + 1, ed));
                return cnt;
            } else if (regex[i] == 'x') {
                ++cnt;
            } else {
                cout << "Unrecognize char" << endl;
                return 0;
            }
            ++i;
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    cout << sol.minimumLength("x(xxx|x|xx)xx|x") << endl;

    return 0;
}
