/*
 * [Source] https://leetcode.com/problems/ugly-number-ii/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 * [Tag]: Heap
 * [Tag]: Math
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// [Solution]: Use three queues to record multiples of only 2s, multiples of 2 and 3s and multiples of 2 and 3 and 5s.
// [Corner Case]:
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;

        vector<long> factors = {2, 3, 5};
        vector<queue<long>> candidates(3);

        long res = 1;
        int idx = 0;
        for (int i = 1; i < n; ++i) {
cout << "mul ";
            for (int j = idx; j < 3; ++j) {
cout << res * factors[j] << " ";
                candidates[j].push(res * factors[j]);
            }
cout << endl;
            res = getFirst(candidates, idx);
cout << res << endl;
        }
        return (int)res;
    }

    long getFirst(vector<queue<long>>& candidates, int& idx) {
        long a = candidates[0].front(), b = candidates[1].front(), c = candidates[2].front();
        long m;
        if (a < b) {
            if (a < c) {
                idx = 0;
                m = a;
            } else {
                idx = 2;
                m = c;
            }
        } else {
            if (b < c) {
                idx = 1;
                m = b;
            } else {
                idx = 2;
                m = c;
            }
        }
cout << a << " " << b << " " << c << endl;
        candidates[idx].pop();
        return m;
    }
};

// [Solution]: Use heap instead of three queues. Notice don't insert duplicate values by mod current val with 5, 3, 2.

int main() {
    Solution sol;

    cout << sol.nthUglyNumber(1600) << endl;

    return 0;
}
