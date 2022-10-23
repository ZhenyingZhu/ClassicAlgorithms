/*
 * [Source] https://leetcode.com/problems/longest-repeating-character-replacement/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

// [Solution]: Sliding window. In the sliding window, the char has max appearance can form the longest substring, with less than other k chars in the window.
// [Corner Case]:
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        unordered_map<char, int> charCntMap; // in the sliding window
        int maxCharCnt = 0;

        int st = 0;
        for (int ed = 0; ed < (int)s.length(); ++ed) {
            char &c = s[ed];
            ++charCntMap[c];
            maxCharCnt = max(charCntMap[c], maxCharCnt);
            // the char that has maxCharCnt doesn't need to be successive
            // in the sliding window, there should be less or equal than k other chars
            while (ed - st + 1 - maxCharCnt > k) {
                --charCntMap[ s[st] ];
                ++st;
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

    cout << sol.characterReplacement("ABAB", 2) << endl;
    cout << sol.characterReplacement("AABABBA", 1) << endl;

    return 0;
}
