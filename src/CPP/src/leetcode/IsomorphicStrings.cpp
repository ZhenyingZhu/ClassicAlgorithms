/*
 * [Source] https://leetcode.com/problems/isomorphic-strings/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        int len = s.length();
        vector<int> s2tMapping(256, -1);
        vector<bool> t2sShowed(256, false);

        for (int i = 0; i < len; ++i) {
            int sChar = s[i], tChar = t[i];
            if (s2tMapping[sChar] >= 0) {
                if (s2tMapping[sChar] != tChar)
                    return false;
            } else {
                if (t2sShowed[tChar])
                    return false;

                s2tMapping[sChar] = tChar;
                t2sShowed[tChar] = true;
            }
        }
        return true;
    }
};

// [Solution]: Except validate if s char can map to t char, also need to validate t char map to s char. So use a set. If cannot find s map to t, but can find t in set, return false
// [Corner Case]: ab vs aa
class SolutionHashmap {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();

        unordered_map<char, char> map;
        unordered_set<char> set;
        for (int i = 0; i < len; ++i) {
            if (map.find(s[i]) == map.end()) {
                map[s[i]] = t[i];
                if (set.find(t[i]) != set.end())
                    return false;
                set.insert(t[i]);
            } else {
                if (map[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << (sol.isIsomorphic("egg", "add") ? "True" : "False") << endl;
    cout << (sol.isIsomorphic("paper", "title") ? "True" : "False") << endl;
    cout << (sol.isIsomorphic("foo", "bar") ? "True" : "False") << endl;
    cout << (sol.isIsomorphic("ab", "aa") ? "True" : "False") << endl;

    return 0;
}
