/*
 * [Source] https://leetcode.com/problems/factorial-trailing-zeroes/
 * [Difficulty]: Easy
 * [Tag]: Math
 */

#include <iostream>

using namespace std;

// [Solution]: multiple of 5 provide 1 0, 25 provide another 1 0...
// [Corner Case]:
class Solution {
public:
    int trailingZeros(int n) {
        int zeroProvider = 5;
        int res = 0;
        /* Readable solution but will overflow
        while (n / zeroProvider > 0) {
            res += n / zeroProvider;
            zeroProvider *= 5; 
            cout << zeroProvider << endl;
        }
        */
        while (n > 0) {
            n /= zeroProvider;
            res += n;
        }
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    /*
    cout << sol.trailingZeros(4) << endl;
    cout << sol.trailingZeros(6) << endl;
    cout << sol.trailingZeros(11) << endl;
    cout << sol.trailingZeros(100) << endl;
    */
    cout << sol.trailingZeros(1808548329) << endl;

    return 0;
}
