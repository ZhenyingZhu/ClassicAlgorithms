/*
 * [Source] https://leetcode.com/problems/repeated-dna-sequences/
 * [Difficulty]: Medium
 * [Tag]: Hash Table
 * [Tag]: Bit Manipulation
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Substrings can overlap. So for substrings from each char, use a hash set to record them, and if it shows up again, print.
// [Corner Case]: Duplicate result. Use hash set to remove
class SolutionBruteForce {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() <= 10)
            return {};

        unordered_set<string> set, resSet;
        for (size_t i = 0; i <= s.length() - 10; ++i) {
            string cur = s.substr(i, 10);
            if (set.find(cur) != set.end()) {
                resSet.insert(cur);
            }
            set.insert(cur);
        }
        return vector<string>(resSet.begin(), resSet.end());
    }
};

// [Solution]: Rolling Hash
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() <= 10)
            return {};
        unordered_set<int> set;

        int hash = getInitHashCode(s);
        set.insert(hash);

        vector<string> res;
        for (size_t i = 1; i <= s.length() - 10; ++i) {
            hash = getNextHashCode(s, i, hash);
cout << hash << endl;
            if (set.find(hash) != set.end()) {
                string str(s.begin() + i, s.begin() + i + 10);
                if (find(res.begin(), res.end(), str) == res.end())
                    res.push_back(str);
            }
            set.insert(hash);
        }
        return res;
    }

private:
    int encoding(const char& c) {
        switch(c) {
            case 'A':
                return 0;
                break;
            case 'C':
                return 1;
                break;
            case 'G':
                return 2;
                break;
            case 'T':
                return 3;
                break;
            default:
                return -1;
                break;
        }
    }

    int getInitHashCode(const string& s) {
        int hash = 0;
        for (int i = 0; i < 10; ++i) {
            hash = 4 * hash + encoding(s[i]);
        }
        return hash;
    }

    int getNextHashCode(const string& s, size_t st, int preHash) {
        return (preHash * 4 + encoding(s[st + 10 - 1])) & ((1 << 20) - 1);
    }
};

int main() {
    Solution sol;

    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    //string s = "AAA";
    for (string& str : sol.findRepeatedDnaSequences(s))
        cout << str << endl;

    return 0;
}
