package algorithms.datastructure; 

import java.util.*; 

public class ValidSudoku {
    /* Function: Check if a sudoku is valid till now. The empty part is '.'. 
     * Solution: Use three matrixes as hash table. 
     */ 
    
    public boolean isValidSudoku(char[][] board) {
        if (board == null || board.length != 9 || board[0].length != 9) {
            return false; 
        }
        
        boolean[][][] check = new boolean[3][9][9]; // row, col, grid
        
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] == '.') {
                    continue; 
                }
                
                if (!valid(i, j, board[i][j] - '0', check)) {
                    return false; 
                }
            }
        }
        
        return true; 
    }
    
    private boolean valid(int x, int y, int val, boolean[][][] check) {
        if (val <= 0 || val > 9) {
            return false; 
        }
        
        if (check[0][x][val - 1]) {
            return false; 
        } else {
            check[0][x][val - 1] = true; 
        }
        
        if (check[1][y][val - 1]) {
            return false; 
        } else {
            check[1][y][val - 1] = true;
        }
        
        if (check[2][x / 3 * 3 + y / 3][val - 1]) {
            return false; 
        } else {
            check[2][x / 3 * 3 + y / 3][val - 1] = true; 
        }
        
        return true; 
    }
} 