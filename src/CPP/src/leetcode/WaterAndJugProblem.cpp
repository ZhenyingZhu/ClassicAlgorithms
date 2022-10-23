/*
 * [Source] https://leetcode.com/problems/water-and-jug-problem/
 * [Difficulty]: Medium
 * [Tag]: Math
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: 1. if a * x + b * y = z, return true. 2. when z is multiple of great common divior, it has solution
// [Corner Case]:
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0)
            return true;

        if (z < 0 || z > x + y)
            return false;

        int g = gcd(x, y);
        if (g == 0)
            return false;
        return z % g == 0;
    }

    int gcd(int x, int y) {
        if (y == 0)
            return x;
        if (x == 0)
            return y;
        return gcd(y, x % y);
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    //cout << sol.canMeasureWater(3, 5, 4) << endl;
    //cout << sol.canMeasureWater(2, 6, 5) << endl;
    cout << sol.canMeasureWater(0, 0, 0) << endl;

    return 0;
}
