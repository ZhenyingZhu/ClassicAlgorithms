/*
 * [Source] https://leetcode.com/problems/one-edit-distance/
 * [Difficulty]: Medium
 * [Tag]: String
 */

#include <iostream>
#include <cmath>

using namespace std;

// [Solution]: From the common sense, there are two cases. If two strings are same length, need exactly one diff; Otherwise the shorter string needs one less char.
// [Corner Case]: Quite a lot corner cases. Need use several testcases.
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.length(), n = t.length();
        if ( abs(m - n) > 1 ) {
            return false;
        }
        if (m > n)
            swap(s, t);

        if (s.length() == t.length()) {
            bool oneDiffFound = false;
            for (int i = 0; i < (int)s.length(); ++i) {
                if (s[i] != t[i]) {
                    if (oneDiffFound)
                        return false;
                    oneDiffFound = true;
                }
            }
            // must have one diff, otherwise they are same
            if (!oneDiffFound)
                return false;
        } else {
            // s is shorter
            bool oneDiffFound = false; // j is pointer of t
            for (int i = 0; i < (int)s.length(); ++i) {
                if (oneDiffFound) {
                    if (s[i] != t[i + 1])
                        return false;
                } else if (s[i] != t[i]) {
                    oneDiffFound = true;
                    if (s[i] != t[i + 1]) // be careful off-by-one bug here
                        return false;
                }
            }
            // if not find any diff, the last char in t should be removed
        }
        return true;
    }
};

// [Solution]: Use DP to compute edit distance. Then check if it is one
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.isOneEditDistance("aabb", "cabb") << endl;
    cout << sol.isOneEditDistance("aabb", "aaabb") << endl;
    cout << sol.isOneEditDistance("aabb", "aabba") << endl;
    cout << sol.isOneEditDistance("aabb", "aabac") << endl;
    cout << sol.isOneEditDistance("aabac", "aabb") << endl;

    return 0;
}
