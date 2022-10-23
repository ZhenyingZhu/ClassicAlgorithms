#include "DoubleSquareRoot.hpp"

#include <cassert>
#include <math.h>
#include <limits>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::numeric_limits;
using std::invalid_argument;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter12 {
    DoubleSquareRoot::Ordering DoubleSquareRoot::compare(double a, double b) {
        if (b == 0.0) {
            if (a > 0.0)
                return LR;
            else if (a == 0.0)
                return EQ;
            else
                return SM;
        }

        double diff = (a - b) / b; // normalized. b cannot be 0

        if ( diff < -numeric_limits<double>::epsilon() ) {
            return SM;
        } else if ( diff > numeric_limits<double>::epsilon() ) {
            return LR;
        } else {
            return EQ;
        }
    }

    double DoubleSquareRoot::squareRoot(double x) {
        if (x < 0.0)
            throw invalid_argument("cannot compute square root for negative number");

        if (x == 0.0)
            return 0.0;

        double left, right;
        if (x < 1.0) {
            left = x;
            right = 1.0;
        } else {
            left = 1.0;
            right = x;
        }

        while (compare(left, right) == SM) {
            double mid = left + 0.5 * (right - left);
            double sqr = mid * mid;
            if (compare(sqr, x) == SM)
                left = mid;
            else if (compare(sqr, x) == LR)
                right = mid;
            else
                return mid;
        }

        return left;
    }

    bool DoubleSquareRoot::test() {
        for (double i = 0.0; i != 17.0; i += 1.0) {
            double ans = sqrt(i);
            double res = squareRoot(i);

            if (compare(ans, res) != EQ) {
                cout << i << " root should be " << sqrt(i) << endl;
                cout << "Result " << squareRoot(i) << endl;
                return false;
            }
        }

        return true;
    }

  } // chapter12
} // epi
