/*
 * [Source] https://leetcode.com/problems/number-complement/
 * [Difficulty]: Easy
 * [Tag]: Bit Manipulation
 */

#include <iostream>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int findComplement(int num) {
        bool notTrailing = false;
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            if ( ((num >> i) & 1) == 1 ) {
                notTrailing = true;
            } else if (notTrailing) {
                res |= 1 << i;
            }
        }
        return res;
    }
};

// [Solution]: Use a mask that leading 1s and 0s that make num becomes 0. Then and their negative form
/* Java solution

 */

int main() {
    Solution sol;

    //cout << sol.findComplement(5) << endl;
    cout << sol.findComplement(-2) << endl;

    return 0;
}
