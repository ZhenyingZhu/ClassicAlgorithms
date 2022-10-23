/*
 * [Source] https://leetcode.com/problems/rotate-image/
 * [Difficulty]: Medium
 * [Tag]: Array
 */

#include <iostream>

using namespace std;

// [Solution]: (x,y) moves to (y, n - x - 1). Each cell should only move once, so from (i, i) to (i, n - i -1), where i is from 0 to n/2.
// [Corner Case]: The middle
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/RotateImage.java
 */

/* Java solution
public class Solution {
    public void rotate(int[][] matrix) {
        if(matrix==null || matrix.length<=1) return; 
		if(matrix.length!=matrix[0].length) return;
		int n=matrix.length;
		for(int i=0; i<n/2; i++){
			for(int j=i; j<n-1-i; j++){
				int tmp=matrix[i][j];
				int x=i;
				int y=j;
				for(int c=0; c<3; c++){
					matrix[x][y]=matrix[n-1-y][x];
					int t=x;
					x=n-1-y;
					y=t;
				}
				matrix[x][y]=tmp;
			}
		}
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
