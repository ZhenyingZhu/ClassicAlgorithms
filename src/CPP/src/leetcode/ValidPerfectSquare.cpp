/*
 * [Source] https://leetcode.com/problems/valid-perfect-square/
 * [Difficulty]: Medium
 * [Tag]: Binary
 * [Tag]: Math
 */

#include <iostream>

using namespace std;

// [Solution]: Binary Search
// [Corner Case]:
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0)
            return false;
        if (num <= 1)
            return true;

        long st = 2, ed = num / 2;
        while (st + 1 < ed) {
            long md = st + (ed - st) / 2;
            long square = md * md;
            if (square == num)
                return true;
            if (square < num)
                st = md;
            else
                ed = md;
        }

        if (st * st == num)
            return true;
        if (ed * ed == num)
            return true;
        return false;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    for (int i = 1; i <= 100; ++i) {
        cout << i << " " << sol.isPerfectSquare(i) << endl;
    }

    return 0;
}
