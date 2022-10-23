/*
 * [Source] https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
 * [Difficulty]: Medium
 * [Tag]: Greedy
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

// [Solution]: Sort by start. When end is smaller, replace the end with this smaller. When an interval is in wrap the end, skip
// [Corner Case]:
class Solution {
public:
    static bool smaller(const pair<int, int> &p1, const pair<int, int> &p2) {
        if (p1.first < p2.first)
            return true;
        if (p1.first == p2.first && p1.second > p2.second)
            return true;
        return false;
    }

    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end(), smaller);

        int num = 0;
        long prevEnd = (long)INT_MIN - 1;
        for (pair<int, int> &point : points) {
            long st = point.first, ed = point.second;
            if (st <= prevEnd && ed >= prevEnd)
                continue; // when shoot at prevEnd, this ballon also burst

            if (ed <= prevEnd) {
                prevEnd = ed; // when shoot at ed, the previous ballons also burst
            } else {
                ++num; // shoot at prevEnd
                prevEnd = ed;
            }
        }
        return num;
    }
};

// [Solution]: Sort the end in increasing order.
/* Java solution

 */

int main() {
    Solution sol;

    //vector<pair<int, int>> points = {{10,16}, {2,8}, {1,6}, {7,12}};
    //vector<pair<int, int>> points = {{1,10}, {2,6}, {4,6}, {6,7}};
    vector<pair<int, int>> points = {{INT_MIN, INT_MAX}};
    cout << sol.findMinArrowShots(points) << endl;

    return 0;
}
