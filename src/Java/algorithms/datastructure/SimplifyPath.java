package algorithms.datastructure; 

import java.util.*; 

public class SimplifyPath {
    /* Function: Given a Unix absolute path with /..//, return the simple one. 
     * Solution: Split by '/' and push to stack. If . or empty, continue; If 
     *     .., pop. If stack is empty, return /. 
     */ 
    
    public String simplifyPath(String path) {
        if (path == null || path.length() == 0) {
            return ""; 
        }
        
        String[] paths = path.split("/"); 
        Stack<String> stack = new Stack<String>(); 
        for (String cur : paths) {
            if (cur.equals(".") || cur.length() == 0) {
                continue; 
            }
            
            if (cur.equals("..")) {
                if (!stack.empty()) {
                    stack.pop(); 
                }
            } else {
                stack.push(cur); 
            }
        }
        
        StringBuffer sb = new StringBuffer(); 
        while (!stack.empty()) {
            sb.insert(0, "/" + stack.pop()); 
        }
        
        if (sb.length() == 0) {
            return "/"; 
        }
        return sb.toString(); 
    }
}
