/*
 * [Source] https://leetcode.com/problems/number-of-segments-in-a-string/
 * [Difficulty]: Easy
 * [Tag]: String
 */

#include <iostream>
#include <string>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int countSegments(string s) {
        if (s.length() == 0)
            return 0;
        int segments = 0;
        for (int i = 1; i < (int)s.length(); ++i) {
            if (s[i - 1] != ' ' && s[i] == ' ')
                ++segments;
        }
        return segments + (s.back() == ' ' ? 0 : 1);
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.countSegments("a b") << endl;
    cout << sol.countSegments(" a b") << endl;
    cout << sol.countSegments("aa bb") << endl;
    cout << sol.countSegments("a b ") << endl;

    return 0;
}
