/*
 * [Source] https://leetcode.com/problems/integer-break/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 * [Tag]: Math
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: DP.
// [Corner Case]: 2, 3 results are smaller than themselves, but for leading numbers they should be themselves.
class SolutionDP {
public:
    int integerBreak(int n) {
        if (n <= 2)
            return 1;
        if (n == 3)
            return 2;

        vector<int> maxProd(n + 1, 0);
        vector<int> breakNum(n + 1, 0);
        maxProd[1] = 1; breakNum[1] = 1;
        breakNum[2] = 1; maxProd[2] = 2; // should be 1
        breakNum[3] = 1; maxProd[3] = 3; // should be 2
        breakNum[4] = 2; maxProd[4] = 4;
        
        for (int i = 5; i <= n; ++i) {
            maxProd[i] = i;
            int idx1 = 0, idx2 = 0;
            for (int a = 1; a <= i / 2; ++a) {
                int b = i - a;
                if (maxProd[a] * maxProd[b] > maxProd[i]) {
                    maxProd[i] = max(maxProd[i], maxProd[a] * maxProd[b]);
                    idx1 = a, idx2 = b;
                    breakNum[i] = breakNum[a] + breakNum[b];
                }
            }
// cout << i << ": " << idx1 << "+" << idx2 << "=" << maxProd[i] << " in "<< breakNum[i] << endl;
        }

        return maxProd[n];
    }
};

// [Solution]: Multiple as many 3 as possible, then if left 4, multiple 4, otherwise multiple 2.
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) // special case
            return n - 1;

        int prod = 1;
        while (n > 4) {
            prod *= 3;
            n -= 3;
        }

        if (n == 3)
            return prod * 3;
        if (n == 4)
            return prod * 4;
        return prod * 2;
    }
};

int main() {
    SolutionDP soldp;
    Solution sol;

    cout << sol.integerBreak(58) << " " << soldp.integerBreak(58) << endl;

    return 0;
}
