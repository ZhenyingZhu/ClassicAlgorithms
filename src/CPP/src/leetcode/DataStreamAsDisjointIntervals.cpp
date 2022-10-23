/*
 * [Source] https://leetcode.com/problems/data-stream-as-disjoint-intervals/
 * [Difficulty]: Hard
 * [Tag]: Binary Search Tree
 */

#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <ostream>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

ostream& operator<<(ostream &stream, Interval &inter) {
    stream << "[" << inter.start << "," << inter.end << "]";
    return stream;
}

// [Solution]: Use a set to store starts of intervals in order, so that find intervals are quick. Use two maps to store start/end map to interval
// [Corner Case]: When insert a number that is already in the intervals, use the set to find the interval before the one that has start just larger than the number.
class SummaryRanges {
public:
    unordered_map<int, Interval*> stIntMap;
    unordered_map<int, Interval*> edIntMap;
    set<int> starts;

    SummaryRanges() {
    }

    void addNum(int val) {
        // first check if the val is already in intervals
        auto interStIt = starts.upper_bound(val);
        if (interStIt != starts.begin()) {
            Interval *maybe = stIntMap[*(--interStIt)];
            if (maybe->start <= val && maybe->end >= val)
                return;
        }

        int st = val, ed = val;

        auto prevIt = edIntMap.find(val - 1);
        if (prevIt != edIntMap.end()) {
            Interval *prev = prevIt->second;
            st = prev->start;

            starts.erase(prev->start);
            delete prev;
            edIntMap.erase(prevIt);
        }

        auto nextIt = stIntMap.find(val + 1);
        if (nextIt != stIntMap.end()) {
            Interval *next = nextIt->second;
            ed = next->end;

            starts.erase(next->start);
            delete next;
            stIntMap.erase(nextIt);
        }

        Interval *newInt = new Interval(st, ed);
        stIntMap[st] = newInt;
        edIntMap[ed] = newInt;
        starts.insert(st);
    }

    vector<Interval> getIntervals() {
        vector<Interval> res;
        for (auto it = starts.begin(); it != starts.end(); ++it) {
            res.push_back( *(stIntMap[*it]) );
        }
        return res;
    }
};

class Solution {
public:
    void test() {
        SummaryRanges obj;
        //vector<int> input = {1, 3, 7, 2, 6};
        vector<int> input = {6, 6, 0, 4, 8, 7, 6, 4, 7, 5};
        for (int &val : input) {
            obj.addNum(val);
            for (Interval &inter : obj.getIntervals())
                cout << inter << " ";
            cout << endl;
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    sol.test();

    return 0;
}
