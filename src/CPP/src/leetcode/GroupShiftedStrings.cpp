/*
 * [Source] https://leetcode.com/problems/group-shifted-strings/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 * [Tag]: String
 */

#include <iostream>
#include <functional>
#include <vector>
#include <unordered_map>

using namespace std;

// [Solution]: Use a user defined hash func to map difference to a hash code
// [Corner Case]:
class Solution {
public:
    struct Diff {
        bool operator==(const Diff &others) const {
            return diffs == others.diffs;
        }

        vector<int> diffs;
    };

    struct DiffHash {
        size_t operator()(const Diff &diff) const {
            string hashStr = "";
            for (int num : diff.diffs) {
                hashStr += to_string(num) + ' ';
            }
            return hash<string>()(hashStr);
        }
    };

    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<Diff, vector<string>, DiffHash> map;
        for (string &str : strings) {
            Diff d = computeDiff(str);
            map[d].push_back(str);
        }

        vector<vector<string>> res;
        for (auto it = map.begin(); it != map.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }

    Diff computeDiff(const string &str) {
        Diff d;
        for (int i = 1; i < (int)str.length(); ++i) {
            int distance = str[i] - str[i - 1];
            if (distance < 0)
                distance += 26;
            d.diffs.push_back(distance);
        }
        return d;
    }
};

int main() {
    Solution sol;

    vector<string> strings = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    for (vector<string> &vec : sol.groupStrings(strings)) {
        for (string &str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
