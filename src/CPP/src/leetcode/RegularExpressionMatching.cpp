/*
 * [Source] https://leetcode.com/problems/regular-expression-matching/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 * [Tag]: Backtracking
 * [Tag]: String
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: DP. B(i, j) indicates p[0, i] == s[0, j]. 
// B(i, j) = B(i-1, j-1) && (p[i-1] == '.' || p[i-1] == s[j-1])
//         = p[i-1] == '*' && {for x = 0..j-1, B(i-1, x) && s[x..j-1] == p[i-2]}
// [Corner Case]: what if '**' shows up, or '*' at the beginning
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        if (p == ".*")
            return true;

        vector<vector<bool>> match(pLen + 1, vector<bool>(sLen + 1, false));
        match[0][0] = true;

        for (int pIdx = 0; pIdx < pLen; ++pIdx) {
            for (int sIdx = -1; sIdx < sLen; ++sIdx) {
                if (p[pIdx] == '*') {
                    // Error case: p[0] should not be '*', shouldn't has '**'
                    if (pIdx == 0 || p[pIdx - 1] == '*')
                        return false;
                    
                    match[pIdx + 1][sIdx + 1] = isMatchStar(s, p, pIdx, sIdx, match);

                } else {
                    if (sIdx == -1) {
                        match[pIdx + 1][0] = false;
                    } else if (p[pIdx] == '.' || p[pIdx] == s[sIdx]) {
                        match[pIdx + 1][sIdx + 1] = match[pIdx][sIdx];
                    }

                }
            } // pIdx
        } // sIdx

        return match[pLen][sLen];
    }

private:
    bool allSame(char prev, string& s, int st, int ed) {
        if (prev == '.')
            return true;

        for (int idx = st; idx <= ed; ++idx) {
            if (s[idx] != prev)
                return false;
        }
        return true;
    }

    bool isMatchStar(string& s, string& p, int pIdx, int sIdx, vector<vector<bool>>& match) {
        // pIdx >= 1, because first char cannot be '*'
        if (sIdx == -1) {
            return match[pIdx - 1][0];
        }

        for (int i = sIdx + 1; i >= 0; --i) {
            if (match[pIdx - 1][i]) {
                if (allSame(p[pIdx - 1], s, i, sIdx))
                    return true;
            }
        }

        return false;
    }

};

// [Solution]: Do the compare in forward direction. If p start with '[char]*', then try if for x = 0..ed, s[x..ed] match p[2..ed]
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/RegularExpressionMatching.java
 */

/* Java solution
public class Solution {
    public boolean isMatch(String s, String p) {
        if (p.length() == 0) {
            return s.length() == 0; 
        }
        if (p.length() == 1) { // base case
            return s.length() == 1 && (s.equals(p) || p.charAt(0) == '.'); 
        }
        if (p.charAt(1) != '*') {
            if (s.length() == 0 || (p.charAt(0) != '.' && s.charAt(0) != p.charAt(0))) {
                return false; 
            } else {
                return isMatch(s.substring(1), p.substring(1)); 
            }
        } else { // x*
            while (s.length() > 0 && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.')) {
                if (isMatch(s, p.substring(2))) {
                    return true; 
                }
                s = s.substring(1); 
            }
        }
        return isMatch(s, p.substring(2)); 
    }
}
 */

int main() {
    Solution sol;

    if (!sol.isMatch("a","a"))
        cout << "0 fail" << endl;
    if (sol.isMatch("aa","a"))
        cout << "1 fail" << endl;
    if (!sol.isMatch("aa","aa"))
        cout << "2 fail" << endl;
    if (sol.isMatch("aaa","aa"))
        cout << "3 fail" << endl;
    if (!sol.isMatch("aa", "a*"))
        cout << "4 fail" << endl;
    if (!sol.isMatch("aa", ".*"))
        cout << "5 fail" << endl;
    if (!sol.isMatch("ab", ".*"))
        cout << "6 fail" << endl;
    if (!sol.isMatch("aab", "c*a*b"))
        cout << "7 fail" << endl;
    if (!sol.isMatch("", ""))
        cout << "8 fail" << endl;
   if (!sol.isMatch("aab", "a*a*b"))
        cout << "9 fail" << endl;
   if (!sol.isMatch("aaab", "a*b"))
        cout << "10 fail" << endl;
   if (sol.isMatch("a", "ab*a"))
        cout << "11 fail" << endl;
   if (!sol.isMatch("aaa", "ab*ac*a"))
        cout << "12 fail" << endl;

   cout << "all passed" << endl;
   return 0;
}
