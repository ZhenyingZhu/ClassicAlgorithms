/*
 * [Source] https://leetcode.com/problems/guess-number-higher-or-lower/
 * [Difficulty]: Easy
 * [Tag]: Binary Search
 */

#include <iostream>

using namespace std;

// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int answer = 6;
int guess(int num) {
    if (num < answer)
        return 1;
    if (num > answer)
        return -1;
    return 0;
}

// [Solution]:
// [Corner Case]: Really? feel like leetcode return 1 when lower, and -1 when larger
class Solution {
public:
    int guessNumber(int n) {
        int st = 1, ed = n;
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            int boolean = guess(md);
            if (boolean == 0)
                return md;
            if (boolean == 1)
                st = md;
            else
                ed = md;
        }
        if (guess(st) == 0)
            return st;
        return ed;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    for (int i = 6; i <= 20; ++i) {
        cout << sol.guessNumber(i) << endl;
    }

    return 0;
}
