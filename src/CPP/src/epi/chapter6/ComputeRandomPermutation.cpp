#include "ComputeRandomPermutation.hpp"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <random>

#include "../../MyUtils.h"

using std::vector;
using std::cout;
using std::endl;
using std::iota;
using std::swap;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::random_device;
using myutils::vec_to_string;

namespace epi {
  namespace chapter6 {
    vector<int> ComputeRandomPermutation::computeRandomPermutation(int n) {
        if (n <= 0)
            return {};

        vector<int> res(n);
        iota(res.begin(), res.end(), 0);

        default_random_engine seed( (random_device()) () );

        for (int i = 0; i != n; ++i) {
            int randomIdx = uniform_int_distribution<int>{ i, n - 1 }(seed);
            swap(res[i], res[randomIdx]);
        }

        return res;
    }

    bool ComputeRandomPermutation::test() {
        for (int i = 0; i != 3; ++i) {
            vector<int> res = computeRandomPermutation(4);
            cout << vec_to_string(res) << endl;
        }

        return true;
    }

  } // chapter6
} // epi
