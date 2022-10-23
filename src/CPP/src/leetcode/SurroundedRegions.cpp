/*
 * [Source] https://leetcode.com/problems/surrounded-regions/
 * [Difficulty]: Medium
 * [Tag]: Breadth-first Search
 * [Tag]: Union Find
 */

#include <iostream>

using namespace std;

// [Solution]: From borders, find all 'O's until hit 'X', and mark them with other mark like '*'. Then repaint all un '*' to be 'X'.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/SurroundedRegions.java
 */

/* Java solution
public class Solution {
    public void solve(char[][] board) {
		if(board==null || board.length<=1 || board[0].length<=1) return; 
		int len=board.length;
		int wid=board[0].length;
		for(int i=0; i<len; i++){
			mark(board, i, 0);
			mark(board, i, wid-1);
		}
		for(int j=0; j<wid; j++){
			mark(board, 0, j);
			mark(board, len-1, j);
		}
		for(int i=0; i<len; i++){
			for(int j=0; j<wid; j++){
				if(board[i][j]=='+') board[i][j]='O';
				else if(board[i][j]=='O') board[i][j]='X';
			}
		}
    }
	
	public void mark(char[][] board, int x, int y){
		if(board[x][y]!='O') return; 
		LinkedList<Integer> queue=new LinkedList<Integer>();
		queue.add(x*board[0].length+y);
		while(!queue.isEmpty()){
			int coor=queue.poll();
			int row=coor/board[0].length;
			int col=coor%board[0].length;
			if(board[row][col]=='O'){
				board[row][col]='+';
				if(row>0)
					queue.add((row-1)*board[0].length+col);
				if(row<board.length-1)
					queue.add((row+1)*board[0].length+col);
				if(col>0)
					queue.add(row*board[0].length+col-1);
				if(col<board[0].length-1)
					queue.add(row*board[0].length+col+1);
			}
		}
	}
}
 */

int main() {
    Solution sol;

    return 0;
}
