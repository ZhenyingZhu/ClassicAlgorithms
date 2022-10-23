/*
 * [Source] https://leetcode.com/problems/shortest-palindrome/
 * [Difficulty]: Hard
 * [Tag]: String
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Find the longest palindrome, and then reverse the left part and concate to the begining
// [Corner Case]:
class SolutionMemoryOut {
public:
    string shortestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }

        vector<vector<int>> matrix(s.length(), vector<int>(s.length(), 2));
        for (int i = (int)s.length() - 1; i >= 0; --i) {
            if (isPalindrome(s, 0, i, matrix)) {
                return construct(s, i + 1);
            }
        }
        return s; // should not reach here
    }

private:
    bool isPalindrome(string& s, int st, int ed, vector<vector<int>>& matrix) {
        if (s[st] != s[ed])
            return false;
        if (matrix[st][ed] == 0)
            return false;
        if (matrix[st][ed] == 1)
            return true;

        if (st + 2 >= ed || isPalindrome(s, st + 1, ed - 1, matrix)) {
            matrix[st][ed] = 1;
            return true;
        }
        matrix[st][ed] = 0;
        return false;
    }

    string construct(string& s, int palLen) {
cout << palLen << endl;
        string tmp = s.substr(palLen, s.length() - palLen);
        reverse(tmp.begin(), tmp.end());
        return tmp + s;
    }
};

// [Solution]: Reverse the string and concate to the end with a special char in the middle. Use the longest prefix suffix array from KMP algorithm to find the longest suffix at the end.
class Solution {
public:
    string shortestPalindrome(string s) {
        string r(s);
        reverse(r.begin(), r.end());
        string tmp = s + "#" + r;

        // KMP compute LPS
        vector<int> lps(tmp.length(), 0);
        for (int i = 1; i < (int)tmp.length(); ++i) {
            int len = lps[i - 1];
            while (len > 0 && tmp[i] != tmp[len]) {
                len = lps[len - 1];
            }

            // lps[i] = (j += tmp[i] == tmp[j]);
            if (tmp[i] == tmp[len]) {
                lps[i] = ++len;
            } else {
                lps[i] = len;
            }
        }
for (int& num : lps)
    cout << num << " ";
cout << endl;

        return r.substr(0, s.length() - lps[tmp.length() - 1]) + s;
    }
};

int main() {
    Solution sol;

    //cout << sol.shortestPalindrome("abcd") << endl;
    //cout << sol.shortestPalindrome("aacecaaa") << endl;
    //cout << sol.shortestPalindrome("ababc") << endl;
    cout << sol.shortestPalindrome("aaacaaaa") << endl;

    return 0;
}
