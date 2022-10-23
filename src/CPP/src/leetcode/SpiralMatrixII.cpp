/*
 * [Source] https://leetcode.com/problems/spiral-matrix-ii/
 * [Difficulty]: Medium
 * [Tag]: Array
 */

#include <iostream>

using namespace std;

// [Solution]: Use direction vectors. When encounter filled cell, turn right.
// [Corner Case]:
class Solution {
};

/* Java solution
public class Solution {
    public int[][] generateMatrix(int n) {
		int[][] matrix=new int[n][n];
        if(n<=0) return matrix;
		int[] xDir={0, 1, 0, -1};
		int[] yDir={1, 0, -1, 0};
		int pt=0;
		int x=0; 
		int y=0;
		for(int i=1; i<=n*n; i++){
			matrix[x][y]=i;
			if(changeDir(matrix, x, y, xDir, yDir, pt)){
				pt++;
				if(pt==4) pt=0;
			}
			x+=xDir[pt];
			y+=yDir[pt];
		}
		return matrix;
    }
	
	public boolean changeDir(int[][] matrix, int x, int y, int[] xDir, int[] yDir, int pt){
		x+=xDir[pt];
		if(x<0 || x>=matrix.length) return true;
		y+=yDir[pt];
		if(y<0 || y>=matrix[0].length) return true;
		if(matrix[x][y]!=0) return true;
		return false;
    }
}
 */

// [Solution]: use offset
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/SpiralMatrixGenerate.java
 */

int main() {
    Solution sol;

    return 0;
}
