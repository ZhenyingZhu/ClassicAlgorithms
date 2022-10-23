#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

// [Source]: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/?tab=Description
// http://www.1point3acres.com/bbs/thread-228718-1-1.html

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int len = s.length();
        if (len < k)
            return len;

        int maxLen = 0;
        int st = 0;
        list<CharIdx> lastCharIdx;
        unordered_map<char, list<CharIdx>::iterator> charIterMap;
        for (int i = 0; i < len; ++i) {
            if (!charIterMap.count(s[i])) {
                lastCharIdx.push_back( {s[i], i} );
                charIterMap[s[i]] = --lastCharIdx.end();

                if ((int)lastCharIdx.size() > k) {
                    CharIdx &ci = lastCharIdx.front();
                    st = ci.idx + 1;
                    charIterMap.erase(ci.c);
                    lastCharIdx.erase(lastCharIdx.begin());
                }
            } else {
                list<CharIdx>::iterator it = charIterMap[s[i]];
                lastCharIdx.erase(it);
                lastCharIdx.push_back( {s[i], i} );
                charIterMap[s[i]] = --lastCharIdx.end();
            }

            maxLen = max(maxLen, i - st + 1);
        }

        return maxLen;
    }

private:
    struct CharIdx {
        char c;
        int idx;
    };
};

int main() {
    Solution sol;

    cout << sol.lengthOfLongestSubstringKDistinct("aabbacccc", 2) << endl;

    return 0;
}
