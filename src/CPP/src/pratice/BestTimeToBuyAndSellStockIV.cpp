#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty() || k <= 0)
            return 0;

        int len = prices.size();
        if (k >= len)
            return maxProfit(prices);

        vector<vector<int>> global(k + 1, vector<int>(len, 0));
        vector<vector<int>> local(k + 1, vector<int>(len, 0));
        for (int day = 1; day < len; ++day) {
            for (int trans = 1; trans <= k; ++trans) {
                int diff = prices[day] - prices[day - 1];
                local[trans][day] = max( local[trans][day - 1] + diff, global[trans - 1][day - 1] + max(diff, 0) );

                global[trans][day] = max(global[trans][day - 1], local[trans][day]);
            }
        }
        return global[k].back();
    }

    int maxProfit(vector<int> &prices) {
        int profit = 0;
        for (int i = 1; i < (int)prices.size(); ++i) {
            profit += max(0, prices[i] - prices[i - 1]);
        }
        return profit;
    }
};

int main() {
    Solution sol;

    vector<int> prices = {2,3,4,1,5};
    cout<< sol.maxProfit(2, prices) << endl;

    return 0;
}
