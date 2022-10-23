/*
 * [Source] https://leetcode.com/problems/hamming-distance/
 * [Difficulty]: Easy
 * [Tag]: Bit Manipulation
 */

#include <iostream>

using namespace std;

// [Solution]: Be careful about -1
// [Corner Case]:
class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y;

        // if tmp < 0, there are a lot 1
        int cnt = 0;
        while (tmp != 0) {
            ++cnt;
            tmp &= tmp - 1;
        }
        return cnt;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    cout << sol.hammingDistance(1, -1) << endl;

    return 0;
}
