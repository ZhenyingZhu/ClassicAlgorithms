/*
 * [Source] https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Sliding window
// [Corner Case]:
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> oriCharCnt(26, 0);
        for (char &c : p)
            ++oriCharCnt[c - 'a'];

        vector<int> res;
        vector<int> runCharCnt(26, 0);
        int st = 0;
        for (int i = 0; i < (int)s.length(); ++i) {
            int idx = s[i] - 'a';
            ++runCharCnt[idx];
            while (runCharCnt[idx] > oriCharCnt[idx]) {
                int stIdx = s[st++] - 'a';
                --runCharCnt[stIdx];
            }

            if (i - st + 1 == (int)p.length()) {
                res.push_back(st);
                --runCharCnt[ s[st++] - 'a' ];
            }
        }

        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    for (int &i : sol.findAnagrams("abacba", "ab"))
        cout << i << " ";
    cout << endl;

    return 0;
}
