#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-224520-4-1.html

struct Interval {
    int start;
    int end;
};

class Solution {
public:
    vector<int> dotsOnEveryInterval(vector<Interval> &intervals) {
        if (intervals.empty())
            return {};
        int size = intervals.size();

        sort(intervals.begin(), intervals.end(), smaller);
        vector<int> dots;
        int dot = intervals[0].end;
        for (int i = 1; i < size; ++i) {
            if (intervals[i].start <= dot) {
                dot = min(dot, intervals[i].end);
            } else {
                dots.push_back(dot);
                dot = intervals[i].end;
            }
        }
        dots.push_back(dot);

        return dots;
    }

private:
    static bool smaller(const Interval &inter1, const Interval &inter2) {
        return inter1.start < inter2.start;
    }
};

int main() {
    Solution sol;

    //vector<Interval> intervals = { {0,2}, {2,4}, {1,3} }; // 2
    //vector<Interval> intervals = { {0,4}, {0,3}, {0,2} }; // 2
    //vector<Interval> intervals = { {0,4}, {0,3}, {4,5} }; // 3,5
    //vector<Interval> intervals = { {0,1}, {1,2}, {2,3} }; // 1,3
    vector<Interval> intervals = { {0,4}, {1,3}, {2,3} }; // 3

    for (int &dot : sol.dotsOnEveryInterval(intervals))
        cout << dot << ", ";
    cout << endl;

    return 0;
}
