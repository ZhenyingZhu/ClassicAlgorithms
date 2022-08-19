package algorithms.mathandprob; 

import java.util.*; 

public class GeneratePrime {
    /* Function: Generate primes in a range. 
     * Solution: Use and boolean array to record if it is not prime, 
     *     and delete all multiples of prime. 
     */ 
    
    public List<Integer> generatePrime(int n) {
        List<Integer> res = new ArrayList<Integer>(); 
        if (n <= 1) {
            return res; // let 0, 1 not be prime. 
        }
        
        boolean[] arr = new boolean[n + 1]; 
        int pt = 2; 
        while (pt * pt <= n) {
            for (int i = pt * pt; i <= n; i += pt) {
                arr[i] = true; 
            }
            
            do {
                ++pt; 
            } while (pt <= n && arr[pt]); 
        }
        
        for (int i = 2; i <= n; ++i) {
            if (!arr[i]) {
                res.add(i); 
            }
        }
        
        return res; 
    }
}
