#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    Interval(int s, int e): start(s), end(e) { }
    int start, end;
};

// [Source]: https://leetcode.com/problems/data-stream-as-disjoint-intervals/
// http://www.1point3acres.com/bbs/thread-224520-1-1.html

class SummaryRanges {
public:
    SummaryRanges() {
    }

    void addNum(int val) {
        if (stEdMap.empty()) {
            stEdMap[val] = val;
            return;
        }

        map<int, int>::iterator next = stEdMap.upper_bound(val);
        if (next == stEdMap.begin()) {
            // next could not be end because already check map is not empty
            if (next->first == val + 1) {
                stEdMap[val] = next->second;
                stEdMap.erase(next);
            } else {
                stEdMap[val] = val;
            }
            return;
        }

        // next step could remove next, so set prev here
        map<int, int>::iterator prev = next;
        --prev;

        // not insert yet
        int end = val;
        if (next != stEdMap.end() && next->first == val + 1) {
            end = next->second;
            stEdMap.erase(next);
        }

        if (prev->second >= val) {
cout << prev->first << ", " << prev->second << endl;
            return;
        } else if (prev->second == val - 1) {
            stEdMap[prev->first] = end;
        } else {
            stEdMap[val] = end;
        }
    }

    vector<Interval> getIntervals() {
        vector<Interval> res;
        for (auto it = stEdMap.begin(); it != stEdMap.end(); ++it) {
            res.push_back( Interval(it->first, it->second) );
        }
        return res;
    }

private:
    map<int, int> stEdMap;
};

int main() {
    SummaryRanges sr;

    //vector<int> nums = {1, 3, 7, 2, 6};
    vector<int> nums = {
49,97,53,5,33,65,62,51,100,38,61,45,74,27,64,17,36,17,96,12,79,32,68,90,77,18,39,12,93,9,87,42,60,71,12,45,55,40,78,81,26,70,61,56,66,33,7,70,1,11,92,51,90,100,85,80,0,78,63,42,31,93,41,90,8,24,72,28,30,18,69,57,11,10,40,65,62,13,38,70,37,90,15,70,42,69,26,77,70,75,36,56,11,76,49,40,73,30,37,23
    };
    for (int &num : nums) {
        sr.addNum(num);
        for (Interval &inter : sr.getIntervals()) {
            cout << "[" << inter.start << "," << inter.end << "] ";
        }
        cout << endl;
    }

    sort(nums.begin(), nums.end());
    for (int &num : nums)
        cout << num << ",";
    cout << endl;

    return 0;
}
