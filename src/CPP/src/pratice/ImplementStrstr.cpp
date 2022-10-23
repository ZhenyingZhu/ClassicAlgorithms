#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/implement-strstr/#/description
// http://www.1point3acres.com/bbs/thread-226625-1-1.html
// KMP

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        if (haystack.empty() || haystack.length() < needle.length())
            return -1;

        vector<int> lps = computeLPS(needle);

        vector<int> positions;
        int ph = 0, pn = 0;
        while (ph < (int)haystack.length()) {
            if (haystack[ph] == needle[pn]) {
                ph++;
                pn++;
                if (pn == (int)needle.length()) {
                    positions.push_back(ph - needle.length());
                    pn = lps[pn - 1];
                }
                continue;
            }

            if (pn == 0)
                ph++;
            else
                pn = lps[pn - 1];
        }

        for (int &num : positions)
            cout << num << ": " << haystack.substr(num, needle.length()) << endl;

        if (positions.empty())
            return -1;
        return positions[0];
    }

    vector<int> computeLPS(string &needle) {
        vector<int> lps(needle.length());
        lps[0] = 0;
        int len = 0, pt = 1;
        while (pt < (int)needle.length()) {
            if (needle[pt] == needle[len]) {
                lps[pt++] = ++len;
            } else if (len == 0) {
                lps[pt++] = 0;
            } else {
                len = lps[len - 1];
            }
        }
        return lps;
    }
};

int main() {
    Solution sol;

    cout << sol.strStr("ababa", "aba") << endl;

    return 0;
}
