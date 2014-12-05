package algorithms.rcanddp; 

import java.util.*; 

public class RestoreIPAddresses {
    /* Function: Give a string, parse it so that it can be an IP address. 
     * Solution: IP address is combined by 4 numbers range in 0 to 255. 
     *     If a number is 00 or 01, it is also wrong. 
     */ 
    
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<String>(); 
        if (s == null || s.length() < 4 || s.length() > 12) {
            return res; 
        }
        
        ipHelper(s, 1, "", res); 
        return res; 
    }
    
    private void ipHelper(String s, int idx, String prev, List<String> res) {
        if (s.length() == 0) {
            return; 
        }
        
        if (idx == 4) {
            if (validIP(s)) {
                res.add(prev + s); 
            }
            return; 
        }
        
        for (int i = 0; i < 3 && i < s.length(); ++i) {
            String cur = s.substring(0, i + 1); 
            if (validIP(cur)) {
                ipHelper(s.substring(i + 1), idx + 1, prev + cur + ".", res); 
            }
        }
    }
    
    private boolean validIP(String s) {
        if (s.charAt(0) == '0' && s.length() > 1 || s.length() > 3) {
            return false; 
        }
        
        int sum = 0; 
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) < '0' && s.charAt(i) > '9') {
                return false; 
            }
            
            sum = sum * 10 + s.charAt(i) - '0'; 
        }
        
        return sum < 256; 
    }
}
