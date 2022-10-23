#ifndef SRC_EPI_CHAPTER6_BUYANDSELLSTOCKONCE_HPP_
#define SRC_EPI_CHAPTER6_BUYANDSELLSTOCKONCE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
namespace chapter6 {

class BuyAndSellStockOnce : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    BuyAndSellStockOnce():
        Solution("EPI Chapter 6.6",
                 "The max profit can make when buy and sell stock once",
                 "Tracking the current seen min value, update max profit using current-min") { }

    bool test();

    ~BuyAndSellStockOnce() { }

    double buyAndSellStockOnceBruteForce(const std::vector<double> &prices);

    double buyAndSellStockOnce(const std::vector<double> &prices);
};

} // chapter6
} // epi

#endif /* SRC_EPI_CHAPTER6_BUYANDSELLSTOCKONCE_HPP_ */
