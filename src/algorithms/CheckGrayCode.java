package algorithms; 

import java.util.*; 

public class CheckGrayCode {
    /* Function: Check if two bytes are gray codes. 
     * Solution: XOR and then check if there is only one bit differ. 
    */ 
    public boolean isGrayCode(byte b1, byte b2) {
        int b3 = b1 ^ b2; 
        if (b1 != b2 && (b3 & (b3 - 1)) == 0) {
            return true; 
        }
        return false; 
    }
}
