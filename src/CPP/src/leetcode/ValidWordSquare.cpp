/*
 * [Source] https://leetcode.com/problems/valid-word-square/
 * [Difficulty]: Easy
 * [Tag]: 
 */

#include <iostream>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (int i = 0; i < (int)words.size(); ++i) {
            int len = words[i].length();
            vector<char> tmp(len);
            for (int j = 0; j < len; ++j) {
                if (len > (int)words.size())
                    return false;
                if (words[j].length() <= i)
                    return false;
                tmp[j] = words[j][i];
            }
            if (string(tmp.begin(), tmp.end()) != words[i])
                return false;
        }
        return true;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
