/*
 * [Source] https://leetcode.com/problems/search-a-2d-matrix/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Binary Search
 */

#include <iostream>

using namespace std;

// [Solution]: Write a function to convert 2D index to 1D index.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/sortandsearch/SearchA2DMatrix.java
 */

// [Solution]: First search Column, then search row
/* Java solution
public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix==null || matrix.length<=0 ||matrix[0].length<=0) return false;
		int row=matrix.length-1;
		int col=matrix[0].length-1;
		if(matrix[0][0]>target || matrix[row][col]<target) return false;
		int rowId=(row==0)?0:binarySearchRow(matrix, target, 0, row);
		int colId=binarySearchCol(matrix[rowId], target, 0, col);
		if(colId==-1) return false;
		return true;
    }
	
	public int binarySearchRow(int[][] matrix, int target, int start, int end){
		if(start>end) return end;
		if(matrix[start][0]==target) return start;
		if(matrix[end][0]==target) return end;
		if(matrix[start][0]<target && matrix[start+1][0]>target) return start;
		if(matrix[end][0]<target) return end;
		int mid=(start+end)/2;
		if(matrix[mid][0]==target) return mid;
		if(matrix[mid][0]>target) return binarySearchRow(matrix, target, start, mid-1);
		return binarySearchRow(matrix, target, mid, end);
	}
	
	public int binarySearchCol(int[] matrixRow, int target, int start, int end){
		if(start>end) return -1;
		int mid=(start+end)/2;
		if(matrixRow[mid]==target) return mid;
		if(matrixRow[mid]>target) return binarySearchCol(matrixRow, target, start, mid-1);
		return binarySearchCol(matrixRow, target, mid+1, end);
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
