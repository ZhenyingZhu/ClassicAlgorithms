package algorithms.treeandgraph; 

import java.util.*; 

public class SurroundedRegions {
    /* Function: Fill cells that surrounded by 'X'. 
     * Solution: BFS the 'O' cells on the boards. Mark 'O' as '+' that can 
     *     reach by the boards 'O'. Then change all 'O' into 'X' and '+' into
     *     'O'. DFS using too many stacks. This BFS check after enqueue. 
     */

    public void solve(char[][] board) {
        if (board == null || board.length == 0 || board[0].length == 0) {
            return; 
        }
        
        searchRow(board, 0); 
        searchRow(board, board.length - 1); 
        searchCol(board, 0); 
        searchCol(board, board[0].length - 1); 
        
        refill(board); 
    }
    
    private void searchRow(char[][] board, int rowIdx) {
        for (int i = 0; i < board[0].length; ++i) {
            if (board[rowIdx][i] == 'O') {
                bfs(board, rowIdx, i); 
            }
        }
    }
    
    private void searchCol(char[][] board, int colIdx) {
        for (int i = 0; i < board.length; ++i) {
            if (board[i][colIdx] == 'O') {
                bfs(board, i, colIdx); 
            }
        }
    }
    
    private void bfs(char[][] board, int row, int col) {
        int n = board[0].length; 
        
        Queue<Integer> queue = new LinkedList<Integer>(); 
        queue.offer(encode(row, col, n)); 
        while (!queue.isEmpty()) {
            int[] corrdinate = decode(queue.poll(), n); 
            int x = corrdinate[0], y = corrdinate[1]; 
            if (board[x][y] == 'O') {
                board[x][y] = '+'; 
                if (x > 0) {
                    queue.offer(encode(x - 1, y, n)); 
                }
                if (x < board.length - 1) {
                    queue.offer(encode(x + 1, y, n)); 
                }
                if (y > 0) {
                    queue.offer(encode(x, y - 1, n)); 
                }
                if (y < board[0].length - 1) {
                    queue.offer(encode(x, y + 1, n)); 
                }
            }
        }
    }
    
    private int encode(int x, int y, int width) {
        return x * width + y; 
    }
    
    private int[] decode(int code, int width) {
        int x = code / width; 
        int y = code % width; 
        int[] res = {x, y}; 
        return res; 
    }
    
    private void refill(char[][] board) {
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] == '+') {
                    board[i][j] = 'O'; 
                } else {
                    board[i][j] = 'X'; 
                }
            }
        }
    }
}
