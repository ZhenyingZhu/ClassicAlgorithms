/*
 * [Source] https://leetcode.com/problems/implement-strstr/
 * [Difficulty]: Easy
 * [Tag]: Two Pointers
 * [Tag]: String
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: KMP
// [Corner Case]: the pattern is longer than search string
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        if (haystack.size() < needle.size())
            return -1;
        vector<int> lps = computeLPS(needle);

cout << "lps: ";
for (int &idx : lps)
    cout << idx << " ";
cout << endl;

        int searchIdx = 0, patternIdx = 0;
        vector<int> positions;
        while ( searchIdx < (int)haystack.length() ) {
            if (patternIdx == -1) { // when hit here, it means no match between current haystack char
                ++patternIdx;
                ++searchIdx;
                continue;
            }

            if (haystack[searchIdx] == needle[patternIdx]) {
                ++patternIdx;
                if (patternIdx == (int)needle.length()) {
                    positions.push_back(searchIdx + 1 - needle.length());
                    patternIdx = lps.back();
                } else {
                    ++searchIdx;
                }
            } else {
                patternIdx = lps[patternIdx];
            }
        }

cout << "positions" << endl;
for (int &idx : positions) {
    cout << idx << " ";
    cout << haystack.substr(idx, 7) << endl;
}

        return positions.empty() ? -1 : positions.front();
    }

    vector<int> computeLPS(const string &pattern) {
        vector<int> lps(pattern.size());
        lps[0] = -1; // set to -1 is to prevent infinate loop
        if (lps.size() >= 2)
            lps[1] = 0;

        int idx = 2;
        int sufixLen = 0;
        while (idx < (int)pattern.size()) {
            if (pattern[idx - 1] == pattern[sufixLen]) {
                ++sufixLen;
                lps[idx] = sufixLen;
                ++idx;
            } else if (sufixLen > 0) {
                sufixLen = lps[sufixLen];
            } else {
                lps[idx] = 0;
                ++idx;
            }
        }
        return lps;
    }
};

// [Solution]: Two level for loop
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/ImplementStrStr.java
 */

/* Java solution
public class Solution {
    public String strStr(String haystack, String needle) {
        if(haystack == null || needle == null || needle.length() == 0) {
            return haystack; 
        }
        if(haystack.length() < needle.length()) {
            return null; 
        }
        int j; 
        for(int i = 0; i <= haystack.length() - needle.length(); ++i) {
            if(haystack.charAt(i) == needle.charAt(0)) {
                for(j = 1; j < needle.length(); ++j) {
                    if(haystack.charAt(i + j) != needle.charAt(j)) {
                        break; 
                    }
                }
                if(j == needle.length()) {
                    return haystack.substring(i); 
                }
            }
        }
        return null; 
    }
}
 */

int main() {
    Solution sol;

    cout << sol.strStr("ABCDABDABC ABCDAB ABCDABCDABDE", "ABCDABD") << endl;
    cout << sol.strStr("a", "a") << endl;
    cout << sol.strStr("abcde", "f") << endl;

    cout << endl;

    return 0;
}
