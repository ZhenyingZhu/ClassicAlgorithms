package algorithms.arrandstring; 

import java.util.*; 

public class GenerateValidParentheses {
    /* Function: Give a number n, generate all valid n parentheses pairs. 
     * Solution: Count left and right to avoid invalid pairs. 
     */ 
    
    public List<String> generateParens(int n) {
        List<String> res = new ArrayList<String>(); 
        if (n <= 0) {
            return res; 
        }
        
        int left = n, right = n; 
        String s = ""; 
        parensHelper(s, left, right, res); 
        return res; 
    }
    
    private void parensHelper(String s, int left, int right, List<String> res) {
        if (right < left) {
            return; // Invalid
        }
        if (left == 0 && right == 0) {
            res.add(s); 
        }
        
        if (left > 0) {
            parensHelper(s + "(", left - 1, right, res); 
        }
        if (right > 0) {
            parensHelper(s + ")", left, right - 1, res); 
        }
    }
    
    public List<String> parensTest(int n) {
        List<String> res = new ArrayList<String>(); 
        int[] arr = new int[2 * n]; 
        parHelper(arr, n, 0, res); 
        return res; 
    }
    
    private void parHelper(int[] arr, int n, int st, List<String> res) {
        if (n == 0) {
            StringBuffer sb = new StringBuffer(); 
            for (int i = 0; i < arr.length; ++i) {
                sb.append(arr[i] == 0 ? "(" : ")"); 
            }
            res.add(sb.toString());
            return; 
        }
        
        for (int i = st; i <= arr.length - n; ++i) {
            arr[i] = 1; 
            parHelper(arr, n - 1, i + 1, res); 
            arr[i] = 0; 
        }
    }  
}
