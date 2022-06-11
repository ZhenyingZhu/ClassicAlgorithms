package algorithms.arrandstring; 

import java.util.*; 

public class FillAnAreaOnPaint {
    /* Function: Give a point and a color, fill paint all this area with same color. 
     * Solution: DFS. Note 1. pixel presentation has x as length while y as height; 
     *     2. If this point is already the given color, return at once, otherwise 
     *     will dead cycle. 
     */ 
    
    public void paintFill(int[][] board, int x, int y, int color) {
        if (board == null || board.length == 0 || board[0].length == 0 
            || x < 0 || x >= board[0].length || y < 0 || y >= board.length 
            || board[y][x] == color) { // Avoid cycle. 
            return; 
        }
        
        fillHelper(board, x, y, board[y][x], color); 
    }
    
    private void fillHelper(int[][] board, int x, int y, int ori, int clr) {
        if (x < 0 || x >= board[0].length || y < 0 || y >= board.length
            || board[y][x] != ori) {
            return; 
        }
        
        board[y][x] = clr; 
        fillHelper(board, x - 1, y, ori, clr); 
        fillHelper(board, x + 1, y, ori, clr); 
        fillHelper(board, x, y - 1, ori, clr); 
        fillHelper(board, x, y + 1, ori, clr); 
    }
}
