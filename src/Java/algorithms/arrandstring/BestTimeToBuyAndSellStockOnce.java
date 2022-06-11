package algorithms.arrandstring; 

import java.util.*; 

public class BestTimeToBuyAndSellStockOnce {
    /* Function: Give the price of each day of a stock, 
     *     find the best time to buy and sell the stock once. 
     * Solution: Keep the minimum value has seen, use the current 
     *     value to minus it. 
     */ 
    
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0; 
        }
        
        int max = 0, min = Integer.MAX_VALUE; 
        for (int i = 0; i < prices.length; ++i) {
            min = Math.min(min, prices[i]); 
            max = Math.max(max, prices[i] - min); 
        }
        
        return max; 
    }
}