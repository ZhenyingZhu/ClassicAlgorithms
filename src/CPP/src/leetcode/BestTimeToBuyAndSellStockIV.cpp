/*
 * [Source] https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// [Corner Case]:
class Solution {
public:
// [Solution]: m[k][ed] means max profit with k trans end before day ed. m[k][ed] = max(m[k-1][st] + p[ed]-p[st]) or m[k][ed-1].
    int maxProfitDPStraightForward(int k, vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        if ((int)prices.size() <= k)
            return maxProfitBetween(prices);

        vector<vector<int>> kTransAtEd(k + 1, vector<int>(prices.size(), 0));
        for (int time = 1; time <= k; ++time) {
            for (size_t ed = 1; ed < prices.size(); ++ed) {
                kTransAtEd[time][ed] = kTransAtEd[time][ed - 1]; // buy and sell at ed
                for (size_t st = 0; st < ed; ++st) {
                    int diff = prices[ed] - prices[st];
                    if (diff > 0) {
                        kTransAtEd[time][ed] = max(kTransAtEd[time][ed], kTransAtEd[time - 1][st] + diff);
                    }
                }
            }
        }
        return kTransAtEd[k][prices.size() - 1];
    }

// [Solution]: a very cozy code style. Use reverse access array to use result from previous compute. See next solution for explaination
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        if ((int)prices.size() <= k)
            return maxProfitBetween(prices);

        vector<int> global(k + 1, 0), local(k + 1, 0);
        for (int i = 0; i < (int)prices.size() - 1; ++i) {
            int diff = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; --j) { // Do it in reverse order to use the previous result
                local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
                global[j] = max(global[j], local[j]);
            }
        }
        return global[k];
    }

// [Solution]: local[i][k] is max profit for k trans end at day i. global[i][k] is k trans before day i. local[i][k] = the max of 1. local[i-1][k]+p[i]-p[i-1] means the kth trans end at day i, 2. global[i-1][k-1]+p[i]-p[i-1] means kth trans end at day i and previous trans doesn't need to continount, 3. global[i-1][k-1] means the kth trans buy in and sell out at day i
    int maxProfitUnderstandAble(int k, vector<int>& prices) {
        vector<vector<int>> global(prices.size(), vector<int>(k + 1, 0)); // in first i days, make j trans
        vector<vector<int>> local(prices.size(), vector<int>(k + 1)); // in first i days, make j trans and last trans end at day i
        for (int i = 1; i < (int)prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
cout << "i: " << i <<" diff: " << diff << endl;
            for (int j = 1; j <= k; ++j) {
                local[i][j] = local[i - 1][j] + diff; // not a trans, but the previous trans with addition day i
                int what = global[i - 1][j - 1] + max(diff, 0); // j-1 trans before day i-1, and now either make a trans from day i-1 to day i or day i to day i
                if (what > local[i][j]) {
cout << "j: " << j << ":" << local[i][j] << " < " << what << endl;
                    local[i][j] = what;
                }
                global[i][j] = max(global[i - 1][j], local[i][j]);
            }
for (int j = 0; j <= k; ++j)
    cout << local[i][j] << " ";
cout << endl;
for (int j = 0; j <= k; ++j)
    cout << global[i][j] << " ";
cout << endl;
        }
        return global[prices.size() - 1][k];
    }

private:
    int maxProfitBetween(vector<int>& prices) {
        int maxProfit = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            maxProfit += diff > 0 ? diff : 0;
        }
        return maxProfit;
    }
};


int main() {
    Solution sol;

    //vector<int> prices = {1, 0, 1, 0, 2, 0, 3};
    vector<int> prices = {3,3,5,0,0,3,1,4};
    //cout << sol.maxProfit(2, prices) << endl;
    cout << sol.maxProfitUnderstandAble(2, prices) << endl;

    return 0;
}
