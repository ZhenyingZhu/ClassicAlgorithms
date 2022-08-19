package algorithms.arrandstring; 

import java.util.*; 

public class EnglishPhaseDescribeInteger {
    /* Function: Convert integer to english phase. 
     * Solution: Note that 0, 1~19, 20~99, >100 are different. If empty, should not print. If thousand, add comma. 
     */ 
    
    public String numToString(int num) {
        if (num == 0) {
            return "zero"; 
        }
        
        StringBuffer res = new StringBuffer(); 
        if (num < 0) {
            res.append("negative "); 
            num = -num; 
        }
        
        String[] digits = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", 
            "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "ninteen"}; 
        String[] tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty"}; 
        
        String[] thousands = {"", "thousand", "million", "billion"}; 
        int k = 1000 * 1000 * 1000; 
        for (int i = 3; i >= 0; --i) {
            String cur = convert(num / k, digits, tens); 
            num %= k; 
            k /= 1000; 
            if (cur.equals("")) {
                continue; 
            }
            
            if (res.length() > 0) {
                res.append(", "); 
            }
            res.append(cur + " " + thousands[i]); 
        }
        
        return res.toString(); 
    }
    
    private String convert(int num, String[] digits, String[] tens) {
        StringBuffer sb = new StringBuffer(); 
        if (num == 0) {
            return sb.toString(); 
        }
        
        int hun = num / 100; 
        num %= 100; 
        if (hun != 0) {
            sb.append(digits[hun] + " hundred"); 
            if (num == 0) {
                return sb.toString(); 
            }
            sb.append(" "); 
        }
        
        if (num < 20) {
            sb.append(digits[num]); 
            return sb.toString(); 
        }
        
        int ten = num / 10; 
        num %= 10; 
        if (ten != 0) {
            sb.append(tens[ten]); 
            if (num == 0) {
                return sb.toString(); 
            }
            sb.append(" "); 
        }
        
        sb.append(digits[num]); 
        return sb.toString(); 
    }
    
    /* Test case
    public static void main(String[] args) {
        int val = 0; 
        int val = 1; 
        int val = 10; 
        int val = 12; 
        int val = 20; 
        int val = 23; 
        int val = 100; 
        int val = 104; 
        int val = 212; 
        int val = 230; 
        int val = 245; 
        int val = 1000; 
        int val = 1002; 
        int val = 1012; 
        int val = 1050; 
        int val = 1065; 
        int val = 110012; 
        int val = 1000000; 
        int val = 1000103; 
        int val = 1000000012; 
        int val = 1000001012; 
        System.out.println(new Test().numToString(val)); 
    }
    */
}
