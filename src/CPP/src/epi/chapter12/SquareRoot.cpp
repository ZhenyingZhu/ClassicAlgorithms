#include "SquareRoot.hpp"

#include <math.h>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::invalid_argument;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter12 {
    int SquareRoot::squareRoot(int k) {
        if (k < 0)
            throw invalid_argument("Sqrt on negative number");

        if (k == 0 || k == 1)
            return k;

        int st = 1, ed = k / 2, md = 1;
        while (st <= ed) {
            md = st + (ed - st) / 2;
            int res = md * md;
            if (res == k)
                return md;

            if (res < k) {
                if ( (md + 1) * (md + 1) > k )
                    return md;
                st = md + 1;
            } else
                ed = md - 1;
        }

        return md;
    }

    bool SquareRoot::test() {
        for (int i = 0; i != 17; ++i) {
            if (squareRoot(i) != (int)sqrt(i)) {
                cout << i << " root should be " << (int)sqrt(i) << endl;
                cout << "Result " << squareRoot(i) << endl;
                return false;
            }
        }

        return true;
    }

  } // chapter12
} // epi
