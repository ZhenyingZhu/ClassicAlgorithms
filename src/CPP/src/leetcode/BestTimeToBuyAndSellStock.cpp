/*
 * [Source] https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Dynamic Programming
 */

#include <iostream>

using namespace std;

// [Solution]: Two pass of array. Find the Max of each cell, then minus the value
// [Corner Case]:
class Solution {
};

// [Solution]: Track previous minumum. Use current value to minus minimum
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/BestTimeToBuyAndSellStockOnce.java
 */

// [Solution]: convert it into must large consictive sum
/* Java solution
public class Solution {
    public int maxProfit(int[] prices) {
		if(prices==null || prices.length<=1) return 0;
		int max=0;
		int sum=0;
		diffArray(prices);
		for(int i=0; i<prices.length; i++){
			sum+=prices[i];
			if(sum<0) sum=0;
			if(sum>max) max=sum;
		}
		return max;
    }

	public void diffArray(int[] array){
		for(int i=array.length-1; i>=1; i--){
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
