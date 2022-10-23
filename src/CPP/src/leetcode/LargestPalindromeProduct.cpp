/*
 * [Source] https://leetcode.com/problems/largest-palindrome-product/
 * [Difficulty]: Easy
 * [Tag]: 
 */

#include <iostream>
#include <cmath>

using namespace std;

// [Solution]: Brute force generate production and try devide it with a number and see if the other number is same digits.
// [Corner Case]:
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1)
            return 9;

        long maxNum = pow(10, n) - 1, minNum = pow(10, n - 1);
        long maxProd = maxNum * maxNum;
        long prodFirstHalf = maxProd / pow(10, n);

        // if n=3, check prod from 100001 to 998899. though prod can be 5 digits as well, it cannot be the max one
        while (prodFirstHalf >= minNum) {
            long prod = computeProd(prodFirstHalf);
            --prodFirstHalf;

            for (long num = maxNum; num >= minNum; --num) {
                // if num too small, then it is previously checked already
                // if num is too large, the other number is smaller than minNum
                if (num * num < prod || num * minNum > prod)
                    break;

                if (prod % num == 0) {
cout << num << " * " << prod / num << " = " << prod << endl;
                    return prod % 1337;
                }
            }
        }

        long x = pow(10, n - 1) + 1;
        long y = 0;
        for (int i = 0; i < n; ++i)
            y = y * 10 + 4;
        return (x * y) % 1337;
    }

    long computeProd(long firstHalf) {
        long res =firstHalf;
        while (firstHalf > 0) {
            res = res * 10 + firstHalf % 10;
            firstHalf /= 10;
        }
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    for (int i = 1; i <= 8; ++i)
        cout << sol.largestPalindrome(i) << endl;

    return 0;
}
