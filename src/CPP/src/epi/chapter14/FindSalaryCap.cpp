#include "FindSalaryCap.hpp"

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../ListNode.h"
#include "../../MyUtils.h"

using myutils::vec_to_string;
using std::vector;
using std::sort;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter14 {
    double FindSalaryCap::findSalaryCap(double targetPayroll, vector<double> currentSalaries) {
        sort(currentSalaries.begin(), currentSalaries.end());

        double computedPayroll = 0.0;
        for (size_t i = 0; i != currentSalaries.size(); ++i) {
            const double newCapPayroll = currentSalaries[i] * (currentSalaries.size() - i);

            if ( (computedPayroll + newCapPayroll) >= targetPayroll ) {
                return ( (targetPayroll - computedPayroll) / (currentSalaries.size() - i) );
            }

            computedPayroll += currentSalaries[i];
        }

        return -1.0;
    }

    bool FindSalaryCap::test() {
        vector<double> array = {20,30,40,90,100};
        double res = findSalaryCap(210, array);

        if (res != 60.0) {
            cout << "Should be " << 60.0 << endl;
            cout << "Result " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter14
} // epi
