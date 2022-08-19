package algorithms.arrandstring; 

import java.util.*; 

public class BestTimeToBuyAndSellStockTwice {
    /* Function: Give the prices history, now make two transaction to get the max profit.  
     * Solution: Find the max profit from head to end, then from end to from, add them together. 
     */ 
    
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0; 
        }
        
        int n = prices.length; 
        int min = Integer.MAX_VALUE; 
        int[] first = new int[n]; 
        for (int i = 0; i < n; ++i) {
            min = Math.min(prices[i], min); 
            first[i] = i == 0 ? 0 : Math.max(first[i - 1], prices[i] - min); 
        }
        
        int max = Integer.MIN_VALUE; 
        int[] second = new int[n]; 
        for (int i = n - 1; i >= 0; --i) {
            max = Math.max(prices[i], max); 
            second[i] = i == n - 1 ? 0 : Math.max(second[i + 1], max - prices[i]); 
        }
        
        int res = 0; 
        for (int i = 0; i < n; ++i) {
            res = Math.max(res, first[i] + second[i]); 
        }
        return res; 
    }
}
