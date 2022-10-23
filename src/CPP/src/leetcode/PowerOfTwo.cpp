/*
 * [Source] https://leetcode.com/problems/power-of-two/
 * [Difficulty]: Easy
 * [Tag]: Math
 * [Tag]: Bit Manipulation
 */

#include <iostream>

using namespace std;

// [Solution]: n and n - 1
// [Corner Case]: 0 and negative numbers are not power of 2.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return (n & (n - 1)) == 0;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    for (int i = 0; i < 9; ++i) {
        cout << i << " " << (sol.isPowerOfTwo(i) ? "True" : "False") << endl;
    }

    return 0;
}
