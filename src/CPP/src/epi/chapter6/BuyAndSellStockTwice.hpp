#ifndef SRC_EPI_CHAPTER6_BUYANDSELLSTOCKTWICE_HPP_
#define SRC_EPI_CHAPTER6_BUYANDSELLSTOCKTWICE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
namespace chapter6 {

class BuyAndSellStockTwice : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    BuyAndSellStockTwice():
        Solution("EPI Chapter 6.7",
                 "The max profit can make when buy and sell stock at most twice",
                 "DP by traverse frontward and backward") { }

    bool test();

    ~BuyAndSellStockTwice() { }

    double buyAndSellStockTwiceBruteForce(const std::vector<double> &prices);

    double buyAndSellStockTwice(const std::vector<double> &prices);

private:
    double buyAndSellStockOnce(std::vector<double>::const_iterator begin, std::vector<double>::const_iterator end);
};

} // chapter6
} // epi

#endif /* SRC_EPI_CHAPTER6_BUYANDSELLSTOCKTWICE_HPP_ */
