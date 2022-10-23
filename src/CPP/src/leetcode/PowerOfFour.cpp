/*
 * [Source] https://leetcode.com/problems/power-of-four/
 * [Difficulty]: Easy
 * [Tag]: Bit Manipulation
 */

#include <iostream>
#include <cmath>

using namespace std;

// [Solution]: log2(num) is even integer. 
// [Corner Case]:
class SolutionLog {
public:
    bool isPowerOfFour(int num) {
        cout << num << ":" << log2(num) << endl;
        return log2(num) - (int)log2(num) == 0.0 && (int)log2(num) % 2 == 0;
    }
};

// [Solution]: Since the only 1 bit is already on even place, create 1010 to see if power of 2 number has the right bit.
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0)
            return false;

        if ((num & (num - 1)) != 0)
            return false;

        return (num & 0x55555555) != 0;
    }
};

// [Solution]: num is power of 2 and minus 1 can be divided by 3.
/* Java solution

 */

int main() {
    Solution sol;

    for (int i = 1; i <= 100; i *= 4) {
        cout << sol.isPowerOfFour(i) << endl;
    }

    return 0;
}
