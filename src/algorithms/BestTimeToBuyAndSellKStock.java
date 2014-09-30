package algorithms; 

import java.util.*; 

public class BestTimeToBuyAndSellKStock {
    /* Function: Give the prices of days, make k transactions, find the max profit. 
     * Solution: DP. Use f[i][j] = f[i][j-1] to get the max value before j days. 
    */
    public int maxKProfit(int[] prices, int k) {
        if (k <= 0 || prices == null || prices.length == 0) {
            return 0; 
        }
        
        int n = prices.length; 
        int[][] f = new int[k + 1][n + 1]; 
        for (int times = 0; times < k; ++times) {
            for (int ed = 0; ed < n; ++ed) {
                f[times + 1][ed + 1] = f[times + 1][ed]; 
                for (int st = 0; st <= ed; ++st) {
                    f[times + 1][ed + 1] = Math.max(f[times + 1][ed + 1], f[times][st] + prices[ed] - prices[st]); 
                }
            }
        }
        
        return f[k][n]; 
    }
}
