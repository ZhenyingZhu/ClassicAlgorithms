package algorithms.mathandprob; 

import java.util.*; 

public class CountSquaresInARange {
    /* Function: Count the square numbers in a range. 
     * Solution: 1. left <= 0; 2. Overflow; 3. Boundary is a square. 
     *     Cannot use st<left/st because e.g, when left is 12~19, st=4,
     *     so cannot distinct if 16 is included. 
     *     Overflow happens when boundary>46340^2. 46341^2<0 so always <boundary. 
     *     st*st<left, means st stop when st*st>=left, so st always include st^2. 
     *     while ed*ed<right means ed doesn't include ed^2, need another judgment. 
     *     left = 2 3 4 ... right = 4 5 6 7 8 
     *       st =     2        ed =         3
     */ 
    public int countSquares(int left, int right) {
        if (left > right || right < 0) {
            return 0; 
        }
        
        int st = 0; 
        while (st * st >= 0 && st * st < left) {
            ++st; 
        }
        int ed = st; 
        while (ed * ed >= 0 && ed * ed <= right) {
            ++ed; 
        }

        return ed - st; 
    }
}
