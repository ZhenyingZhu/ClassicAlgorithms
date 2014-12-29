package algorithms.bitmanipulate; 

import java.util.*; 

public class SwapEvenAndOddBits {
    /* Function: Swap even and odd bits in an integer. 
     * Solution: Use mask. 
     */ 
    
    public int swapOddEvenBits(int x) {
        return ((x & 0xAAAAAAAA) >>> 1) | ((x & 0x55555555) << 1); 
    }
    
    public static void printBinary(int x) {
        System.out.println(); 
        for (int i = 31; i >= 0; --i) {
            System.out.print(x >>> i & 1); 
        }
        System.out.println(); 
    }
} 
