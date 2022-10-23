/*
 * [Source] https://leetcode.com/problems/minimum-unique-word-abbreviation/
 * [Difficulty]: Hard
 * [Tag]: Backtracking
 * [Tag]: Bit Manipulation
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// [Solution]: 1. convert each word in dict to a bitset, that the char diff from target sets to 1. 2. find a mask that and every word still left at least 1 bits.
// [Corner Case]:
class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        int len = target.length();

        vector<int> diffBitsets;
        int candidateBits = 0;
        for (string &str : dictionary) {
            if ((int)str.length() != len)
                continue;

            int diffBitset = 0; // if target[i] diff from str[i], i bit set to 1
            for (int i = 0; i < len; ++i) {
                if (target[i] != str[i]) {
                    diffBitset |= 1 << (len - 1 - i);
                }
            }
            diffBitsets.push_back(diffBitset);
            candidateBits |= diffBitset;
        }

//for (int &diffBitset : diffBitsets)
//    cout << diffBitset << endl;

        int abbr = 0;
        int minLen = INT_MAX;
        helper(0, 1, candidateBits, diffBitsets, abbr, minLen);

cout << abbr << endl;

        return convert(target, abbr);
    }

    void helper(int abbrCandidate, int highBit, int &candidateBits, vector<int> &diffBitsets, int &shortestAbbr, int &minLen) {
        // bit 1 in abbrCandidate means this char should keep, 0 means this char can convert to number
        int len = getAbbrLen(abbrCandidate);
cout << abbrCandidate << "len " << len << " " << candidateBits << " " << highBit << endl;
        if (len > minLen)
            return;

        bool notConflict = true;
        for (int &diffBitset : diffBitsets) {
            if ((diffBitset & abbrCandidate) == 0) {
                notConflict = false;
                break;
            }
        }

        if (notConflict) {
            shortestAbbr = abbrCandidate;
            minLen = len;
        } else {
            // highBit is the first bit position that could set. E.g. candidateBits is 111, highBit is 1, then next candidate is 001, next next candidate is 010
            for (int bit = highBit; bit <= candidateBits; bit <<= 1) {
                if ((bit & candidateBits) != 0) {
                    helper(abbrCandidate | bit, bit << 1, candidateBits, diffBitsets, shortestAbbr, minLen);
                }
            }
        }
    }

    int getAbbrLen(int abbrCandidate) {
        int cnt = 0;
        bool preIsZero = false;
        for (int bit = 1; bit <= abbrCandidate; bit <<= 1) {
            if ((abbrCandidate & bit) == 0) {
                if (!preIsZero) {
                    ++cnt;
                    preIsZero = true;
                }
            } else {
                ++cnt;
                preIsZero = false;
            }
        }
        return cnt;
    }

    string convert(string &target, int abbr) {
        string res;
        int cnt = 0;
        for (int idx = 0; idx < (int)target.length(); ++idx) {
            if ((abbr & ( 1 << (target.length() - 1 - idx) )) == 0) {
                ++cnt;
            } else {
                if (cnt != 0)
                    res += to_string(cnt);
                res += target.substr(idx, 1);
                cnt = 0;
            }
        }
        if (cnt != 0)
            res += to_string(cnt);

        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<string> dict = {"plain", "amber", "blade"};
    vector<string> dict = {"blade"};
    cout << sol.minAbbreviation("apple", dict) << endl;

    return 0;
}
