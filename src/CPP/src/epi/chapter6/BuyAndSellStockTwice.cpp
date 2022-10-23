#include "BuyAndSellStockTwice.hpp"

#include <vector>
#include <iostream>
#include <algorithm>
#include "../../MyUtils.h"

using std::vector;
using std::cout;
using std::endl;
using std::max;
using std::min;
using myutils::vec_to_string;

namespace epi {
namespace chapter6 {
double BuyAndSellStockTwice::buyAndSellStockOnce(vector<double>::const_iterator begin, vector<double>::const_iterator end) {
    if (begin == end)
        return 0.0;

    double max = 0.0, min = *begin;
    for (vector<double>::const_iterator iter = begin; iter <= end; ++iter) {
        if (*iter < min)
            min = *iter;

        if (*iter - min > max)
            max = *iter - min;
    }

    return max;
}

double BuyAndSellStockTwice::buyAndSellStockTwiceBruteForce(const vector<double> &prices) {
    if (prices.empty())
        return 0.0;

    double maxProfit = 0.0;
    for (vector<double>::const_iterator iter = prices.begin(); iter != prices.end(); ++iter) {
        // Sell and buy at the same day is identical to buy and sell once
        double fMax = buyAndSellStockOnce(prices.begin(), iter);
        double bMax = buyAndSellStockOnce(iter, prices.end() - 1);
        maxProfit = max(maxProfit, fMax + bMax);
    }

    return maxProfit;
}

double BuyAndSellStockTwice::buyAndSellStockTwice(const vector<double> &prices) {
    if (prices.empty())
        return 0.0;

    vector<double> frontwardMax(prices.size(), 0.0);
    vector<double> backwardMax(prices.size(), 0.0);

    double frontMin = *prices.begin(), frontwardMaxSeen = 0.0;
    for (size_t i = 0; i != prices.size(); ++i) {
        frontMin = min(frontMin, prices[i]);
        frontwardMaxSeen = max(prices[i] - frontMin, frontwardMaxSeen);
        frontwardMax[i] = frontwardMaxSeen;
    }

    double backMax = *(prices.end() - 1), backwardMaxSeen = 0.0;
    for (int j = prices.size() - 1; j >= 0; --j) {
        backMax = max(backMax, prices[j]);
        backwardMaxSeen = max(backwardMaxSeen, backMax - prices[j]);
        backwardMax[j] = backwardMaxSeen;
    }

    double maxProfit = 0.0;
    for (size_t k = 0; k != prices.size(); ++k) {
        maxProfit = max(maxProfit, frontwardMax[k] + backwardMax[k]);
    }

    return maxProfit;
}

bool BuyAndSellStockTwice::test() {
    vector<double> prices = {12,11,13,9,12,8,14,13,15};

    if (buyAndSellStockTwiceBruteForce(prices) - buyAndSellStockTwice(prices) > 0.001) {
        cout << "Prices: " << vec_to_string(prices) << endl;
        cout << "Max profit should be: " << buyAndSellStockTwiceBruteForce(prices) << endl;
        cout << "Result is : " << buyAndSellStockTwice(prices) << endl;

        return false;
    }

    return true;
}

} // chapter6
} // epi
