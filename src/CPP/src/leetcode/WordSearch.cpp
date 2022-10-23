/*
 * [Source] https://leetcode.com/problems/word-search/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Backtracking
 */

#include <iostream>

using namespace std;

// [Solution]: Walk through all cells. If find the first char, mark this cell and check its adjacent cells.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/WordSearch.java
 */

/* Java solution
public class Solution {
    public boolean exist(char[][] board, String word) {
        char[] letters=word.toCharArray();
		boolean result=false;
		boolean[][] visited=new boolean[board.length][board[0].length];
		for(int i=0; i<board.length; i++){
			for(int j=0; j<board[0].length; j++){
				result|=exist(board, letters, 0, i, j, visited);
			}
		}
		return result;
    }
	
	public boolean exist(char[][] board, char[] word, int idx, int x, int y, boolean[][] visited){
		if(idx==word.length) return true;
		if(x<0 || x>=board.length || y<0 || y>=board[0].length){
			return false; // Out bound
		}
		if(visited[x][y]) return false; // Used
		if(board[x][y]!=word[idx]){
			return false; // Not match
		}
		visited[x][y]=true;
		boolean res=exist(board, word, idx+1, x-1, y, visited)
		||  exist(board, word, idx+1, x+1, y, visited)
		||  exist(board, word, idx+1, x, y-1, visited)
		||  exist(board, word, idx+1, x, y+1, visited);
		visited[x][y]=false;
		return res;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
