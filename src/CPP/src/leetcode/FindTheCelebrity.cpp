/*
 * [Source] https://leetcode.com/problems/find-the-celebrity/
 * [Difficulty]: Medium
 * [Tag]: Array
 */

#include <iostream>
#include <vector>

using namespace std;

bool knows(int a, int b) {
    if (a == 0 && b == 1)
        return true;
    if (a == 1 && b == 0)
        return true;
    return false;
}

// [Solution]: Brute force. Passed OJ as well.
// [Corner Case]:
class SolutionBF {
public:
    int findCelebrity(int n) {
        vector<bool> possible(n, true);
        for (int asker = 0; asker < n; ++asker) {
            for (int target = 0; target < n; ++target) {
                if (target == asker)
                    continue;
                // If asker know any one, he must not be celebrity
                if (knows(asker, target)) {
                    possible[asker] = false;
                    break;
                }
            }
        }

        for (int target = 0; target < n; ++target) {
            if (!possible[target])
                continue;

            bool isCelebrity = true;
            for (int asker = 0; asker < n; ++asker) {
                if (asker == target)
                    continue;
                if (!knows(asker, target)) {
                    isCelebrity = false;
                    break;
                }
            }
            if (isCelebrity)
                return target;
        }
        return -1;
    }
};

// [Solution]: See comments in line. Notice when check candidate, needs do from both side.
class Solution {
public:
    int findCelebrity(int n) {
        int left = 0, right = n - 1;
        while (left < right) {
            if (knows(left, right))
                // left must not be celebrity
                ++left;
            else
                // right must not be celebrity
                --right;
            // If there is a celebrity, left cannot pass over it
            // Since there is only one celebrity, celebrity must between left and right
        }

        for (int i = 0; i < n; ++i) {
            if (i == left)
                continue;
            // Need two check. First check is that a personal can be known by others but he also know one before him.
            if (!knows(i, left) || knows(left, i))
                return -1;
        }
        return left;
    }
};

int main() {
    Solution sol;

    cout << sol.findCelebrity(2) << endl;

    return 0;
}
