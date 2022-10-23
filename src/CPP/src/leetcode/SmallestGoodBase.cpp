/*
 * [Source] https://leetcode.com/problems/smallest-good-base/
 * [Difficulty]: Hard
 * [Tag]: Binary Search
 */

#include <iostream>
#include <cmath>

using namespace std;

// [Solution]: Binary Search
// [Corner Case]: Notice pow(num, 1.0) might not be num
class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long long num = stoll(n);
        // if base is 2, since n is at most 10^18 < (2^4)^18, so there can be at most 62 bits
        for (int digits = 62; digits >= 2; --digits) {
            unsigned long long base = computeBase(num, digits);
            if (base != 0)
                return to_string(base);
        }
        return to_string(num - 1);
    }

    unsigned long long computeBase(unsigned long long num, int digits) {
        unsigned long long left = 2;
        // n = k^(digits - 1) + k^(digits - 2) + ... + k + 1
        // notice digits cannot be 1 here
        // there is some pricise lost here. pow(num, 1) != num
        unsigned long long right = pow((double)num, 1.0/(digits - 1)) + 1;
cout << digits << ": " << left << " " << right << endl;
        while (left <= right) {
            unsigned long long mid = left + (right - left) / 2;

            unsigned long long factor = 1;
            unsigned long long res = 0;
            for (int i = 0; i < digits; ++i) {
                res += factor;
                factor *= mid;
            }

            if (res == num)
                return mid;
            if (res > num)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return 0;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    //cout << sol.smallestGoodBase("2") << endl;
    //cout << sol.smallestGoodBase("1000000000000000000") << endl;
    //cout << sol.smallestGoodBase("4680") << endl;
    cout << sol.smallestGoodBase("727004545306745403") << endl;

    return 0;
}
