package algorithms.arrandstring; 

import java.util.*; 

public class ZigZagConversion {
    /* Function: ZigZag in the vertical direction, turn string in each n chars, and return the result line by line. 
     * Solution: use mod operation. 
     */ 
    
    public String convert(String s, int nRows) {
        if (s == null || s.length() <= nRows || nRows <= 1) {
            return s; 
        }
        
        StringBuffer[] sbs = new StringBuffer[nRows]; 
        for (int i = 0; i < sbs.length; ++i) {
            sbs[i] = new StringBuffer(); 
        }
        
        int part = nRows + nRows - 2; 
        for (int i = 0; i < s.length(); ++i) {
            if (i % part < nRows) {
                sbs[i % part].append(s.charAt(i)); 
            } else {
                sbs[part - i % part].append(s.charAt(i)); 
            }
        }
        
        StringBuffer res = new StringBuffer(); 
        for (StringBuffer sb : sbs) {
            System.out.println(sb.toString()); 
            res.append(sb); 
        }
        
        return res.toString(); 
    }
}