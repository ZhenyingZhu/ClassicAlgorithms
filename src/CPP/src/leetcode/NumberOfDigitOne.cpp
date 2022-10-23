/*
 * [Source] https://leetcode.com/problems/number-of-digit-one/
 * [Difficulty]: Hard
 * [Tag]: Math
 */

#include <iostream>

using namespace std;

// [Solution]: Count on each digits, how many 1s there. Notice when this digit is 0, 1, larger than 1, the numbers are different.
// [Corner Case]:
class Solution {
public:
    int countDigitOne(int n) {
        long total = 0;
        long mask = 1;
        long tmp = n;
        while (tmp / mask > 0) {
            long currentDigitOnes = tmp / 10 / mask;
            int currentDigit = tmp / mask % 10;
            if (currentDigit > 1) {
                total += (currentDigitOnes + 1) * mask;
            } else if (currentDigit == 1) {
                total += currentDigitOnes * mask + n % mask + 1;
            } else {
                total += currentDigitOnes * mask;
            }
            mask *= 10;
        }
        return (int)total;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.countDigitOne(1) << endl;
    cout << sol.countDigitOne(11) << endl;
    cout << sol.countDigitOne(111) << endl;
    cout << sol.countDigitOne(1410065408) << endl;

    return 0;
}
