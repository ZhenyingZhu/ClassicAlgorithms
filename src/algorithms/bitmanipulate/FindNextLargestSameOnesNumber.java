package algorithms.bitmanipulate; 

import java.util.*; 

public class FindNextLargestSameOnesNumber {
    /* Function: Find the next larger number that has the same one in binary presentation. 
     * Solution: Shift the left most one right, and them move all ones after it to the right. 
     */ 
    
    // Test Case
    public static void main(String[] args) {
        int n = 7; 
        System.out.println(new Test().getNext(n)); 
    }
    
    public int getNext(int num) {
        if (num <= 0) {
            return 0; 
        }
        
        int pt = 0; 
        while (pt < 32 && ((num >>> pt) & 1) == 0) {
            pt++; 
        }
        
        int ones = 0; 
        while (pt < 32 && ((num >>> pt) & 1) == 1) {
            pt++; 
            ones++; 
        } 
        
        if (pt == 32) {
            return num; // The largest one. 
        }
        
        num |= (1 << pt);  
        num &= ~((1 << pt) - 1);  
        
        num |= (1 << (ones - 1)) - 1; 
        
        return num; 
    } 
} 
