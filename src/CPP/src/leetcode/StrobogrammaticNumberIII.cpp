/*
 * [Source] https://leetcode.com/problems/strobogrammatic-number-iii/
 * [Difficulty]: Hard
 * [Tag]: Math
 * [Tag]: Recursion
 */

#include <iostream>
#include <string>

using namespace std;

// [Solution]: Start from middle, adding number to before and end. So construct number with length between low to high.
// [Corner Case]:
class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int res = 0;
        for (int len = (int)low.size(); len <= (int)high.size(); ++len) {
            res += numMiddle("", len, low, high);
            res += numMiddle("0", len, low, high);
            res += numMiddle("1", len, low, high);
            res += numMiddle("8", len, low, high);
        }
        return res;
    }

    int numMiddle(string middle, int len, string &low, string &high) {
        int curLen = middle.length();
        if (curLen > len)
            return 0;
        if (curLen == len) {
            if (middle[0] == '0' && len > 1)
                return 0;
            if (len == (int)low.length() && middle.compare(low) < 0)
                return 0;
            if (len == (int)high.length() && middle.compare(high) > 0)
                return 0;
cout << middle << endl;
            return 1;
        }

        int res = 0;
        res += numMiddle("0" + middle + "0", len, low, high);
        res += numMiddle("1" + middle + "1", len, low, high);
        res += numMiddle("6" + middle + "9", len, low, high);
        res += numMiddle("8" + middle + "8", len, low, high);
        res += numMiddle("9" + middle + "6", len, low, high);
        return res;
    }
};


int main() {
    Solution sol;

    cout << sol.strobogrammaticInRange("50", "100") << endl;

    return 0;
}
