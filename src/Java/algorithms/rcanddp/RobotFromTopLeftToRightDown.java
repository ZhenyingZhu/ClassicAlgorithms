package algorithms.rcanddp; 

import java.util.*; 

public class RobotFromTopLeftToRightDown {
    /*  Function: Find the total ways that let robot goes from top left to (x, y).  
     *  Solution: Using combination. But before interger overflow. 
     */
    
    public int getPaths(int x, int y) {
        if (x <= 0 || y <= 0) {
            return 0; 
        }

        if (x + y >= 13) {
            return getPath(x, y); 
        }
        return combine(x + y, x); 
    }

    private int combine(int n, int c) {
        int sub = 1; 
        int top = 1; 
        for (int i = 1; i <= c; ++i) {
            top *= n--; 
            sub *= i; 
        }

        return top / sub; 
    }

    private int getPath(int x, int y) {
        int[][] matrix = new int[x + 1][y + 1]; 
        for (int i = 0; i <= x; ++i) {
            matrix[i][0] = 1; 
        }
        for (int i = 0; i <= y; ++i) {
            matrix[0][i] = 1; 
        }

        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
        }

        return matrix[x][y]; 
    }
}
