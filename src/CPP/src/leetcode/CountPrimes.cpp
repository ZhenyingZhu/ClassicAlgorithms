/*
 * [Source] https://leetcode.com/problems/count-primes/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 * [Tag]: Math
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: The Sieve of Eratosthenes method.
// [Corner Case]: n is not included
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> nums(n, true);
        nums[0] = false;
        nums[1] = false;
        int mul = 2;
        while (mul * mul < n) {
            if (nums[mul]) {
                for (int i = mul * mul; i < n; i += mul)
                    nums[i] = false;
            }
            ++mul;
        }

        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (nums[i]) {
cout << i << " ";
                ++res;
            }
        }
cout << endl;
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.countPrimes(26) << endl;

    return 0;
}
