/*
 * [Source] https://leetcode.com/problems/number-of-1-bits/
 * [Difficulty]: Easy
 * [Tag]: Bit Manipulation
 */

#include <iostream>

using namespace std;

// [Solution]: Use n & (n - 1) to remove the last 1
// [Corner Case]: uint is fine. If it is int, then need deal with negative number like INT_MIN
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0) {
            n &= (n - 1);
            ++res;
        }
        return res;
    }
};

// [Solution]: shift and count
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.hammingWeight(11) << endl;

    return 0;
}
