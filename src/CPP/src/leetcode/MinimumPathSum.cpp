/*
 * [Source] https://leetcode.com/problems/minimum-path-sum/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Dynamic Programming
 */

#include <iostream>

using namespace std;

// [Solution]: D(m,n)=A[m,n] + min(D(m-1,n), D(m,n-1))
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/MinimumPathSum.java
 */

/* Java solution
public class Solution {
    public int minPathSum(int[][] grid) {
        if(grid==null || grid.length<=0 || grid[0].length<=0) return 0;
		int hei=grid.length;
		int wid=grid[0].length;
		int[][] matrix=new int[hei][wid];
		matrix[0][0]=grid[0][0];
		for(int i=1; i<hei; i++){
			matrix[i][0]=matrix[i-1][0]+grid[i][0];
		}
		for(int j=1; j<wid; j++){
			matrix[0][j]=matrix[0][j-1]+grid[0][j];
		}
		for(int i=1; i<hei; i++){
			for(int j=1; j<wid; j++){
				matrix[i][j]=grid[i][j]+Math.min(matrix[i-1][j], matrix[i][j-1]);
			}
		}
		return matrix[hei-1][wid-1];
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
