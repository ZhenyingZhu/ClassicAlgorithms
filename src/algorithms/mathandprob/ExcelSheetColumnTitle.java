package algorithms.mathandprob; 

import java.util.*; 

public class ExcelSheetColumnTitle {
    /* Function: Giving a base 1 integer, return the correspond string that used as excel sheet column. 
     * Solution: Since it is not like 0~9 because 10~19 add 1 at first rather than 0, so need n - 1. 
     */ 
    
    /* Test Case
    public static void main(String[] args) {
        String v1 = "1", v2 = "0"; 
        System.out.println(new Test().compareVersion(v1, v2)); 
    }
    */
    
    public String convertToTitle(int n) {
        if (n <= 0) {
            return ""; 
        }

        String alp = "ZABCDEFGHIJKLMNOPQRSTUVWXY"; 
        
        StringBuffer sb = new StringBuffer(); 
        while (n > 0) {
            sb.insert(0, alp.charAt(n % 26)); 
            n = (n - 1) / 26; 
        }
        
        return sb.toString(); 
    }
} 
