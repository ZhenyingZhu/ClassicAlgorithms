package algorithms.mathandprob; 

import java.util.*; 

public class CheckGrayCode {
    /* Function: Check if two bytes are gray codes. 
     * Solution: XOR and then check if there is only one bit differ. 
     *     Cannot use b3 & (b3 - 1) because -128 = 10000000
    */ 
    public boolean isGrayCode(byte b1, byte b2) {
        int b3 = b1 ^ b2; 
        int cnt = 0; 
        for (int i = 7; i >= 0; --i) {
            cnt += (b3 >>> i) & 0x01; 
        }
        
        return cnt == 1; 
    }
}
