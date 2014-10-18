package algorithms.arrandstring; 

import java.util.*; 

public class SudokuSolver {
    /* Function: Solve a Sudoku. 
     * Solution: DFS. Set a number, check if it is valid, then pass it to 
     *     try next cell. If a cell cannot fill any number return false. 
     *     When all cells filled, return true. 
     */ 
    
    public void solveSudoku(char[][] board) {
        if (board == null || board.length != 9 || board[0].length != 9) {
            return; 
        }
        
        sudokuHelper(board); 
    }
    
    private boolean sudokuHelper(char[][] board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    continue; 
                }
                
                for (char c = '1'; c <= '9'; ++c) {
                    board[i][j] = c; 
                    if (valid(board, i, j) && sudokuHelper(board)) {
                        return true; 
                    }
                    
                    board[i][j] = '.'; 
                }
                return false; 
            }
        }
        
        return true; 
    }
    
    private boolean valid(char[][] board, int x, int y) {
        char c = board[x][y]; 
        for (int i = 0; i < 9; ++i) {
            if (board[i][y] == c && i != x) {
                return false; 
            }
        }

        for (int j = 0; j < 9; ++j) {
            if (board[x][j] == c && j != y) {
                return false; 
            }
        }
        
        int sx = (x / 3) * 3, sy = (y / 3) * 3; 
        for (int k = 0; k < 9; ++k) {
            if (board[sx + k / 3][sy + k % 3] == c && k != (x - sx) * 3 + (y - sy)) {
                return false; 
            }
        }
        
        return true; 
    }
}
