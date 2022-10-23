#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/find-the-celebrity/
// http://www.1point3acres.com/bbs/thread-227305-1-1.html

class Solution {
public:
    int findCelebrity(int n) {
        int left = 0, right = n - 1;
        while (left < right) {
            if (knows(left, right)) {
                ++left;
            } else {
                --right;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i == left)
                continue;
            if (knows(left, i) || !knows(i, left))
                return -1;
        }
        return left;
    }
};

int main() {
    Solution sol;

    return 0;
}
