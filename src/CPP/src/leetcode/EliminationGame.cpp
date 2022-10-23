/*
 * [Source] https://leetcode.com/problems/elimination-game/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class SolutionBF {
public:
    int lastRemaining(int n) {
        if (n == 1)
            return 1;

        vector<int> begin;
        begin.reserve(n / 2);
        for (int i = 2; i <= n; i += 2) {
            begin.push_back(i);
        }

        while (begin.size() > 1) {
            vector<int> remain;
            for (int i = begin.size() - 2; i >= 0; i -= 2) {
                remain.push_back(begin[i]);
            }
            swap(begin, remain);
        }
        return begin[0];
    }
};

// [Solution]: Use recursive call. Notice each time when eliminate half of the array, it equals to half the number multiple two
class Solution {
public:
    int lastRemaining(int n) {
        return helper(n, true);
    }

    int helper(int n, bool left2right) {
        if (n == 1)
            return 1;
        if (left2right) {
            // (1,2,3,4) or (1, 2, 3, 4, 5) cross out from left to right equals to (2*1, 2*2) corss out from right to left
            return 2 * helper(n / 2, false);
        } else {
            // (1, 2, 3, 4, 5, 6) from right to left equals to (2*1-1, 2*2-1, 2*3-1) from left to right
            // (1, 2, 3, 4, 5, 6, 7) from right to left equals to (2*1, 2*2, 2*3) from left to right
            return 2 * helper(n / 2, true) - 1 + n % 2;
        }

    }
};

int main() {
    Solution sol;

    cout << sol.lastRemaining(100000000) << endl;

    return 0;
}
