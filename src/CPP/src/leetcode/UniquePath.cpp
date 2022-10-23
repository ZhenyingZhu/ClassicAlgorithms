/*
 * [Source] https://leetcode.com/problems/unique-paths/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Dynamic Programming
 */

#include <iostream>

using namespace std;

// [Solution]: D(m,n)=D(m-1,n)+D(m,n-1)
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/UniquePaths.java
 */

/* Java solution
public class Solution {
    public int uniquePaths(int m, int n) {
		if(m==0 || n==0) return 0;
        int[][] matrix=new int[m][n];
		matrix[0][0]=1;
		for(int i=1; i<m; i++){
			matrix[i][0]=1;
		}
		for(int j=1; j<n; j++){
			matrix[0][j]=1;
		}
		for(int i=1; i<m; i++){
			for(int j=1; j<n; j++){
				matrix[i][j]=matrix[i-1][j]+matrix[i][j-1];
			}
		}
		return matrix[m-1][n-1];
    }
}
 */

// [Solution]: (m-1+n-1)C(n-1). But why?

int main() {
    Solution sol;

    return 0;
}
