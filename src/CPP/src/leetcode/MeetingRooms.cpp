/*
 * [Source] https://leetcode.com/problems/meeting-rooms/
 * [Difficulty]: Easy
 * [Tag]: Sort
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

// [Solution]: Sort and check if overlap
// [Corner Case]:
class Solution {
public:
    static bool smaller(const Interval &int1, const Interval &int2) {
        return int1.start < int2.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty())
            return true;

        sort(intervals.begin(), intervals.end(), smaller);
        int ed = intervals.front().end;
        for (int i = 1; i < (int)intervals.size(); ++i) {
            Interval &inter = intervals[i];
cout << inter.start << " " << inter.end << endl;
            if (ed > inter.start)
                return false;
            ed = inter.end;
        }
        return true;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<Interval> intervals = {{0, 5},{5, 10},{15, 20}};
    cout << sol.canAttendMeetings(intervals) << endl;

    return 0;
}
