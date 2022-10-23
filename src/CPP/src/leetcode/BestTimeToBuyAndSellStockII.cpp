/*
 * [Source] https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Greedy
 */

#include <iostream>

using namespace std;

// [Solution]: Keep adding a[i]-a[i-1] if it is larger than 0.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/BestTimeToBuyAndSellStockUnlimit.java
 */

// [Solution]: convert to difference.
/* Java solution
public class Solution {
    public int maxProfit(int[] prices) {
		if(prices.length<=1) return 0;
		convertDiff(prices);
		int[] profit=new int[prices.length];
		int sum=0;
		int max=0;
		for(int i=0; i<prices.length; i++){
			if(prices[i]<0){
				max+=sum;
				sum=0;
			}
			else sum+=prices[i];
		}
		max+=sum;
		return max;
    }
	
	public void convertDiff(int[] array){
		for(int i=array.length-1; i>0; i--){
			array[i]=array[i]-array[i-1];
		}
		array[0]=0;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
