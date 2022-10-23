/*
 * [Source] https://leetcode.com/problems/count-the-repetitions/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 */

#include <iostream>

using namespace std;

// [Solution]: Use two pointers. One pointer go through s1 n1 times, another one go through s2 if s2[j]==s1[i].
// [Corner Case]:
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (s2.empty())
            return 0;

        if (n1 % n2 == 0) {
            n1 /= n2;
            n2 = 1;
        }

        int len1 = s1.length(), len2 = s2.length();

        int p1 = 0, p2 = 0;
        int cnt = 0;
        while (p1 < len1 * n1) {
            if (s1[p1++ % len1] == s2[p2]) {
                ++p2;
                if (p2 == len2) {
                    ++cnt;
                    p2 = 0;
                }
            }
        }
        return cnt / n2;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //cout << sol.getMaxRepetitions("acb", 4, "ba", 2) << endl;
    cout << sol.getMaxRepetitions("aahumeaylnlfdxfircvscxggbwkfnqduxwfnfozvsrtkjprepggxrpnrvystmwcysyycqpevikeffmznimkkasvwsrenazkycxf", 2, "aac", 2) << endl;

    return 0;
}
