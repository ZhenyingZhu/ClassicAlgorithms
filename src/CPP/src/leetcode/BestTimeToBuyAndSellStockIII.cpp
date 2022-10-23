/*
 * [Source] https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 * [Difficulty]: Hard
 * [Tag]: Array
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// [Solution]: Compute max profit from 0 to i, and compute max profit from i to end. DP.
// [Corner Case]: Need overlap because it could be one transaction
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0)
            return 0;

        vector<int> maxProfitFromStToI(len);
        int preMin = INT_MAX;
        for (int i = 0; i < len; ++i) {
            preMin = min(preMin, prices[i]);
            maxProfitFromStToI[i] = max(prices[i] - preMin, i == 0 ? 0 : maxProfitFromStToI[i - 1]);
        }

        vector<int> maxProfitFromIToEd(len);
        int nxtMax = INT_MIN;
        for (int i = len - 1; i >= 0; --i) {
            nxtMax = max(nxtMax, prices[i]);
            maxProfitFromIToEd[i] = max(nxtMax - prices[i], i == len - 1 ? 0 : maxProfitFromIToEd[i + 1]);
        }

        int maxProfit = 0;
        for (int i = 0; i < len; ++i) {
            maxProfit = max(maxProfitFromStToI[i] + maxProfitFromIToEd[i], maxProfit);
        }

        return maxProfit;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/BestTimeToBuyAndSellStockTwice.java
 */

/* Java solution
public class Solution {
    public int maxProfit(int[] prices) {
		if(prices.length<=1) return 0;
		convertDiff(prices);
		int[] firstPart=new int[prices.length];
		int[] secondPart=new int[prices.length];
		int sum=0;
		int max=0;
		for(int i=0; i<prices.length; i++){
			sum+=prices[i];
			if(sum<0) sum=0;
			if(sum>max) max=sum;
			firstPart[i]=max;
		}
		sum=0;
		max=0;
		for(int i=prices.length-1; i>=0; i--){
			sum+=prices[i];
			if(sum<0) sum=0;
			if(sum>max) max=sum;
			secondPart[i]=max;
		}
		int mProfit=0;
		for(int i=0; i<prices.length-1; i++){
			int profit=firstPart[i]+secondPart[i+1];
			if(profit>mProfit) mProfit=profit;
		}
		return mProfit;
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

    //vector<int> prices = {0,4,1,5};
    //vector<int> prices = {0,4};
    //vector<int> prices = {5,4,3,2};
    vector<int> prices = {1,2,3};
    cout << sol.maxProfit(prices) << endl;

    return 0;
}
