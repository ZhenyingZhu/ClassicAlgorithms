package algorithms.mathandprob; 

import java.util.*;

public class MultiplyStrings {
    /* Function: Multiple two strings. 
     * Solution: Special case is that 0 * num. Otherwise only the highest bit can be 0. 
    */
     public String multiply(String num1, String num2) {
        if (num1 == null || num2 == null || num1.length() == 0 || num2.length() == 0) {
            return ""; 
        }
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }

        int m = num1.length(), n = num2.length(); 
        int[] res = new int[m + n]; 
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int mul = res[i + j + 1] + (num1.charAt(i) - '0') * (num2.charAt(j) - '0'); 
                res[i + j + 1] = mul % 10; 
                res[i + j] += mul / 10; 
            }
        }
        
        StringBuffer sb = new StringBuffer(); 
        if (res[0] != 0) {
            sb.append(res[0]); 
        }
        for (int i = 1; i < res.length; ++i) {
            sb.append(res[i]); 
        }
        
        return sb.toString(); 
    }
}
