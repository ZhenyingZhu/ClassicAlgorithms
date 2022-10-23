/*
 * [Source] https://leetcode.com/problems/bulb-switcher/
 * [Difficulty]: Medium
 * [Tag]: Math
 * [Tag]: Brainteaser
 */

#include <iostream>

using namespace std;

// [Solution]: equal to x = sqrt(n) because for n from x^2 to (x+1)^2-1, x^2 leaves x bulbs on. Then each x^2+y has even primes, which leaves bulb off. Until (x+1)^2, which has even number of primes and (x+1), makes a bulb on.
// [Corner Case]:
class Solution {
public:
    int bulbSwitch(int n) {
        if (n <= 1)
            return n;

        for (long x = n / 2; x >= 1; --x)
            if (x * x <= (long)n)
                return (int)x;
        return 0;
    }
};

int main() {
    Solution sol;

    cout << sol.bulbSwitch(99999) << endl;

    return 0;
}
