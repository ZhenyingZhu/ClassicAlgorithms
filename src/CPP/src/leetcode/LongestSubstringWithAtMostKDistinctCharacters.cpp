/*
 * [Source] https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
 * [Difficulty]: Hard
 * [Tag]: Hash Table
 * [Tag]: String
 */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// [Solution]: Sliding window
// [Corner Case]:
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if ((int)s.length() <= k)
            return s.length();
        if (k == 0)
            return 0;

        unordered_map<char, int> charCnt;
        int distinct = 0;

        int maxLen = 0;
        int st = 0;
        for (int ed = 0; ed < (int)s.length(); ++ed) {
            char &last = s[ed];
            if (!charCnt.count(last))
                ++distinct;
            ++charCnt[last];

            while (distinct > k) {
                char &first = s[st++];
                --charCnt[first];
                if (charCnt[first] == 0) {
                    charCnt.erase(first);
                    --distinct;
                }
            }

            maxLen = max(ed - st + 1, maxLen);
        }
        return maxLen;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.lengthOfLongestSubstringKDistinct("abcabcabc", 2) << endl;
    cout << sol.lengthOfLongestSubstringKDistinct("abcabcabc", 3) << endl;

    return 0;
}
