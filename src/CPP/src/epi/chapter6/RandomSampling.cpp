#include "RandomSampling.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "../../MyUtils.h"

using std::vector;
using std::cout;
using std::endl;
using myutils::vec_to_string;
using std::default_random_engine;
using std::random_device;
using std::uniform_int_distribution;
using std::swap;

namespace epi {
  namespace chapter6 {
    void RandomSampling::randomSampling(int k, vector<int> &vec) {
        default_random_engine seed( (random_device()) () );

        for (int i = 0; i != k; ++i) {
            int randomIdx = uniform_int_distribution<int>{ i, static_cast<int>(vec.size() - 1) }(seed);
            swap(vec[i], vec[randomIdx]);
        }
    }

    bool RandomSampling::test() {
        vector<int> vec;
        for (int i = 0; i != 10; ++i)
            vec.push_back(i);

        randomSampling(3, vec);
        vector<int> res(vec.begin(), vec.begin() + 3);
        cout << vec_to_string(res) << endl;

        return true;
    }

  } // chapter6
} // epi
