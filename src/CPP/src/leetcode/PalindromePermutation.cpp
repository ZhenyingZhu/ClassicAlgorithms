/*
 * [Source] https://leetcode.com/problems/palindrome-permutation/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 */

#include <iostream>
#include <unordered_set>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> shows;
        for (char &c : s) {
            if (shows.count(c))
                shows.erase(c);
            else
                shows.insert(c);
        }
        return shows.size() <= 1;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.canPermutePalindrome("code") << endl;
    cout << sol.canPermutePalindrome("aab") << endl;
    cout << sol.canPermutePalindrome("carerac") << endl;

    return 0;
}
