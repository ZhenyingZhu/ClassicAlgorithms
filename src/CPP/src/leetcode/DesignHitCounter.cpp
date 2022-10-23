/*
 * [Source] https://leetcode.com/problems/design-hit-counter/
 * [Difficulty]: Medium
 * [Tag]: Design
 */

#include <iostream>
#include <map>

using namespace std;

// [Solution]:
// [Corner Case]:
class HitCounter {
public:
    HitCounter() {
        timeHits[0] = 0;
        totalHits = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        ++totalHits;
        timeHits[timestamp] = totalHits;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int start = timestamp - 300;
        if (start < 0)
            start = 0;
        map<int, int>::iterator it = timeHits.lower_bound(start);
cout << start << " " << it->first << endl;
        if (it == timeHits.end())
            return 0;
        if (it->first > start)
            --it;
        return totalHits - it->second;
    }

    map<int, int> timeHits;
    int totalHits;
};

class Solution {
public:
    void test() {
        HitCounter hc;
        hc.hit(2);
        hc.hit(3);
        hc.hit(4);
        cout << hc.getHits(300) << endl;
        cout << hc.getHits(301) << endl;
        cout << hc.getHits(302) << endl;
        cout << hc.getHits(303) << endl;
        cout << hc.getHits(304) << endl;
        hc.hit(501);
        cout << hc.getHits(600) << endl;
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
