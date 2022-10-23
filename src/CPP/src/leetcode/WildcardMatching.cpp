/*
 * [Source] https://leetcode.com/problems/wildcard-matching/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 * [Tag]: Backtracking
 * [Tag]: Greedy
 * [Tag]: String
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: DP
// [Corner Case]:
class SolutionDP {
private:
    bool isPreviousMatch(const vector<vector<bool>>& matrix, int pPos, int sPos) {
        for (int i = 0; i <= sPos; ++i)
            if (matrix[pPos - 1][i])
                return true;
        return false;
    }

public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        if (pLen == 0)
            return sLen == 0;

        vector<vector<bool>> matrix(pLen + 1, vector<bool>(sLen + 1, false));
        matrix[0][0] = true;
        for (int i = 0; i < pLen && p[i] == '*'; ++i)
            matrix[i + 1][0] = true;

        for (int i = 1; i <= pLen; ++i) {
            char pattern = p[i - 1];
            for (int j = 1; j <= sLen; ++j) {
                if (pattern == '?' || s[j - 1] == pattern) {
                    matrix[i][j] = matrix[i - 1][j - 1];
                } else if (pattern == '*') {
                    matrix[i][j] = isPreviousMatch(matrix, i, j);
                } // else matrix[i][j] = false
            }
        }

        return matrix[pLen][sLen];
    }
};

// [Solution]: since if any partial of string matches pattern before star, then can continue compare.
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        int sp = 0, pp = 0;
        int star = -1, matched = -1;

        while (sp < sLen) {
            if ( pp < pLen && (p[pp] == '?' || s[sp] == p[pp]) ) {
                ++sp, ++pp;
            } else if (pp < pLen && p[pp] == '*') {
                star = pp++;
                matched = sp;
            } else if (star != -1) {
                pp = star + 1;
                sp = matched++;
            } else {
                return false;
            }
        }

        while (pp < pLen && p[pp] == '*')
            ++pp;

        return pp == pLen;
    }

};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/WildcardMatching.java
 */

/* Java solution
public class Solution {
    public boolean isMatch(String s, String p) {
		int i=0, j=0;
		int star=-1; // The position of star
		int mark=-1;
		while(i<s.length()){
			if(j<p.length() && (s.charAt(i)==p.charAt(j) || p.charAt(j)=='?')){
				i++; j++;
			}else if(j<p.length() && p.charAt(j)=='*'){
				star=j++;
				mark=i;
			}else if(star!=-1){ // Not match, but there is a star
				j=star+1;
				i=++mark; // Return i to avoid i==j cause i++ and j++
			}else{
				return false; // There is no star
			}
		}
		while(j<p.length() && p.charAt(j)=='*') j++;
		return j==p.length();		
    }  
}
 */

int main() {
    Solution sol;

    if (sol.isMatch("aa","a"))
        cout << 1 << endl;
    if (!sol.isMatch("aa","aa"))
        cout << 2 << endl;
    if (sol.isMatch("aaa","aa"))
        cout << 3 << endl;
    if (!sol.isMatch("aa", "*"))
        cout << 4 << endl;
    if (!sol.isMatch("aa", "a*"))
        cout << 5 << endl;
    if (!sol.isMatch("ab", "?*"))
        cout << 6 << endl;
    if (sol.isMatch("aab", "c*a*b"))
        cout << 7 << endl;
    if (sol.isMatch(
"bbaaabbababbbbbabababaaabbabbaabbbbbaaabbbaaababbbbababbbbabbbababaabababbbbbbbababaaababababbbbaabbaaaabbbaaabbbaababbbbababbbbbabbabbaabaabbaabaabbbabaabbbbbabababbabaabbababbabbbbabbbbaaaaaaaabbaab", 
"a**abaaa*b*aa*ba*****b*a*bb**bbab*a*aa**b***ba*a*aabb*bab**aa*ab*b**b*b*aabba******bbbb*aa*a****abb***b*"
    ))
        cout << 8 << endl;

    return 0;
}
