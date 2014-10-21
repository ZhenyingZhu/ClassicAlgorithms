package algorithms.bitmanipulate; 

import java.util.*; 

public class AddTwoNumberBit {
    /* Function: Don't use + to add two numbers. 
     * Solution: bit=a^b^c, c=ab+bc+ac. 
     */ 
    
    public int bitAdd(int op1, int op2) {
        if (op1 == 0) {
            return op2; 
        }
        if (op2 == 0) {
            return op1; 
        }
        
        int res = 0, c = 0; 
        for (int i = 0; i < 32; ++i) {
            int a = (op1 >>> i) & 1; 
            int b = (op2 >>> i) & 1; 
            res |= (a ^ b ^ c) << i; 
            c = (a & b) | (a & c) | (b & c); 
        }
        
        return res; 
    }
}
