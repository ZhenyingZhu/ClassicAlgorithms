/*
 * [Source] https://leetcode.com/problems/first-bad-version/
 * [Difficulty]: Easy
 * [Tag]: Binary Search
 */

#include <iostream>

using namespace std;

bool isBadVersion(int version) {
    return version >= 3;
}

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int firstBadVersion(int n) {
        if (n <= 0)
            return 0;

        int st = 1, ed = n;
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            if (isBadVersion(md))
                ed = md;
            else
                st = md;
        }

        if (isBadVersion(st))
            return st;
        return ed;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.firstBadVersion(5) << endl;
    cout << sol.firstBadVersion(4) << endl;
    cout << sol.firstBadVersion(3) << endl;
    cout << sol.firstBadVersion(2) << endl;

    return 0;
}
