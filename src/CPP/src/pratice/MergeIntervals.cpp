#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    Interval(): start(0), end(0) { }
    Interval(int s, int e): start(s), end(e) { }
    int start, end;
};

// [Source]: https://leetcode.com/problems/merge-intervals
// http://www.1point3acres.com/bbs/thread-218632-1-1.html

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty())
            return { };

        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), smaller);

        int st = intervals[0].start, ed = intervals[0].end;
        for (int i = 1; i < (int)intervals.size(); ++i) {
            Interval &cur = intervals[i];
            if (cur.start > ed) {
                res.push_back(Interval(st, ed));
                st = cur.start;
                ed = cur.end;
            } else {
                ed = max(ed, cur.end);
            }
        }
        res.push_back(Interval(st, ed));
        return res;
    }

private:
    static bool smaller(const Interval &i1, const Interval &i2) {
        return i1.start < i2.start;
    }
};

int main() {
    Solution sol;

    vector<Interval> intervals = {{1,3},{2,6},{8,10},{15,18}};
    for (Interval &inter : sol.merge(intervals))
        cout << "<" << inter.start << "," << inter.end << "> ";
    cout << endl;

    return 0;
}
