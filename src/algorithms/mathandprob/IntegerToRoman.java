package algorithms.mathandprob; 

import java.util.*; 

public class IntegerToRoman {
    /* Function: Convert the given integer to roman number. 
     * Solution: The complex method is how people thought. 
     *     While the simple way is using the character that 
     *     9 and 4 are special. Using mod oeration can also
     *     function as if. 
     */ 
    
    public String intToRoman(int num) {
        if (num <= 0 || num > 3999) {
            return ""; 
        }
        
        String[] rom = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; 
        int[] val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; 
        
        StringBuffer sb = new StringBuffer(); 
        for (int i = 0; i < val.length; ++i) {
            int cnt = num / val[i]; 
            num = num % val[i]; 
            for (int j = 0; j < cnt; ++j) {
                sb.append(rom[i]); 
            }
        }
        
        return sb.toString(); 
    }
    
    public String intToRomanComplex(int num) {
        if (num <= 0 || num > 3999) {
            return ""; 
        }
        
        StringBuffer sb = new StringBuffer(); 
        String rom = "IVXLCDM"; 
        int offset = 0; 
        while (num > 0) {
            int cur = num % 10; 
            num = num / 10; 
            
            int t = cur % 5; 
            if (t == 4) {
                sb.insert(0, cur > 5 ? rom.charAt(offset + 2) : rom.charAt(offset + 1)); 
                sb.insert(0, rom.charAt(offset)); 
            } else {
                for (int i = 0; i < t; ++i) {
                    sb.insert(0, rom.charAt(offset)); 
                }
                sb.insert(0, cur < 5 ? "" : rom.charAt(offset + 1)); 
            }
            
            offset += 2; 
        }
        
        return sb.toString(); 
    }
}
