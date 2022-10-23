/*
 * [Source] https://leetcode.com/problems/nth-digit/
 * [Difficulty]: Easy
 * [Tag]: Math
 */

#include <iostream>

using namespace std;

// [Solution]: Count the number of each length.
// [Corner Case]:
class Solution {
public:
    int findNthDigit(int n) {
        if (n <= 9)
            return n;

        long tmp = n;
        long len = 1, numbersOfLen = 9;
        long st = 1;
        while (tmp > len * numbersOfLen) {
            tmp -= len * numbersOfLen;
            st *= 10; // for example 100
            numbersOfLen *= 10; // there are 900 len 3 numbers
            ++len;
        }

        --tmp; // make n 0 base, otherwise digit never goes to 0
        int idx = tmp / len, digit = len - 1 - tmp % len;
        int number = st + idx;
cout << number << endl;
        while (digit > 0) {
            number /= 10;
            --digit;
        }
        return number % 10;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    for (int i = 10; i < 16; ++i)
        cout << sol.findNthDigit(i) << " ";
    cout << endl;
    for (int i = 190; i < 199; ++i)
        cout << sol.findNthDigit(i) << " ";
    cout << endl;
    cout << sol.findNthDigit(1000000000) << endl;

    return 0;
}
