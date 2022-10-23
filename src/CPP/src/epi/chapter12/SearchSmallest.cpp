#include "SearchSmallest.hpp"

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
    int SearchSmallest::searchSmallest(const vector<int> &A) {
        int st = 0, ed = A.size() - 1;

        int md = st;
        while (st <= ed) {
            if (A[st] < A[ed])
                return st;

            md = st + (ed - st) / 2;
            if (A[md] > A[st] || A[md] > A[ed]) {
                st = md + 1;
            } else if (A[md] < A[st]) {
                ed = md;
            } else { // A[md] == A[st] == A[ed]
                int smallest = A[st], idx = st;
                for (int i = st; i != ed; ++i) {
                    if (A[i] < smallest) {
                        smallest = A[i];
                        idx = i;
                    }
                }
                return idx;
            }
        }

        return md;
    }

    bool SearchSmallest::test() {
        vector<int> input = {378, 478, 550, 631, 103, 203, 220, 234, 279, 368};

        int res1 = searchSmallest(input);
        if (res1 != 4) {
            cout << "Should be 4" << endl;
            cout << "Result " << res1 << endl;
            return false;
        }

        return true;
    }

  } // chapter12
} // epi
