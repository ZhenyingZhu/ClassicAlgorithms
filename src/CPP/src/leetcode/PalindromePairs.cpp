/*
 * [Source] https://leetcode.com/problems/palindrome-pairs/
 * [Difficulty]: Hard
 * [Tag]: Hash Table
 * [Tag]: String
 * [Tag]: Trie
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// [Solution]: Use reverse string to find palindrome pair in hash table. Use ordered set to find lengthes
// [Corner Case]:
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> strIdxMap;
        set<int> lengths;
        for (int i = 0; i < (int)words.size(); ++i) {
            strIdxMap[words[i]] = i; // words are unique
            lengths.insert(words[i].length());
        }

        vector<vector<int>> res;
        for (int i = 0; i < (int)words.size(); ++i) {
            string reverseStr = words[i];
            reverse(reverseStr.begin(), reverseStr.end());

            if ( strIdxMap.find(reverseStr) != strIdxMap.end() && strIdxMap[reverseStr] != i ) {
                res.push_back({i, strIdxMap[reverseStr]}); // don't push backward, otherwise dup
            }

            int strLen = reverseStr.length();
            auto lastLenIt = lengths.find(strLen);
            for (auto it = lengths.begin(); it != lastLenIt; ++it) {
                int addLen = *it;

                string prefix = reverseStr.substr(0, addLen);
                if ( strIdxMap.find(prefix) != strIdxMap.end() && isPalindrome(words[i].substr(0, strLen - addLen)) )
                    res.push_back({strIdxMap[prefix], i});

                string suffix = reverseStr.substr(strLen - addLen);
                if ( strIdxMap.find(suffix) != strIdxMap.end() && isPalindrome(words[i].substr(addLen)) )
                    res.push_back({i, strIdxMap[suffix]});
            }
        }

        return res;
    }

    bool isPalindrome(string str) {
        int st = 0, ed = str.length() - 1;
        while (st + 1 <= ed) {
            if (str[st++] != str[ed--])
                return false;
        }
        return true;
    }
};

// [Solution]: sliding window on each string. Reverse the part in string and find it in hash table

int main() {
    Solution sol;

    //vector<string> words = {};
    //vector<string> words = {"bat", "tab", "cat"};
    //vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
    vector<string> words = {"a","abc","aba",""};
    for (vector<int> &vec : sol.palindromePairs(words))
        cout << vec[0] << "," << vec[1] << endl;

    return 0;
}
