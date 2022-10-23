/*
 * [Source] https://leetcode.com/problems/remove-duplicate-letters/
 * [Difficulty]: Hard
 * [Tag]: Stack
 * [Tag]: Greedy
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// [Solution]: When add a new char into result, greedily remove all disorder chars in result, if they will show up again.
// [Corner Case]:
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> charNumLast; // the number of char in the remaining part of the string
        for (char& c : s)
            ++charNumLast[c];

        unordered_set<char> inResult;
        string res("0"); // 0 is smaller than any char

        for (char& c : s) {
            --charNumLast[c];
            // if it is already in result, it is in the position which has smallest lexicographical order, this one won't change it
            if (inResult.find(c) != inResult.end())
                continue;

            // keep the result in order. If meet one char in result that never shows up again, can stop. Otherwise will break the order
            while (c < res.back() && charNumLast[res.back()] > 0) {
                char& end = res.back();
                inResult.erase(end);
                res.pop_back();
            }

            res.push_back(c);
            inResult.insert(c);
        }

        return res.substr(1);
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.removeDuplicateLetters("bcabc") << endl;
    cout << sol.removeDuplicateLetters("cbacdcbc") << endl;

    return 0;
}
