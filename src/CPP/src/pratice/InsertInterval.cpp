#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    Interval(): start(0), end(0) { }
    Interval(int s, int e): start(s), end(e) { }
    int start, end;
};

// [Source]: https://leetcode.com/problems/insert-interval/
// http://www.1point3acres.com/bbs/thread-218632-1-1.html

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty())
            return {newInterval};

        vector<Interval> res;

        int pt = 0;
        while (pt < (int)intervals.size()) {
            if (intervals[pt].end < newInterval.start)
                res.push_back(intervals[pt++]);
            else
                break;
        }

        if (pt == (int)intervals.size()) {
            res.push_back(newInterval);
            return res;
        }

        if (intervals[pt].start > newInterval.end) {
            res.push_back(newInterval);
            res.insert(res.end(), intervals.begin() + pt, intervals.end());
            return res;
        }

        int st = min(intervals[pt].start, newInterval.start), ed = max(intervals[pt].end, newInterval.end);
        ++pt;
        while (pt < (int)intervals.size()) {
            if (intervals[pt].start <= ed)
                ed = max(ed, intervals[pt++].end);
            else
                break;
        }
        res.push_back(Interval(st, ed));

        while (pt < (int)intervals.size())
            res.push_back(intervals[pt++]);

        return res;
    }
};

int main() {
    Solution sol;

    //vector<Interval> intervals = {{1,2},{3,6},{8,10},{15,18}};
    vector<Interval> intervals = {{1,2},{3,6},{8,10},{15,18}};
    for (Interval &inter : sol.insert(intervals, {20, 21}))
        cout << "<" << inter.start << "," << inter.end << "> ";
    cout << endl;

    return 0;
}
