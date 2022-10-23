/*
 * [Source] https://leetcode.com/problems/palindrome-permutation-ii/
 * [Difficulty]: Medium
 * [Tag]: Backtracking
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// [Solution]: Use a vector to store candidates, and then create palindrome
// [Corner Case]:
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_set<char> showed;
        vector<char> showedTwice;
        for (char &c : s) {
            if (showed.count(c)) {
                showed.erase(c);
                showedTwice.push_back(c);
            } else {
                showed.insert(c);
            }
        }

        vector<string> res;
        if (showed.size() > 1)
            return res;

        sort(showedTwice.begin(), showedTwice.end());
        vector<bool> used(showedTwice.size(), false);

        string mid = "";
        if (showed.size() == 1)
            mid += *showed.begin();

        helper(mid, s.length(), showedTwice, used, res);
        return res;
    }

    void helper(string mid, size_t len, vector<char> &candidates, vector<bool> &used, vector<string> &res) {
        if (mid.length() == len) {
            res.push_back(mid);
            return;
        }

        for (int i = 0; i < (int)candidates.size(); ++i) {
            if (i != 0 && candidates[i] == candidates[i - 1] && !used[i - 1])
                continue; // remove dup
            if (used[i])
                continue;

            used[i] = true;
            char &c = candidates[i];
            helper(c + mid + c, len, candidates, used, res);
            used[i] = false;
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //for (string &s : sol.generatePalindromes("aabbb")) {
    for (string &s : sol.generatePalindromes("aabc")) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
