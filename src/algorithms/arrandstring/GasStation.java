package algorithms.arrandstring; 

import java.util.*; 

public class GasStation {
    /* Function: Given an array shows the gas each station contains, another array cost[i] shows 
     *     that from i station to i + 1 need how much gas. Find the start point that can complete
     *     the circuit. 
     * Solution: left+gas[i]-cost[i] means when it reach i station, how much gas it has. So if it 
     *     is nagetive, this station cannot be the starter. 
     */ 
    
    public int canCompleteCircuit(int[] gas, int[] cost) {
        if (gas == null || gas.length == 0 || cost == null || cost.length != gas.length) {
            return -1;
        }
        
        int val = 0, sum = 0; 
        int res = -1; 
        for (int i = 0; i < gas.length; ++i) {
            val += gas[i] - cost[i]; 
            sum += gas[i] - cost[i]; 
            if (sum < 0) {
                sum = 0; 
                res = i; 
            }
        }
        
        if (val < 0) {
            return -1; 
        }
        
        return res + 1; 
    }
}
