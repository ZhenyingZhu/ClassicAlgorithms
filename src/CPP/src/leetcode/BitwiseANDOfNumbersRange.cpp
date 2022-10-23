/*
 * [Source] https://leetcode.com/problems/bitwise-and-of-numbers-range/
 * [Difficulty]: Medium
 * [Tag]: Bit Manipulation
 */

#include <iostream>
#include <climits>

using namespace std;

// [Solution]: If the higher bits of two numbers are same, those bits are leave in the result. Bits after first different bits are all cleared.
// [Corner Case]:
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int mask = INT_MAX; // make last several bits become 0, see how many 0 needed to make m == n
        while ( (m & mask) != (n & mask) ) {
            mask = mask << 1;
        }
        return m & mask;
    }

    int rangeBitwiseAndMySol(int m, int n) {
        int bit = 1;
        int t = n;
        while (t >> 1 != 0) { // find highest bit 1
            bit = bit << 1;
            t = t >> 1;
        }

        int res = 0;
        while (bit > 0) {
            if (((m & bit) ^ (n & bit)) == 0) { // if they are same, set it in the result
                res |= m & bit;
                bit = bit >> 1;
            } else {
                break;
            }
        }

        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.rangeBitwiseAnd(5, 7) << endl;
    cout << sol.rangeBitwiseAnd(5, 8) << endl;

    return 0;
}
