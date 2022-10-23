/*
 * [Source] https://leetcode.com/problems/poor-pigs/
 * [Difficulty]: Easy
 * [Tag]: 
 */

#include <iostream>

using namespace std;

// [Solution]: Use multi deminsion to use less pigs. two pigs, each can try 4 times, one for x axis and one for y axis, can cover 5*5 buckets (as if a pig try 4 times and not die, it means the position is in the last row).
// [Corner Case]:
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int temps = minutesToTest / minutesToDie + 1;
        int pigs = 0;
        int tests = 1;
        while (tests < buckets) {
            tests *= temps;
            ++pigs;
        }
        return pigs;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //cout << sol.poorPigs(10, 3, 10) << endl;
    cout << sol.poorPigs(1000, 15, 60) << endl;

    return 0;
}
