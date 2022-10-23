/*
 * [Source] https://leetcode.com/problems/sort-characters-by-frequency/
 * [Difficulty]: Medium
 * [Tag]: Hash Table
 * [Tag]: Heap
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Use sort.
// [Corner Case]:
class Solution {
public:
    struct CharFreq {
        char c;
        int freq;

        bool operator<(const CharFreq &other) {
            return freq > other.freq; // sort in descend order
        }
    };

    string frequencySort(string s) {
        unordered_map<char, int> charCnt;
        for (char &c : s)
            ++charCnt[c];

        vector<CharFreq> freqs;
        for (auto it = charCnt.begin(); it != charCnt.end(); ++it)
            freqs.push_back( {it->first, it->second} );

        sort(freqs.begin(), freqs.end());

        string res;
        for (CharFreq &cf : freqs)
            res += string(cf.freq, cf.c);

        return res;
    }
};

// [Solution]: Can also use bucket sort, since no char will shows more than s.length times.
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.frequencySort("Aabb") << endl;

    return 0;
}
