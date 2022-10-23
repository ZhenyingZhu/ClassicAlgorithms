/*
 * [Source] https://leetcode.com/problems/super-pow/
 * [Difficulty]: Medium
 * [Tag]: Math
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: It is divide and conquer. Power of numbers can always use it.
// [Corner Case]:
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (a == 0)
            return 0;
        if (b.empty())
            return a % 1337;

        // a * b % 7 = (a % 7) * (b % 7) % 7
        int res = 1;
        for (int &digit : b) {
            res = myPow(res, 10) * myPow(a, digit) % 1337;
        }
        return res;
    }

    int myPow(int num, int exp) {
        if (exp == 0)
            return 1;
        if (exp == 1)
            return num % 1337;

        int first = myPow(num, exp / 2) % 1337;
        int second = myPow(num, exp - exp / 2) % 1337;
        return first * second % 1337;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> b = {1, 0};
    cout << sol.superPow(2, b) << endl;

    return 0;
}
