package algorithms.mathandprob; 

import java.util.*; 

public class PalindromeNumber {
    /* Function: Check if a number is palindrome without using extra space. 
     * Solution: Point to the highest bit and lowest bit and compare. 
     */ 
    
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false; 
        }
        
        int pow = 1; 
        while (x / pow >= 10) { // Won't overflow because MAX Integer start with 2
            pow *= 10; 
        }
        
        while (pow > 1) {
            if ((x / pow) % 10 != x % 10) {
                return false; 
            }
            
            pow /= 100; 
            x /= 10; 
        }

        return true; 
    }
    
    public static void main(String[] args) {
        String s = "PAYPALISHIRING"; 
        boolean ans = new Test().isPalindrome(1234554321); 
        System.out.println(ans); 
    }
}