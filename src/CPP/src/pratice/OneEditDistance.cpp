#include <iostream>

using namespace std;

// [Source]: https://leetcode.com/problems/one-edit-distance/
// http://www.1point3acres.com/bbs/thread-226078-1-1.html

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.length() + 1 == t.length())
            return checkRemove(s, t);
        else if (s.length() == t.length() + 1)
            return checkRemove(t, s);

        if (s.length() == t.length())
            return checkReplace(s, t);

        return false;
    }

private:
    bool checkRemove(string &shorter, string &longer) {
        int ps = 0, pl = 0;
        bool removed = false;
        while (ps < (int)shorter.length() && pl < (int)longer.length()) {
            if (shorter[ps] == longer[pl]) {
                ++ps;
                ++pl;
            } else if (removed) {
                return false;
            } else {
                ++pl;
                removed = true;
            }
        }

        if (removed)
            return pl == (int)longer.length();
        return pl == (int)longer.length() - 1;
    }

    bool checkReplace(string &s, string &t) {
        bool replaced = false;
        for (int ps = 0, pt = 0; ps < (int)s.length(); ++ps, ++pt) {
            if (s[ps] != t[pt]) {
                if (replaced)
                    return false;
                replaced = true;
            }
        }
        return replaced;
    }
};

int main() {
    Solution sol;

    cout << sol.isOneEditDistance("a", "ab") << endl;
    cout << sol.isOneEditDistance("a", "") << endl;
    cout << sol.isOneEditDistance("a", "b") << endl;
    cout << sol.isOneEditDistance("a", "aab") << endl;
    cout << sol.isOneEditDistance("a", "ca") << endl;
    cout << sol.isOneEditDistance("aa", "bb") << endl;

    return 0;
}
