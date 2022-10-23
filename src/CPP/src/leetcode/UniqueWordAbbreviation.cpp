/*
 * [Source] https://leetcode.com/problems/unique-word-abbreviation/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 * [Tag]: Design
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// [Solution]: Too vague.
// [Corner Case]: Dictionary may contain dup, which should count as 1. isUnique might pass in word that is in dictionary or not in.
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string &str : dictionary) {
            if (set.count(str))
                continue;
            set.insert(str);
            string abbr = getAbbr(str);
            map[abbr]++;
        }
    }

    bool isUnique(string word) {
        string abbr = getAbbr(word);
        if (set.count(word))
            return map[abbr] == 1;
        else
            return map[abbr] == 0;
    }

    string getAbbr(string &str) {
        return str.front() + to_string(str.length() - 2) + str.back();
    }

    unordered_map<string, int> map;
    unordered_set<string> set;
};

class Solution {
public:
    void test() {
        vector<string> dictionary = {"deer", "door", "cake", "card"};
        ValidWordAbbr vwa(dictionary);

        vector<string> words = {"dear", "cart", "cane", "make"};
        for (string &word : words) {
            cout << vwa.isUnique(word) << endl;
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    sol.test();

    return 0;
}
