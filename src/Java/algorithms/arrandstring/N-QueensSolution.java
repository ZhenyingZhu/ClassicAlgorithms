package algorithms.arrandstring; 

import java.util.*; 

public class N-QueensSolution {
    /* Function: Place n queens on a board that each one wont affact others. 
     * Solution: Use an array to record the previous configuration. DFS for 
     *     the valid solution. 
     */ 
    
    public List<String[]> solveNQueens(int n) {
        List<String[]> res = new ArrayList<String[]>(); 
        if (n <= 0) {
            return res; 
        }
        
        int[] conf = new int[n]; 
        queenHelper(n, conf, 0, res); 
        return res; 
    }
    
    private void queenHelper(int n, int[] conf, int idx, List<String[]> res) {
        if (idx == n) {
            res.add(generateRes(n, conf)); 
            return; 
        }
        
        boolean[] invalid = new boolean[n]; 
        for (int j = 0; j < idx; ++j) {
            int pos = conf[j]; 
            invalid[pos] = true; 
            if (pos + j - idx >= 0) {
                invalid[pos + j - idx] = true; 
            }
            if (pos - j + idx < n) {
                invalid[pos - j + idx] = true; 
            }
        }

        for (int i = 0; i < n; ++i) {
            if (invalid[i]) {
                continue; 
            }
            
            conf[idx] = i; 
            queenHelper(n, conf, idx + 1, res); 
        }
    }
    
    private String[] generateRes(int n, int[] conf) {
        String[] res = new String[n]; 
        for (int i = 0; i < n; ++i) {
            StringBuffer sb = new StringBuffer(); 
            for (int j = 0; j < n; ++j) {
                if (j == conf[i]) {
                    sb.append("Q"); 
                } else {
                    sb.append("."); 
                }
            }
            
            res[i] = sb.toString(); 
        }
        
        return res; 
    }
}
