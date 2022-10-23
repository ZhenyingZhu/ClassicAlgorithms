/*
 * [Source] https://leetcode.com/problems/edit-distance/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 * [Tag]: String
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// [Solution]: if w1[m]=w2[n], D[m,n]=D[m-1,n-1]. Else, D[m,n]= min( D[m-1,n-1]+1 // replace; D[m-1,n]+1 // del; D[m,n-1]+1 // add )
// [Corner Case]:
class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1Len = word1.length(), w2Len = word2.length();
        vector<vector<int>> matrix(w2Len + 1, vector<int>(w1Len + 1, -1));
        for (int i = 0; i <= w2Len; ++i)
            matrix[i][0] = i;
        for (int j = 1; j <= w1Len; ++j)
            matrix[0][j] = j;

        for (int i = 1; i <= w2Len; ++i) {
            for (int j = 1; j <= w1Len; ++j) {
                if (word2[i - 1] == word1[j - 1]) {
                    matrix[i][j] = matrix[i - 1][j - 1];
                    continue;
                }

                matrix[i][j] = 1 + min( matrix[i - 1][j - 1],  min(matrix[i][j - 1], matrix[i - 1][j]) );
            }
        }

        return matrix[w2Len][w1Len];
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/EditDistance.java
 */

/* Java solution
public class Solution {
    public int minDistance(String word1, String word2) {
        if(word1==null || word1.length()<=0) return word2.length();
		if(word2==null || word2.length()<=0) return word1.length();
		int len1=word1.length();
		int len2=word2.length();
		int[][] matrix=new int[len1+1][len2+1];
		for(int i=0; i<=len1; i++){
			matrix[i][0]=i;
		}
		for(int j=1; j<=len2; j++){
			matrix[0][j]=j;
		}
		for(int i=1; i<=len1; i++){
			for(int j=1; j<=len2; j++){
				if(word1.charAt(i-1)==word2.charAt(j-1)) matrix[i][j]=matrix[i-1][j-1];
				else{
					matrix[i][j]=Math.min(matrix[i][j-1]+1, matrix[i-1][j]+1);
					if(matrix[i][j]>(matrix[i-1][j-1]+1)) matrix[i][j]=matrix[i-1][j-1]+1;
				}
			}
		}
		return matrix[len1][len2];
    }
}
 */

int main() {
    Solution sol;

    cout << sol.minDistance("abcde", "abc") << endl;

    return 0;
}
