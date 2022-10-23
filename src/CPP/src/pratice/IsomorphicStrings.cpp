#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// [Source]: https://leetcode.com/problems/isomorphic-strings/
// http://www.1point3acres.com/bbs/thread-224947-1-1.html

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapping;
        unordered_set<char> mapped;

        for (int i = 0; i < (int)s.length(); ++i) {
            if (mapping.count(s[i])) {
                if (mapping[s[i]] != t[i])
                    return false;
            } else if (mapped.count(t[i])) {
                return false;
            } else {
                mapping[s[i]] = t[i];
                mapped.insert(t[i]);
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    cout << sol.isIsomorphic("paper", "title") << endl;
    cout << sol.isIsomorphic("add", "bcd") << endl;
    cout << sol.isIsomorphic("add", "bbb") << endl;

    return 0;
}
