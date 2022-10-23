/*
 * [Source] https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// [Solution]: Use an int as mask to find not completed char. Each time start from the next char of previous run.
// [Corner Case]:
class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxLen = 0;
        int st = 0;
        while (st + k < (int)s.length()) {
            int currentEnd = st; // this is the found longest substring. Don't need check again

            unordered_map<char, int> charCnt;
            unsigned int validCharMask = 0; // each bit means a char. If it is 0, means this char has appeared k times
            for (int ed = st; ed < (int)s.length(); ++ed) {
                char &cur = s[ed];
                ++charCnt[cur];
                if (charCnt[cur] < k) {
                    validCharMask |= 1U << (cur - 'a');
                } else {
                    validCharMask &= ~(1U << (cur - 'a'));
                }

                if (validCharMask == 0) {
                    maxLen = max(ed - st + 1, maxLen);
                    currentEnd = ed;
                }
            }

            st = currentEnd + 1; // If this run doesn't find any valid substring, move one char ahead
        }
        return maxLen;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.longestSubstring("aaabb", 3) << endl;
    cout << sol.longestSubstring("ababbc", 2) << endl;
    cout << sol.longestSubstring("ababacb", 3) << endl;

    return 0;
}
