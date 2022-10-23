/*
 * [Source] https://leetcode.com/problems/non-overlapping-intervals/
 * [Difficulty]: Medium
 * [Tag]: Greedy
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// [Solution]: When two intervals overlapped, always need to delete one. Then if the left one overlap with next one, need delete one again. So make the left one has the smaller end makes deletion less
// [Corner Case]:
class Solution {
public:
    static bool smaller(const Interval &int1, const Interval &int2) {
        return int1.start < int2.start;
    }

    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), smaller);
        int deleteCnt = 0;
        int prevInterIdx = 0;
        for (int i = 1; i < (int)intervals.size(); ++i) {
            // overlapping, need delete one
            if (intervals[i].start < intervals[prevInterIdx].end) {
                ++deleteCnt;

                // leave the one with smaller end
                if (intervals[i].end < intervals[prevInterIdx].end) {
                    prevInterIdx = i;
                }
            } else {
                prevInterIdx = i;
            }
        }
        return deleteCnt;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<Interval> intervals = {
        {1, 3}, {2, 4}, {3, 6}, {3, 5}, {5, 7}
    };
    cout << sol.eraseOverlapIntervals(intervals) << endl;

    return 0;
}
