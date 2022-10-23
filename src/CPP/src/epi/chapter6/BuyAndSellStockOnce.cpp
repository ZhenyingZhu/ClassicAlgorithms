#include "BuyAndSellStockOnce.hpp"

#include <vector>
#include <iostream>

#include "../../MyUtils.h"

using std::vector;
using std::cout;
using std::endl;
using myutils::vec_to_string;

namespace epi {
namespace chapter6 {

double BuyAndSellStockOnce::buyAndSellStockOnceBruteForce(const vector<double> & prices) {
    double max = 0.0;

    for (vector<double>::const_iterator i = prices.begin(); i != prices.end() - 1; ++i) {
        for (vector<double>::const_iterator j = i + 1; j != prices.end(); ++j) {
            if (*j - *i > max)
                max = *j - *i;
        }
    }

    return max;
}

double BuyAndSellStockOnce::buyAndSellStockOnce(const vector<double> & prices) {
    if (prices.empty())
        return 0.0;

    double max = 0.0, min = *(prices.begin()); // min could be less than 0

    for (vector<double>::const_iterator iter = prices.begin(); iter != prices.end(); ++iter) {
        if (*iter < min)
            min = *iter;

        if (*iter - min > max)
            max = *iter - min;
    }

    return max;
}

bool BuyAndSellStockOnce::test() {
    vector<double> prices = {310,315,275,295,260,270,290,230,255,250};

    if ( buyAndSellStockOnceBruteForce(prices) - buyAndSellStockOnce(prices) > 0.001 ) {
        cout << "Prices: " << vec_to_string(prices) << endl;
        cout << "Profit should be: " << buyAndSellStockOnceBruteForce(prices) << endl;
        cout << "But result is: " << buyAndSellStockOnce(prices) << endl;

        return false;
    }

    return true;
}

} // chapter6
} // epi
