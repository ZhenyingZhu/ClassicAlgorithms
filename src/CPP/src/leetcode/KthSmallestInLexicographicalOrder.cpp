/*
 * [Source] https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/
 * [Difficulty]: Hard
 * [Tag]: 
 */

#include <iostream>

using namespace std;

// [Solution]: Backtracking TLE
// [Corner Case]:
class SolutionTLE {
public:
    int findKthNumber(int n, int k) {
        long ed = n;
        long res = 0;
        for (long i = 1; i <= 9; ++i) {
            if (helper(i, ed, res, k))
                return (int)res;
        }
        return -1;
    }

    bool helper(long num, long ed, long &res, int &k) {
        if (num > ed)
            return false;
cout << num << endl;
        --k;
        if (k == 0) {
            res = num;
            return true;
        }

        for (long i = 0; i <= 9; ++i) {
            if (helper(num * 10 + i, ed, res, k))
                return true;
        }
        return false;
    }
};

// [Solution]: Compute the numbers between two success number by multiple them by 10 and minus
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        --k; // the 1st number is 1
        while (k > 0) {
            int steps = calSteps(cur, cur + 1, n);
            if (steps <= k) {
                k -= steps;
                ++cur;
            } else {
                --k; // number cur
                cur *= 10;
            }
        }
        return cur;
    }

    int calSteps(long cur, long nxt, long max) {
        // compute how many numbers between cur and nxt, not include nxt
        int steps = 0;
        while (cur <= max) {
            steps += min(max + 1, nxt) - cur; // cur is 1, max is 1, then steps is 1
            cur *= 10;
            nxt *= 10;
        }
        return steps;
    }
};

int main() {
    Solution sol;

    cout << endl << sol.findKthNumber(103, 13) << endl;

    return 0;
}
