package algorithms.mathandprob; 

import java.util.*; 

public class Pow {
    /* Function: Compute x^n. 
     * Solution: Notice -n is 1/result. 
     */ 
    
    public double pow(double x, int n) {
        if (n == Integer.MIN_VALUE) {
            return 0.0; // Cannot use -n to make it positive, so n%2 is -1 at first, then the result is 1. 
        }
        
        if (n < 0) {
            return 1 / powHelper(x, -n); 
        } else {
            return powHelper(x, n); 
        }
    }
    
    private double powHelper(double x, int n) {
        if (n == 0) {
            return 1.0; 
        }
        
        double y = powHelper(x, n / 2); 
        System.out.println(n % 2); 
        if (n % 2 == 1) {
            return y * y * x; 
        } else {
            return y * y; 
        }
    }
}