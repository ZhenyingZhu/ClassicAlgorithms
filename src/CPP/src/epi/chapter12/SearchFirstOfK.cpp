#include "SearchFirstOfK.hpp"

#include <vector>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::vector;
using std::length_error;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter12 {
    int SearchFirstOfK::searchFirstOfK(const vector<int> &A, int k) {
        int st = 0, ed = A.size() - 1;

        while (st <= ed) {
            int md = st + (ed - st) / 2;
            if (A[md] == k) {
                if (md == 0 || A[md - 1] < k)
                    return md;
                ed = md - 1;
            } else if (A[md] < k) {
                st = md + 1;
            } else {
                ed = md - 1;
            }
        }

        return -1;
    }

    bool SearchFirstOfK::test() {
        vector<int> input = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};

        int res1 = searchFirstOfK(input, 108);
        if (res1 != 3) {
            cout << "Should be 3" << endl;
            cout << "Result " << res1 << endl;
            return false;
        }

        int res2 = searchFirstOfK(input, 285);
        if (res2 != 6) {
            cout << "Should be 6" << endl;
            cout << "Result " << res2 << endl;
            return false;
        }

        int res3 = searchFirstOfK(input, 1);
        if (res3 != -1) {
            cout << "Should be -1" << endl;
            cout << "Result " << res3 << endl;
            return false;
        }

        return true;
    }

  } // chapter12
} // epi
