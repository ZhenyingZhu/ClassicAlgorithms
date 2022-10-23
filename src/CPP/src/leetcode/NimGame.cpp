/*
 * [Source] https://leetcode.com/problems/nim-game/
 * [Difficulty]: Easy
 * [Tag]: Brainteaser
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: DP solution is that when previous 3 stone numbers are all definitely win, then this number definitely lose. Then it is the multiple of 4.
// [Corner Case]:
class Solution {
public:
    bool canWinNim(int n) {
        if (n <= 3)
            return true;

        return !(n % 4 == 0);
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
