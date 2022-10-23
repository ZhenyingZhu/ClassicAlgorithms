#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Source]: https://leetcode.com/problems/non-overlapping-intervals/
// http://www.1point3acres.com/bbs/thread-224520-4-1.html

struct Interval {
    int start, end;
    Interval(): start(0), end(0) { }
    Interval(int s, int e): start(s), end(e) { }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval> &intervals) {
        if (intervals.empty())
            return 0;
        int size = intervals.size();

        sort(intervals.begin(), intervals.end(), smaller);
        int cnt = 0;
        int prevEnd = intervals[0].end;
        for (int i = 1; i < size; ++i) {
            if (intervals[i].start >= prevEnd) {
                prevEnd = intervals[i].end;
            } else {
                ++cnt;
                prevEnd = min(intervals[i].end, prevEnd);
            }
        }
        return cnt;
    }

private:
    static bool smaller(const Interval &inter1, const Interval &inter2) {
        if (inter1.start < inter2.start)
            return true;
        else if (inter1.start == inter2.start)
            return inter1.end > inter2.end;
        return false;
    }
};

int main() {
    Solution sol;

    //vector<Interval> intervals = { {0,1},{1,2} }; // 0
    //vector<Interval> intervals = { {0,3},{1,2} }; // 1
    //vector<Interval> intervals = { {0,3},{0,2} }; // 1
    vector<Interval> intervals = { {0,3},{1,5} }; // 1

    cout << sol.eraseOverlapIntervals(intervals) << endl;

    return 0;
}
