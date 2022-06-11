package algorithms.arrandstring; 

import java.util.*; 

public class MasterMind {
    /* Function: Guess 4 colors and find the hit and pseudo hit to the solution. 
     * Solution: A hit cannot be count as pseudo hit. So don't count it into the 
     *     frequency arr. 
     */ 
    
    public Result estimate(String sol, String guess) {
        if (sol == null || guess == null || sol.length() != guess.length()) {
            return null; 
        }
        
        int hit = 0, pseudo = 0; 
        int[] arr = new int[4]; 
        for (char c : sol.toCharArray()) {
            if (code(c) == -1) {
                return null; 
            }
            
            ++arr[code(c)]; // If hit, don't add here, then the next loop can ommit. 
        }
        
        for (int i = 0; i < sol.length(); ++i) {
            if (sol.charAt(i) == guess.charAt(i)) {
                ++hit; 
            }
        }
        
        for (int i = 0; i < guess.length(); ++i) {
            int idx = code(guess.charAt(i)); 
            if (arr[idx] > 0) {
                ++pseudo; 
                --arr[idx]; 
            }
        }
        
        return new Result(hit, pseudo - hit); 
    }
    
    private int code(char c) {
        switch (c) {
            case 'B': return 0; 
            case 'G': return 1; 
            case 'R': return 2; 
            case 'Y': return 3; 
            default: return -1; 
        }
    }
}

class Result {
    public int hit, pseudo; 
    public Result(int hit, int pseudo) {
        this.hit = hit; 
        this.pseudo = pseudo; 
    }
    
    public String toString() {
        return "hit: " + hit + ", pseudo-hit: " + pseudo; 
    }
}

