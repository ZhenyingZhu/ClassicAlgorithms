/*
 * [Source] https://leetcode.com/problems/reverse-string/
 * [Difficulty]: Easy
 * [Tag]: Two Pointers
 * [Tag]: String
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    string reverseString(string s) {
        vector<char> reverse;
        for (int i = s.length() - 1; i >= 0; --i) {
            reverse.push_back(s[i]);
        }
        return string(reverse.begin(), reverse.end());
    }
};

// [Solution]:

int main() {
    Solution sol;

    cout << sol.reverseString("hello") << endl;

    return 0;
}
