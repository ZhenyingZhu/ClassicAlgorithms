/*
 * [Source] https://leetcode.com/problems/unique-paths-ii/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Dynamic Programming
 */

#include <iostream>

using namespace std;

// [Solution]: D(m,n)=D(m-1,n)+D(m,n-1) || = 0
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/UniquePathsObstacles.java
 */

/* Java solution
public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
		int hei=obstacleGrid.length;
		int wid=obstacleGrid[0].length;
		if(obstacleGrid[0][0]==1 || obstacleGrid[hei-1][wid-1]==1) return 0;
        int[][] matrix=new int[hei][wid];
		matrix[0][0]=1;
		for(int i=1; i<hei; i++){
			matrix[i][0]=(obstacleGrid[i][0]==1)?0:matrix[i-1][0];
		}
		for(int j=1; j<wid; j++){
			matrix[0][j]=(obstacleGrid[0][j]==1)?0:matrix[0][j-1];
		}
		for(int i=1; i<hei; i++){
			for(int j=1; j<wid; j++){
				matrix[i][j]=(obstacleGrid[i][j]==1)?0:(matrix[i-1][j]+matrix[i][j-1]);
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
