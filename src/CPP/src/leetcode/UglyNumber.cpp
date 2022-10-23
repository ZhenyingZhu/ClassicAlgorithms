/*
 * [Source] https://leetcode.com/problems/ugly-number/
 * [Difficulty]: Easy
 * [Tag]: Math
 */

#include <iostream>

using namespace std;

// [Solution]: Repeatly divide 2, 3, or 5 if they can be round divided by them. Then check if the result is 1.
// [Corner Case]: 0 leads to infinity loop so exclude it first
class Solution {
public:
    bool isUgly(int num) {
        if (num == 0)
            return false;

        while (num % 2 == 0)
            num /= 2;
        while (num % 3 == 0)
            num /= 3;
        while (num % 5 == 0)
            num /= 5;
        return num == 1;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.isUgly(6) << endl;
    cout << sol.isUgly(8) << endl;
    cout << sol.isUgly(14) << endl;

    return 0;
}
