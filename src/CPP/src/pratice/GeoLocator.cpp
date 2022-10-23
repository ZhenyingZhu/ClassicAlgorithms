#include <iostream>
#include <map>
#include <vector>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-224297-1-1.html

class Solution {
public:
    string whichCity(string ip, vector<vector<string>> &cities) {
        if (cities.empty())
            return "Not found";

        map<int, int> stEdMap;
        map<int, string> stCityMap;
        for (vector<string> &tuple : cities) {
            int st = convertIP(tuple[0]), ed = convertIP(tuple[1]);
            stEdMap[st] = ed;
            stCityMap[st] = tuple[2];
        }

        int checking = convertIP(ip);
        auto it = --stEdMap.upper_bound(checking);

        int intervalSt = it->first;
        if (checking > it->second)
            return "Not found";
        return stCityMap[intervalSt];
    }

private:
    int convertIP(string ip) {
        int num = 0;
        size_t st = 0, ed = ip.find_first_of(".");
        while (ed != string::npos) {
            num = num * 256 + stoi(ip.substr(st, ed - st));
            st = ed + 1;
            ed = ip.find_first_of(".", st);
        }
        num = num * 256 + stoi(ip.substr(st));
        return num;
    }
};

int main() {
    Solution sol;

    vector<vector<string>> cities = {
        {"1.1.1.0", "1.1.1.255", "CityA"},
        {"2.2.2.0", "2.2.2.255", "CityB"}
    };

    cout << sol.whichCity("1.1.1.0", cities) << endl;
    cout << sol.whichCity("1.1.1.5", cities) << endl;
    cout << sol.whichCity("1.2.1.0", cities) << endl;
    cout << sol.whichCity("2.2.2.255", cities) << endl;
    cout << sol.whichCity("3.1.1.0", cities) << endl;

    return 0;
}
