//package algorithms.mathandprob; 
package algorithms; 

import java.util.*; 

public class BestTimeToBuyAndSellStockUnlimit {
    /* Function: Give the stock prices of each day. Now can do several 
     *     transactions, find out the max profit. 
     * Solution: If the next value is bigger than previous one, add. 
     */ 

    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0; 
        }
        
        int sum = 0; 
        for (int i = 1; i < prices.length; ++i) {
            int diff = prices[i] - prices[i - 1]; 
            sum += diff > 0 ? diff : 0; 
        }
        
        return sum; 
    }
     
    public static void main(String[] args) {
        System.out.println("Hello World");
    }
} 