/*
 * [Source] https://leetcode.com/problems/word-pattern-ii/
 * [Difficulty]: Hard
 * [Tag]: Backtracking
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// [Solution]:
// [Corner Case]: When a string is already pair to a char, it cannot pair to another char
class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> charStrMap;
        unordered_set<string> used;
        return helper(charStrMap, pattern, 0, str, 0, used);
    }

    bool helper(unordered_map<char, string> &charStrMap, string &pattern, int pIdx, string &str, int sIdx, unordered_set<string> &used) {
        if (pIdx == (int)pattern.length())
            return sIdx == (int)str.length();

        char &p = pattern[pIdx];
        if (charStrMap.count(p)) {
            string &shouldBe = charStrMap[p];
            if (sIdx + shouldBe.length() > str.length()) {
                return false;
            } else if (str.substr(sIdx, shouldBe.length()) == shouldBe) {
                return helper(charStrMap, pattern, pIdx + 1, str, sIdx + shouldBe.length(), used);
            } else {
                return false;
            }
        } else {
            for (int len = 1; len <= (int)str.length() - sIdx; ++len) {
                string couldBe = str.substr(sIdx, len);
                if (used.count(couldBe))
                    continue;
                used.insert(couldBe);
                charStrMap[p] = couldBe;
                if ( helper(charStrMap, pattern, pIdx + 1, str, sIdx + len, used) )
                    return true;
                charStrMap.erase(p);
                used.erase(couldBe);
            }
        }
        return false;
    }
};

// [Solution]:

int main() {
    Solution sol;

    //cout << sol.wordPatternMatch("abab", "redblueredblue") << endl;
    //cout << sol.wordPatternMatch("aaaa", "asdasdasdasd") << endl;
    //cout << sol.wordPatternMatch("aabb", "xyzabcxzyabc") << endl;
    cout << sol.wordPatternMatch("ab", "xx") << endl;

    return 0;
}
