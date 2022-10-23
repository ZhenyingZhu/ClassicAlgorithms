/*
 * [Source] https://leetcode.com/problems/count-numbers-with-unique-digits/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 * [Tag]: Backtracking
 * [Tag]: Math
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// [Solution]: Combination. To pick k number from 0-9, there are 10*9*8... ways. But notice 0 cannot be the first one, so there are 9*9*8... ways for k length. Then sum length from 1 to k is the result.
// [Corner Case]:
class SolutionDP {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;

        int res = 0;
        for (int i = 1; i <= n; ++i) {
            res += uniqueDigitsForLen(i);
        }
        return res;
    }

    int uniqueDigitsForLen(int len) {
        if (len == 1)
            return 10;

        int num = 9;
        for (int i = 1; i < len; ++i) {
            num *= 10 - i; // if there are 11 digits, there is 0 ways to create an unique number
        }
        return num;
    }
};

// [Solution]: Backtracking
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 1; // 0
        int max = pow(10, n);
        unsigned int used = 0;

        for (int i = 1; i < 10; ++i) { // first digit cannot be 0
            used |= 1 << i; // means i is used
            res += numberCount(i, max, used);
            used &= ~(1 << i);
        }
        return res;
    }

    int numberCount(int pre, int max, unsigned int used) {
        // if I wrote it, I would use a n size vector
        if (pre >= max)
            return 0;

        int res = 1; // pre itself
        for (int i = 0; i < 10; ++i) {
            if ( (used & (1 << i)) > 0 )
                continue;
            used |= 1 << i;
            res += numberCount(pre * 10 + i, max, used);
            used &= ~(1 << i);
        }
        return res;
    }
};

int main() {
    Solution sol;

    for (int i = 0; i <= 3; ++i)
        cout << sol.countNumbersWithUniqueDigits(i) << endl;

    return 0;
}
