/*
 * [Source] https://leetcode.com/problems/can-i-win/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <unordered_map>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 1)
            return true;
        int sum = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
        if (desiredTotal > sum)
            return false;

        int used = 0;
        unordered_map<int, bool> canWin;
        return thisTurn(maxChoosableInteger, used, desiredTotal, canWin);
    }

    bool thisTurn(int maxChoosableInteger, int used, int desiredTotal, unordered_map<int, bool> &canWin) {
        if (canWin.count(used))
            return canWin[used];

        for (int i = 1; i <= maxChoosableInteger; ++i) {
            if ( ((used >> i) & 1) == 1)
                continue;

            int tmp = used | (1 << i);
            if (desiredTotal - i <= 0) {
                canWin[used] = true;
                return true;
            }

            if ( !thisTurn(maxChoosableInteger, tmp, desiredTotal - i, canWin) ) {
                canWin[used] = true;
                return true;
            }
        }
        canWin[used] = false;
        return false;
    }
};


int main() {
    Solution sol;

    cout << sol.canIWin(10, 20) << endl;

    return 0;
}
