/*
 * [Source] https://leetcode.com/problems/interleaving-string/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 * [Tag]: String
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// [Solution]: D[i][j] = T if s3[i+j]==s1[i] && D[i-1][j] or s3[i+j]==s2[j] && D[i][j-1]
// [Corner Case]:
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len3 != len1 + len2)
            return false;

        vector<vector<bool>> s1s2Interleave(len1 + 1, vector<bool>(len2 + 1, false));
        s1s2Interleave[0][0] = true;
        for (int i = 1; i <= len1; ++i)
            s1s2Interleave[i][0] = s1s2Interleave[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        for (int j = 1; j <= len2; ++j)
            s1s2Interleave[0][j] = s1s2Interleave[0][j - 1] && (s2[j - 1] == s3[j - 1]);

        for (int s1Idx = 1; s1Idx <= len1; ++s1Idx) {
            for (int s2Idx = 1; s2Idx <= len2; ++s2Idx) {
                if (s3[s1Idx + s2Idx - 1] == s1[s1Idx - 1] && s1s2Interleave[s1Idx - 1][s2Idx])
                    s1s2Interleave[s1Idx][s2Idx] = true;
                if (s3[s1Idx + s2Idx - 1] == s2[s2Idx - 1] && s1s2Interleave[s1Idx][s2Idx - 1])
                    s1s2Interleave[s1Idx][s2Idx] = true;
            }
        }

        return s1s2Interleave[len1][len2];
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/InterleavingString.java
 */

/* Java solution
public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
		if(s3.length()!=(s1.length()+s2.length())) return false;
		boolean[][] matrix=new boolean[s1.length()+1][s2.length()+1];
		matrix[0][0]=true;
		int pt1=1;
		int pt2=1;
		for(int i=1; i<=s1.length(); i++){
			if(s3.charAt(i-1)==s1.charAt(i-1)) matrix[i][0]=true;
		}
		for(int j=1; j<=s2.length(); j++){
			if(s3.charAt(j-1)==s2.charAt(j-1)) matrix[0][j]=true;
		}
		for(int i=1; i<=s1.length(); i++){
			for(int j=1; j<=s2.length(); j++){
				if(s3.charAt(i+j-1)==s1.charAt(i-1)) matrix[i][j] |=matrix[i-1][j];
				if(s3.charAt(i+j-1)==s2.charAt(j-1)) matrix[i][j] |=matrix[i][j-1];
			}
		}
		return matrix[s1.length()][s2.length()];
    }
}
 */

int main() {
    Solution sol;

    /*
    if (!sol.isInterleave("aabcc", "dbbca", "aadbbcbcac"))
        cout << "1 fail" << endl;
    if (sol.isInterleave("aabcc", "dbbca", "aadbbbaccc"))
        cout << "2 fail" << endl;
    */
    if (!sol.isInterleave("aabc", "abad", "aabadabc"))
        cout << "3 fail" << endl;

    return 0;
}
