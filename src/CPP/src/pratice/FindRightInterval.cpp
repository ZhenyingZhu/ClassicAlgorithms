#include <iostream>
#include <vector>
#include <map>

using namespace std;

// [Source]: https://leetcode.com/problems/find-right-interval/
// http://www.1point3acres.com/bbs/thread-218632-1-1.html

struct Interval {
    Interval(int s, int e): start(s), end(e) { }
    int start, end;
};

class Solution {
public:
    vector<int> findRightInterval(vector<Interval> &intervals) {
        map<int, int> stIdxMap;
        for (int i = 0; i < (int)intervals.size(); ++i) {
            stIdxMap[intervals[i].start] = i;
        }

        vector<int> res;
        for (int i = 0; i < (int)intervals.size(); ++i) {
            auto it = stIdxMap.lower_bound(intervals[i].end);
            if (it == stIdxMap.end()) {
                res.push_back(-1);
            } else {
                res.push_back(it->second);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<Interval> intervals = {
        {1,3}, {2,4}, {5,6}
    };
    for (int idx : sol.findRightInterval(intervals))
        cout << idx << ",";
    cout << endl;

    return 0;
}
