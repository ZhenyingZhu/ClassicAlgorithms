/*
 * [Source] https://leetcode.com/problems/longest-palindromic-substring/
 * [Difficulty]: Medium
 * [Tag]: String
 * [Tag]: DP
 */

#include <iostream>

using namespace std;

// [Solution]: Use a boolean matrix which indicates substring between st and ed is palindrom or not. So isPalindrom(st, ed) = str(st) == str(ed) && isPalindrom(st + 1, ed - 1).
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/LongestPalindromicSubstring.java
 */

/* Java solution
public class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.length() <= 1) {
            return s; 
        }
        boolean[][] f = new boolean[s.length()][s.length()]; 
        int st = 0; 
        int maxLen = 1; 
        int i, j; 
        for (i = 0; i < s.length(); ++i) {
            f[i][i] = true; 
            for (j = 0; j < i; ++j) {
                f[j][i] = s.charAt(j) == s.charAt(i) && (i <= j + 1 || f[j + 1][i - 1]); 
                if (f[j][i] && i - j + 1 >maxLen) {
                    st = j; 
                    maxLen = i - j + 1; 
                }
            }
        }
        return s.substring(st, st + maxLen); 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
