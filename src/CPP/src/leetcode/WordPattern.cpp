/*
 * [Source] https://leetcode.com/problems/word-pattern/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// [Solution]: use a hash table to map pattern to string, and a set to indicate if a string shows up
// [Corner Case]:
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> vec = split(str);
for (string& st : vec)
    cout << st << " ";
cout << endl;

        if (vec.size() != pattern.length())
            return false;

        unordered_map<char, string> patMap;
        unordered_set<string> showedUp;
        for (int i = 0; i < (int)pattern.length(); ++i) {
            char c = pattern[i];
            if (patMap.find(c) == patMap.end()) {
                if (showedUp.find(vec[i]) != showedUp.end())
                    return false;

                patMap[c] = vec[i];
                showedUp.insert(vec[i]);
            } else {
                if (patMap[c] != vec[i])
                    return false;
            }
        }

        return true;
    }

    vector<string> split(string& str) {
        vector<string> vec;

        size_t st = 0;
        size_t space = str.find_first_of(" ");
        while (space != string::npos) {
            vec.push_back(str.substr(st, space - st));
            st = space + 1;
            space = str.find_first_of(" ", st);
        }
        vec.push_back(str.substr(st));

        return vec;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.wordPattern("abba", "dog cat cat dog") << endl;
    cout << sol.wordPattern("abba", "dog cat cat fish") << endl;
    cout << sol.wordPattern("aaaa", "dog cat cat dog") << endl;
    cout << sol.wordPattern("abba", "dog dog dog dog") << endl;

    return 0;
}
