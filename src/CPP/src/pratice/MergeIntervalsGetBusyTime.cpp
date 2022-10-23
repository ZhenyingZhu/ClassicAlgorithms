#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-218632-1-1.html

struct Interval {
    int start, end;
    Interval(int s, int e): start(s), end(e) { }
};

class MergedIntervalsLinkedList {
public:
    MergedIntervalsLinkedList(): totalTime(0) {
    }

    void addInterval(Interval interval) {
        auto it = intervalList.begin();
        while (it != intervalList.end() && it->end < interval.start)
            ++it;

        if (it == intervalList.end()) {
            intervalList.push_back(interval);
            totalTime += interval.end - interval.start;
            return;
        }

        if (it->start > interval.end) {
            intervalList.insert(it, interval);
            totalTime += interval.end - interval.start;
            return;
        }

        int st = min(interval.start, it->start);
        int ed = max(interval.end, it->end);
        while (it != intervalList.end() && it->start <= interval.end) {
            totalTime -= it->end - it->start;
            ed = max(ed, it->end);
            auto deleteIt = it;
            ++it;
            intervalList.erase(deleteIt);
        }

        totalTime += ed - st;
        intervalList.insert(it, Interval(st, ed));
    }

    int getTotalBusyTime() {
        return totalTime;
    }

    void printIntervals() {
        for (auto it = intervalList.begin(); it != intervalList.end(); ++it) {
            cout << "[" << it->start << "," << it->end << "] ";
        }
        cout << endl;
    }

private:
    list<Interval> intervalList;
    int totalTime;
};

class MergedIntervals {
public:
    void addInterval(Interval interval) {
        int end = interval.end;
        if (stEdMap.count(interval.start)) {
            end = max(stEdMap[interval.start], end);
        }
        stEdMap[interval.start] = end;
    }

    int getTotalBusyTime() {
        if (stEdMap.empty())
            return 0;

        int totalTime = 0;
        int st = stEdMap.begin()->first, ed = stEdMap.begin()->second;
        for (auto it = stEdMap.begin(); it != stEdMap.end(); ++it) {
            if (it->first > ed) {
                totalTime += ed - st;
                st = it->first;
                ed = it->second;
            } else {
                ed = max(ed, it->second);
            }
        }
        totalTime += ed - st;
        return totalTime;
    }

    void printIntervals() {
        for (auto it = stEdMap.begin(); it != stEdMap.end(); ++it) {
            cout << "[" << it->first << "," << it->second << "] " << endl;
        }
    }

private:
    map<int, int> stEdMap;
};

int main() {
    MergedIntervals mi;

    vector<Interval> input = { {1,3}, {4,6}, {2,5}, {4,7} };
    for (Interval &i : input) {
        mi.addInterval(i);
        mi.printIntervals();
        cout << mi.getTotalBusyTime() << endl;
    }

    return 0;
}
