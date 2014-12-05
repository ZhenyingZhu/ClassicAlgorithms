package algorithms.arrandstring; 

import java.util.*; 

public class WordSearch {
    /* Function: Give a board, find if a word exists in the adjacent cells. 
     * Solution: Mark the current cell to avoid repeat search. 
     */ 
    
    public boolean exist(char[][] board, String word) {
        if (board == null || board.length == 0 || board[0].length == 0) {
            return false; 
        }
        if (word == null || word.length() == 0) {
            return true; 
        }
        
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (search(board, i, j, word, 0)) {
                    return true; 
                }
            }
        }
        
        return false; 
    }
    
    private boolean search(char[][] board, int x, int y, String word, int idx) {
        if (x < 0 || x >= board.length || y < 0 || y >= board[0].length) {
            return false; 
        }
        if (board[x][y] != word.charAt(idx)) {
            return false; 
        }
        if (idx == word.length() - 1) {
            return true; 
        }
        
        board[x][y] = '*'; // Won't repeat this char
        boolean res = search(board, x + 1, y, word, idx + 1) || 
                search(board, x - 1, y, word, idx + 1) || 
                search(board, x, y + 1, word, idx + 1) || 
                search(board, x, y - 1, word, idx + 1); 
        board[x][y] = word.charAt(idx); 
        return res; 
    }
}