/*
 * [Source] http://www.lintcode.com/en/problem/heart-beat/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

namespace {
    void printVec(vector<string> vec) {
        cout << "[";
        for (string& str : vec) {
            cout << str << " ";
        }
        cout << "]" << endl;
    }
}

// [Solution]:
class HeartBeat {
public:
    int timeInterval;
    unordered_map<string, int> lastPings;

    HeartBeat() {
    }

    // @param slaves_ip_list a list of slaves'ip addresses
    // @param k an integer
    // @return void
    void initialize(vector<string>& slaves_ip_list, int k) {
        timeInterval = k;
        for (string& slave : slaves_ip_list)
            lastPings[slave] = 0;
    }

    // @param timestamp current timestamp in seconds
    // @param slave_ip the ip address of the slave server
    // @return nothing
    void ping(int timestamp, string slave_ip) {
        if (lastPings.find(slave_ip) == lastPings.end())
            return;
        lastPings[slave_ip] = timestamp;
    }

    // @param timestamp current timestamp in seconds
    // @return a list of slaves'ip addresses that died
    vector<string> getDiedSlaves(int timestamp) {
        vector<string> diedSlaves;
        for (auto it = lastPings.begin(); it != lastPings.end(); ++it) {
            if (timestamp - it->second >= 2 * timeInterval)
                diedSlaves.push_back(it->first);
        }
        return diedSlaves;
    }
};

int main() {
    HeartBeat hb;
    vector<string> slaves = {"10.173.0.2", "10.173.0.3"};
    hb.initialize(slaves, 10);
    hb.ping(1, "10.173.0.2");
    printVec(hb.getDiedSlaves(20));
    printVec(hb.getDiedSlaves(21));
    hb.ping(22, "10.173.0.2");
    hb.ping(23, "10.173.0.3");
    printVec(hb.getDiedSlaves(24));
    printVec(hb.getDiedSlaves(42));

    return 0;
}
