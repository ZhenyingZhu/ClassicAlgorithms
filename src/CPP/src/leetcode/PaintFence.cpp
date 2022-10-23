/*
 * [Source] https://leetcode.com/problems/paint-fence/
 * [Difficulty]: Easy
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Use two DP vecs to indicate when the last two cells are same or different.
// [Corner Case]:
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0)
            return 0;
        vector<int> same(n, 0), diff(n, 0);
        diff[0] = k;
        for (int i = 1; i < n; ++i) {
            // current fence and previous fence paint differently
            diff[i] = diff[i - 1] * (k - 1) + same[i - 1] * (k - 1);
            // current fence and previous fence paint same
            same[i] = diff[i - 1];
        }
        return diff.back() + same.back();
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    for (int i = 1; i <= 4; ++i) {
        cout << sol.numWays(i, 3) << endl;
    }

    return 0;
}
