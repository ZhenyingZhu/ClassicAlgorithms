/*
 * [Source] https://leetcode.com/problems/sum-of-two-integers/
 * [Difficulty]: Easy
 * [Tag]: Bit Manipulation
 */

#include <iostream>
#include <bitset>

using namespace std;

// [Solution]: If consider sign, it is not easy at all. Since c++ has undifined shift operation with signed int.
// [Corner Case]:
class Solution {
public:
    int getSum(int a, int b) {
        // a is the sum of non-carry. b is the carry. When carry is 0, the result is sum
        unsigned int noCarrySum = a;
        unsigned int carry = b;
cout << (int)noCarrySum << " " << (int)carry << endl;

        while (carry != 0) {
            unsigned int tmp = (noCarrySum & carry) << 1;
            noCarrySum = noCarrySum ^ carry;
            carry = tmp;
bitset<32> aa(noCarrySum);  bitset<32> bb(carry);
cout << aa << " " << bb << endl;
        }
        return (int)noCarrySum;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.getSum(7, -5) << endl;

    return 0;
}
