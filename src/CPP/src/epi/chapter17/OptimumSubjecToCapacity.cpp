#include "OptimumSubjecToCapacity.hpp"

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::max;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter17 {
    struct OptimumSubjecToCapacity::Item {
        size_t weight;
        unsigned int value;
    };

    unsigned int OptimumSubjecToCapacity::optimumSubjecToCapacity(const vector<Item> &items, size_t capacity) {
        if (items.size() == 0 || capacity == 0)
            return 0;

        vector<vector<unsigned int>> maxValue( items.size() + 1, vector<unsigned int>(capacity + 1, 0) );
//        for (size_t i = 0; i != capacity + 1; ++i)
//            maxValue[0][i] = 0;

        for (size_t itemNum = 1; itemNum != items.size() + 1; ++itemNum) {
            for (size_t cap = 1; cap != capacity + 1; ++cap) {
                unsigned int currentValue = maxValue[itemNum - 1][cap];

                size_t itemWeight = items[itemNum - 1].weight;
                unsigned int itemValue = items[itemNum - 1].value;
                if (itemWeight <= cap) {
                    currentValue = max(currentValue, maxValue[itemNum - 1][cap - itemWeight] + itemValue);
                }

                maxValue[itemNum][cap] = currentValue;
            }
        }

        return maxValue[items.size()][capacity];
    }

    bool OptimumSubjecToCapacity::test() {
        vector<Item> items = {
                {5, 60},
                {3, 50},
                {4, 70},
                {2, 30}
        };
        unsigned int res = optimumSubjecToCapacity(items, 5);

        if ( res != 80 ) {
            cout << "Should be: 80" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter17
} // epi
