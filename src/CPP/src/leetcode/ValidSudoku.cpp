/*
 * [Source] https://leetcode.com/problems/valid-sudoku/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 */

#include <iostream>

using namespace std;

// [Solution]: For each row and column and square, hash exist number
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/datastructure/ValidSudoku.java
 */

/* Java solution
public class Solution {
    public boolean isValidSudoku(char[][] board) {
        int i, j, pos, id;
        int[][] allConstrains = new int[3 * 9][9]; 
        for (i = 0; i < 9; ++i) { 
            for (j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                pos = board[i][j] - '1'; 
                if (allConstrains[i][pos] == 1) { // Check row. 
                    return false; 
                } else {
                    allConstrains[i][pos] = 1;
                }
                if (allConstrains[9 + j][pos] == 1) { // Check col. 
                    return false; 
                } else {
                    allConstrains[9 + j][pos] = 1;
                }
                id = getBlockId(i, j); 
                if (allConstrains[id][pos] == 1) { // Check block. 
                    return false; 
                } else {
                    allConstrains[id][pos] = 1; 
                }
            }
        }
        return true; 
    }
    
    private int getBlockId(int x, int y) {
        int xAxis = x / 3; 
        int yAxis = y / 3; 
        return (18 + 3 * xAxis + yAxis); 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
