/*
 * [Source] https://leetcode.com/problems/first-unique-character-in-a-string/
 * [Difficulty]: Easy
 * [Tag]: 
 */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// [Solution]: Scan twice
// [Corner Case]:
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charCnt;
        for (char &c : s) {
            ++charCnt[c];
        }

        for (int i = 0; i < (int)s.size(); ++i) {
            if (charCnt[ s[i] ] == 1)
                return i;
        }
        return -1;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
