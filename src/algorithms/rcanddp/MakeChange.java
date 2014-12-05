package algorithms.rcanddp; 

import java.util.*; 

public class MakeChange {
    /* Function: Make change using quarter, dime, five and one cents. 
     * Solution: Notice 1,1,5,1,1,1 is same as 1,1,1,1,1,5. So the method using 
     *     for climb stairs is not approachable. Using memo cache instead. 
     */ 
    
    public int makeChange(int amount) {
        if (amount <= 0) {
            return 0; 
        }
        
        int[] denoms = {25, 10, 5, 1}; 
        int[][] map = new int[amount + 1][denoms.length]; 
        
        int res = changeHelper(amount, denoms, 0, map); 
        /* Map is not fully filled
        for (int i = 0; i < map.length; ++i) {
            for (int j = 0; j < map[0].length; ++j) {
                System.out.print(map[i][j] + " "); 
            }
            System.out.println(); 
        }
        */
        return res; 
    }
    
    private int changeHelper(int amount, int[] denoms, int idx, int[][] map) {
        if (map[amount][idx] > 0) {
            return map[amount][idx]; 
        }
        
        if (amount == 0 || idx == denoms.length - 1) {
            map[amount][idx] = 1; // Not necessary, just try to see the map. 
            return 1; 
        }
        
        int ways = 0; 
        for (int i = 0; i * denoms[idx] <= amount; ++i) {
            ways += changeHelper(amount - denoms[idx] * i, denoms, idx + 1, map); 
        }
        map[amount][idx] = ways; 
        return ways; 
    }
}
