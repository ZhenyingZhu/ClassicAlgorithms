/*
 * [Source] https://leetcode.com/problems/find-right-interval/
 * [Difficulty]: Medium
 * [Tag]: Binary Search
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// [Solution]: Use a map to store start and index mapping. map has a function lower_bound which is binary search.
// [Corner Case]:
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> startIdxMap;
        for (int i = 0; i < (int)intervals.size(); ++i) {
            startIdxMap[ intervals[i].start ] = i;
        }

        vector<int> res;
        for (Interval &interval : intervals) {
            auto it = startIdxMap.lower_bound(interval.end);
            if (it == startIdxMap.end())
                res.push_back(-1);
            else
                res.push_back(it->second);
        }
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<Interval> intervals = {{1,2}};
    //vector<Interval> intervals = {{3,4}, {2,3}, {1,2}};
    vector<Interval> intervals = {{1,4}, {2,3}, {3,4}};
    for (int &idx : sol.findRightInterval(intervals))
        cout << idx << " ";
    cout << endl;

    return 0;
}
