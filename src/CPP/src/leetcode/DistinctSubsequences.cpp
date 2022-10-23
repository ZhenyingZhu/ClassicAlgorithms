/*
 * [Source] https://leetcode.com/problems/distinct-subsequences/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 * [Tag]: String
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// [Solution]: i is target, j is source. D[i][j]=D[i-1][j]+1 if t[i]=s[j], or 0.
// [Corner Case]:
class Solution {
public:
    int numDistinct(string s, string t) {
        int sLen = s.length(), tLen = t.length();
        if (tLen > sLen)
            return 0;

        vector<vector<int>> ways(tLen + 1, vector<int>(sLen + 1));
        for (int i = 1; i <= tLen; ++i)
            ways[i][0] = 0;
        for (int j = 0; j <= sLen; ++j)
            ways[0][j] = 1;

        for (int i = 1; i <= tLen; ++i) {
            for (int j = 1; j <= sLen; ++j) {
                ways[i][j] = ways[i][j - 1];
                if (t[i - 1] == s[j - 1])
                    ways[i][j] += ways[i - 1][j - 1];
            }
        }
/*
for (int i = 0; i <= tLen; ++i) {
    for (int j = 0; j <= sLen; ++j) {
        cout << ways[i][j] << "|";
    }
    cout << endl;
}
*/
        return ways[tLen][sLen];
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/DistinctSubsequences.java
 */

/* Java solution
public class Solution {
    public int numDistinct(String S, String T) {
		if(S.length()<1) return 0;
		if(T.length()<1) return S.length();
		int[][] matrix=new int[T.length()+1][S.length()+1];
		for(int i=0; i<=S.length(); i++){
			matrix[0][i]=1;
		}
		for(int i=1; i<=T.length(); i++){
			for(int j=1; j<=S.length(); j++){
				if(S.charAt(j-1)==T.charAt(i-1)){
					matrix[i][j]=matrix[i-1][j-1]+matrix[i][j-1];
				}else{
					matrix[i][j]=matrix[i][j-1];
				}
			}
		}
		return matrix[T.length()][S.length()];
    }
}
 */

int main() {
    Solution sol;

    cout << sol.numDistinct("rabbbit", "rabbit") << endl;
    //cout << sol.numDistinct("rabbb", "rabb") << endl;

    return 0;
}
