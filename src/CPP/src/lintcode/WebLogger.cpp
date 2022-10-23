/*
 * [Source] http://www.lintcode.com/en/problem/web-logger/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <map>

using namespace std;

class WebLogger {
public:
    WebLogger() {
        hits = 0;
    }

    /**
     * @param timestamp an integer
     * @return void
     */
    void hit(int timestamp) {
        hitsAt[timestamp] = ++hits;
    }

    /**
     * @param timestamp an integer
     * @return an integer
     */
    int get_hit_count_in_last_5_minutes(int timestamp) {
        int startTime = timestamp - 300;
        auto it = hitsAt.lower_bound(startTime);
        if (it->first == startTime) { // not need to count hits at startTime
            return hits - it->second;
        } else if (it == hitsAt.begin()) { // it->first > startTime
            return hits;
        } else {
            --it;
            return hits - it->second;
        }
    }

private:
    int hits;
    map<int, int> hitsAt;
};

// [Corner Case]:
// [Solution]:

// [Solution]:

int main() {
    WebLogger wl;
    wl.hit(1);
    wl.hit(2);
    cout << wl.get_hit_count_in_last_5_minutes(3) << endl;
    wl.hit(300);
    cout << wl.get_hit_count_in_last_5_minutes(300) << endl;
    cout << wl.get_hit_count_in_last_5_minutes(301) << endl;

    return 0;
}
