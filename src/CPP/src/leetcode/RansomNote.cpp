/*
 * [Source] https://leetcode.com/problems/ransom-note/
 * [Difficulty]: Easy
 * [Tag]: String
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote == "")
            return true;

        unordered_map<char, int> charCnt;
        int len = 0;
        for (char &c : ransomNote) {
            ++charCnt[c];
            ++len;
        }

        for (char &c : magazine) {
            if (charCnt.find(c) != charCnt.end() && charCnt[c] > 0) {
                --charCnt[c];
                --len;

                if (len == 0)
                    return true;
            }
        }

        return false;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.canConstruct("a", "b") << endl;
    cout << sol.canConstruct("aa", "ab") << endl;
    cout << sol.canConstruct("aa", "aab") << endl;

    return 0;
}
