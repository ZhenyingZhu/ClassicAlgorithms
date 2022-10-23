#ifndef SRC_EPI_CHAPTER14_FINDSALARYCAP_HPP_
#define SRC_EPI_CHAPTER14_FINDSALARYCAP_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter14 {
    class FindSalaryCap : myutils::Solution {
    public:
        FindSalaryCap():
            Solution("EPI Chapter 14.10",
                     "Compute a salary threshold",
                     "Given a salary array and a target sum payroll. Set a cap so that salary "
                     "above cap become cap, and the sum equle to payroll. First set cap to be "
                     "each salary and compute the sum payroll. Find out cap should between which "
                     "two salaries. Then use a formular to compute the exact cap.") { }

        ~FindSalaryCap() { }

        double findSalaryCap(double targetPayroll, std::vector<double> currentSalaries);

        bool test();

    };

  } // chapter14
} // epi

#endif /* SRC_EPI_CHAPTER14_FINDSALARYCAP_HPP_ */
