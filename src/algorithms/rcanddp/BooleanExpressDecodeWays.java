package algorithms.rcanddp; 

import java.util.*; 

public class BooleanExpressDecodeWays {
    /* Function: Given a boolean express without parentheses. Find how many ways to decode it to a given boolean. 
     * Solution: Giving parentheses can be DP as f[i][j]=max(f[i][k]+f[k+1][j]). Memo cache the ways that a string 
     *     can decode to true and false. Each time need to judge if the method is valid. 
     */ 
    
    public int expressWays(String s, boolean bol) {
        if (s == null || s.length() % 2 == 0) {
            return 0; 
        }
        
        int num = s.length() / 2 + 1; 
        Map<String, int[]> map = new HashMap<String, int[]>(); 
        int target = bol ? 1 : 0; 
        return expressHelper(s, target, map); 
    }
    
    private int expressHelper(String s, int target, Map<String, int[]> map) {
        if (s.length() == 0) {
            return 0; 
        }
        if (s.length() == 1) {
            return s.charAt(0) - '0' == target ? 1 : 0; 
        }
        if (map.containsKey(s) && map.get(s)[target] != -1) {
            return map.get(s)[target]; 
        }
        
        if (!map.containsKey(s)) {
            int[] res = {-1, -1}; 
            map.put(s, res); 
        } 
        int[] res = map.get(s); 
        
        int max = 0; 
        for (int i = 0; i < s.length() - 2; i += 2) { // axbxc==(axb)xc
            max = Math.max(max, parse(s, i + 1, target, map)); 
        }
        
        res[target] = max; 
        map.put(s, res); 
        return max; 
    }
    
    private int parse(String s, int op, int target, Map<String, int[]> map) {
        int leftSame = expressHelper(s.substring(0, op), target, map); 
        int rightSame = expressHelper(s.substring(op + 1, s.length()), target, map); 
        int leftDiff = expressHelper(s.substring(0, op), 1 - target, map); 
        int rightDiff = expressHelper(s.substring(op + 1, s.length()), 1 - target, map); 
        switch (s.charAt(op)) {
            case '&' : return leftSame * rightSame; 
            case '|' : return leftSame * rightSame + leftSame * rightDiff + leftDiff * rightSame; 
            case '^' : return target == 1 ? leftSame * rightDiff + leftDiff * rightSame : leftSame * rightSame + leftDiff * rightDiff; 
            default : return 0; 
        }
    }
    
    /* Test Case
    public static void main(String[] args) {
        String s = "1^0|0|1"; 
        int ans = new Test().expressWays(s, true); 
        System.out.print(ans + " "); 
        System.out.println(); 
    }
    */
}