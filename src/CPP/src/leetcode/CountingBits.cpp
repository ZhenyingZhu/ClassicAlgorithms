/*
 * [Source] https://leetcode.com/problems/counting-bits/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 * [Tag]: Bit Manipulation
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        res[0] = 0;
        for (int i = 1; i <= num; ++i) {
            res[i] = res[i & (i - 1)] + 1; // like 110 has 2 bits which is res[100] + 1 bit.
        }
        return res;
    }
};

// [Solution]: Each number after a 2^n is 1 + num - 2^n.
// [Corner Case]:
class SolutionSelf {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        if (num == 0)
            return res;
        res[1] = 1;

        int prePt = 0, curPt = 2;
        int exp = 2;
        while (curPt <= num) {
            if (prePt == exp) {
                prePt = 0;
                exp += exp;
            } else {
                res[curPt++] = 1 + res[prePt++];
            }
        }
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    for (int &i : sol.countBits(5))
        cout << i << " ";
    cout << endl;

    return 0;
}
