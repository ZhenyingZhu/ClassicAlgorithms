/*
 * [Source] https://leetcode.com/problems/excel-sheet-column-number/
 * [Difficulty]: Easy
 * [Tag]: Math
 */

#include <iostream>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (const char& c : s) {
            res = res * 26 + c - 'A' + 1;
        }
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.titleToNumber("Z") << endl;
    cout << sol.titleToNumber("AB") << endl;
    cout << sol.titleToNumber("AAA") << endl;

    return 0;
}
