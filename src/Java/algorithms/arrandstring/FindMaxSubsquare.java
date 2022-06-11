package algorithms.arrandstring; 

import java.util.*; 

public class FindMaxSubsquare {
    /* Function: Find the max subsquare that all boarders are 1. 
     * Solution: Check from the larger one to smaller one. Pre-pocess compute the length of
     *     boarder of right and below of a vertex. 
     */ 
    
    public SubSquare findMaxSquare(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length != matrix.length) {
            return null; 
        }
        
        SubSquare[][] prec = squareHelper(matrix); 
        
        for (int i = matrix.length; i > 0; --i) {
            SubSquare square = checkSize(prec, i); 
            if (square != null) {
                return square; 
            }
        }
        
        return null; 
    }
    
    private SubSquare[][] squareHelper(int[][] matrix) {
        int n = matrix.length; 
        SubSquare[][] res = new SubSquare[n + 1][n + 1]; 
        res[n][n] = new SubSquare(0, 0); 
        for (int i = 0; i < n; ++i) {
            res[n][i] = new SubSquare(0, 0); 
            res[i][n] = new SubSquare(0, 0); 
        }
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == 0) {
                    res[i][j] = new SubSquare(0, 0); 
                } else {
                    res[i][j] = new SubSquare(res[i][j + 1].right + 1, res[i + 1][j].below + 1); 
                }
                res[i][j].setPos(i, j); 
            }
        }
        
        return res; 
    }
    
    private SubSquare checkSize(SubSquare[][] matrix, int size) {
        for (int i = 0; i <= matrix.length - size; ++i) {
            for (int j = 0; j <= matrix.length - size; ++j) {
                if (matrix[i][j].right < size || matrix[i][j].below < size) {
                    continue; 
                }
                
                if (matrix[i + size - 1][j].right >= size && matrix[i][j + size - 1].below >= size) {
                    matrix[i][j].setSize(size); 
                    return matrix[i][j]; 
                }
            }
        }
        
        return null; 
    }
}

class SubSquare {
    int right = 0; // How many consequtive black on the right
    int below = 0; // How many Consequtive black under it. 
    int x, y; 
    int size; 
    public SubSquare(int right, int below) {
        this.right = right; 
        this.below = below; 
    }
    
    public void setPos(int x, int y) {
        this.x = x; 
        this.y = y; 
    }
    
    public void setSize(int size) {
        this.size = size; 
    }
    
    public String toString() {
        return "Coordinate: (" + x + ", " + y + ") Size: " + size + ". "; 
    }
}