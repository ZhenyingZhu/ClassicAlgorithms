/*
 * [Source] https://leetcode.com/problems/find-the-difference/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 * [Tag]: Bit Manipulation
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// [Solution]: Use a hash map.
// [Corner Case]:
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> charCnt;
        for (char &c : s) {
            ++charCnt[c];
        }

        for (char &c : t) {
            --charCnt[c];
            if (charCnt[c] < 0)
                return c;
        }

        return '0';
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
