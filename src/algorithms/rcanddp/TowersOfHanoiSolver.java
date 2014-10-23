package algorithms.rcanddp; 

import java.util.*; 

public class TowersOfHanoiSolver {
    /* Function: Print the solution of hanoi tower. 
     * Solution: Use recursive. 
     */ 
    
    public List<Move> moveDisks(int n) {
        List<Move> res = new ArrayList<Move>(); 
        if (n <= 0) {
            return res; 
        }
        
        moveHelper(n, 1, 3, res); 
        return res; 
    }
    
    private void moveHelper(int n, int st, int ed, List<Move> res) {
        if (n == 0) {
            return; 
        }
        
        int md = 6 - st - ed; // 1+2+3
        moveHelper(n - 1, st, md, res); 
        res.add(new Move(st, ed)); 
        moveHelper(n - 1, md, ed, res); 
    }
    
    private class Move {
        int from, to; 
        public Move(int st, int ed) {
            from = st; 
            to = ed; 
        }
        
        public String toString() {
            return from + "->" + to; 
        }
    }
}
