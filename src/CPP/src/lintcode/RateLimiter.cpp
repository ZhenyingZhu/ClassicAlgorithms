/*
 * [Source] http://www.lintcode.com/en/problem/rate-limiter/
 * [Difficulty]: Hard
 * [Tag]: 
 */

#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

// [Corner Case]:
// [Solution]: Just count all hits on each second. Should use different counts for different intervals
class RateLimiter {
public:
    /**
     * @param timestamp the current timestamp
     * @param event the string to distinct different event
     * @param rate the format is [integer]/[s/m/h/d]
     * @param increment whether we should increase the counter
     * @return true or false to indicate the event is limited or not
     */
    bool isRatelimited(int timestamp, string event, string rate, bool increment) {
        Rate r = getRate(rate);

        if (eventMap.find(event) == eventMap.end())
            eventMap[event] = TimeHitMap();
        TimeHitMap &timeHitMap = eventMap[event];
        int startTime = timestamp - r.seconds + 1;
        int totalHits = 0;
        for (auto it = timeHitMap.lower_bound(startTime); it != timeHitMap.end(); ++it)
            totalHits += it->second;
        
        if (totalHits >= r.hits)
            return true;

        if (increment)
            ++timeHitMap[timestamp];
        return false;
    }

private:
    struct Rate {
        int seconds;
        int hits;
    };

    typedef map<int, int> TimeHitMap;

    Rate getRate(string &rate) {
        int idx = rate.find("/");
        string type = rate.substr(idx + 1);
        int hits = atoi(rate.substr(0, idx).c_str());

        int seconds = 1;
        switch(type[0]) {
            case 'm': seconds = 60;
                      break;
            case 'h': seconds = 60 * 60;
                      break;
            case 'd': seconds = 24 * 60 * 60;
                      break;
            default : seconds = 1;
                      break;
        }

        return {seconds, hits};
    }

    unordered_map<string, TimeHitMap> eventMap;
};

// [Solution]:

int main() {
    RateLimiter rl;
    cout << rl.isRatelimited(1, "login", "3/m", true) << endl;
    cout << rl.isRatelimited(11, "login", "3/m", true) << endl;
    cout << rl.isRatelimited(21, "login", "3/m", true) << endl;
    cout << rl.isRatelimited(30, "login", "3/m", true) << endl;
    cout << rl.isRatelimited(65, "login", "3/m", true) << endl;
    cout << rl.isRatelimited(300, "login", "3/m", true) << endl; 

    return 0;
}
