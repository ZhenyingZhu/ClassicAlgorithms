/*
 * [Source] https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
 * [Difficulty]: Hard
 * [Tag]: Hash Table
 * [Tag]: Two Pointers
 * [Tag]: String
 */

#include <iostream>
#include <unordered_map>

using namespace std;

// [Solution]: Sliding window with a count indicate how many distinct chars showed up already.
// [Corner Case]: Notice map.count will also count keys that has value 0.
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.empty())
            return 0;

        unordered_map<char, int> charCnt;
        int distinct = 0;

        int st = 0, ed = 0;
        int len = 0;
        for (; ed < (int)s.length(); ++ed) {
            char &last = s[ed];
            if (!charCnt.count(last))
                ++distinct;
            ++charCnt[last];

            while (distinct > 2) {
                char &first = s[st++];
                --charCnt[first];
                if (charCnt[first] == 0) {
                    --distinct;
                    charCnt.erase(first);
                }
            }

            len = max(ed - st + 1, len);
        }

        return len;
    }
};

int main() {
    Solution sol;

    cout << sol.lengthOfLongestSubstringTwoDistinct("abcabcabc") << endl;

    return 0;
}
