/*
 * [Source] https://leetcode.com/problems/longest-palindrome/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 */

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

// [Solution]: If a char has appeared, len increase 2, and remove this char from set. If at the end the set is not empty, pick one single char from the set to be the center
// [Corner Case]:
class Solution {
public:
    int longestPalindrome(string s) {
        if (s.length() == 0)
            return 0;

        unordered_set<char> singleAppear;
        int len = 0;
        for (char &c : s) {
cout << c << endl;
            if (singleAppear.count(c)) {
cout << "find c" << endl;
                len += 2;
                singleAppear.erase(c);
            } else {
cout << "not find c" << endl;
                singleAppear.insert(c);
            }
        }
        return len + (singleAppear.empty() ? 0 : 1);
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //cout << sol.longestPalindrome() << endl;
    cout << sol.longestPalindrome("abccccdd") << endl;

    return 0;
}
