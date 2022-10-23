/*
 * [Source] https://leetcode.com/problems/palindrome-partitioning-ii/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: D[i]=D[i-x]+1 if s[x+1,i] is palindrome. Use DP to check if the partial of string is palindrome.
// [Corner Case]:
class Solution {
private:
    bool isPalindrome(const string& s, int st, int ed, vector<vector<bool>>& matrix) {
        if (st == ed) {
            matrix[st][ed] = true;
        } else if (s[st] == s[ed] && (st + 1 == ed || matrix[st + 1][ed - 1])) {
            matrix[st][ed] = true;
        }
        return matrix[st][ed];
    }

public:
    int minCut(string s) {
        int len = s.length();
        if (len == 0)
            return 0;

        vector<int> minCuts(len + 1, len - 1);
        minCuts[0] = -1;

        vector<vector<bool>> palindromeMatrix(len, vector<bool>(len, false));
        for (int ed = 1; ed <= len; ++ed) {
            for (int st = ed; st >= 1; --st) {
                if (isPalindrome(s, st - 1, ed - 1, palindromeMatrix)) {
                    minCuts[ed] = min(minCuts[st - 1] + 1, minCuts[ed]);
                }
            }
        }

        return minCuts[len];
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/PalindromePartitioningMinCut.java
 */

/* Java solution
public class Solution {
    public int minCut(String s) {
		// If s[i...j] is a palindrome, then cut(s[i...end])=cut(s[j+1]+1)
		int[] min=new int[s.length()+1]; 
		min[s.length()]=-1; // So cut at the end will return 0 cut
		boolean[][] matrix=new boolean[s.length()][s.length()];
		for(int i=s.length()-1; i>=0; i--){
			min[i]=min[i+1]+1; // cut itself out
			for(int j=i; j<s.length(); j++){
				if(s.charAt(i)==s.charAt(j)){ // Don't need to judge the head and the end
					if(j-i<2 || matrix[i+1][j-1]){
						matrix[i][j]=true; // It is palindrome
						/* This make sure that even char i is not in a palindrome, 
						it still can reach the right answer by cut it right after itself. */
						if(min[i]>min[j+1]+1) min[i]=min[j+1]+1; 
					}
				}
			}
		}
		return min[0];
    }
	
}
 */

int main() {
    Solution sol;

    cout << sol.minCut("a") << endl;
    cout << sol.minCut("aa") << endl;
    cout << sol.minCut("ab") << endl;
    cout << sol.minCut("aab") << endl;

    return 0;
}
