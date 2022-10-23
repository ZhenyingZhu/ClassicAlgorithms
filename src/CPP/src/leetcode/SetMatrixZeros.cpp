/*
 * [Source] https://leetcode.com/problems/set-matrix-zeroes/
 * [Difficulty]: Medium
 * [Tag]: Array
 */

#include <iostream>

using namespace std;

// [Solution]: For the cells except borders, if its 0, set its left most and up most cell to be 0. Do the border an the end.
// [Corner Case]: If left up most is 0.
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/SetMatrixZeroes.java
 */

/* Java solution
public class Solution {
    public void setZeroes(int[][] matrix) {
        if(matrix==null || matrix.length<=0 || matrix[0].length<=0) return;
		boolean leftSide=false; //Separate judge
		for(int i=0; i<matrix.length; i++){
			if(matrix[i][0]==0) leftSide=true;
		}
		boolean upSide=false; //Separate judge
		for(int j=0; j<matrix[0].length; j++){
			if(matrix[0][j]==0) upSide=true;
		}
		for(int i=1; i<matrix.length; i++){
			for(int j=1; j<matrix[0].length; j++){
				if(matrix[i][j]==0){
					matrix[i][0]=0;
					matrix[0][j]=0;
				}
			}
		}
		for(int i=1; i<matrix.length; i++){
			for(int j=1; j<matrix[0].length; j++){
				if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
			}
		}
		if(leftSide){
			for(int i=0; i<matrix.length; i++) matrix[i][0]=0;
		}
		if(upSide){
			for(int j=0; j<matrix[0].length; j++) matrix[0][j]=0;
		}
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
