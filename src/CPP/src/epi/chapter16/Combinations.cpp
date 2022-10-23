#include "Combinations.hpp"

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::sort;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter16 {
    void Combinations::combinationsHelper(unsigned int n, size_t k, unsigned int st,
            vector<unsigned int> &prevAdded, vector<vector<unsigned int>> &result) {
        if (prevAdded.size() == k) {
            result.push_back(prevAdded);
            return;
        }

        for (unsigned int i = st; i <= n; ++i) {
            prevAdded.push_back(i);
            combinationsHelper(n, k, i + 1, prevAdded, result);
            prevAdded.pop_back();
        }
    }

    vector<vector<unsigned int>> Combinations::combinations(unsigned int n, size_t k) {
        vector<vector<unsigned int>> res;
        vector<unsigned int> prev;
        combinationsHelper(n, k, 1, prev, res);

        return res;
    }

    bool Combinations::test() {
        vector<vector<unsigned int>> res = combinations(5, 2);

        if (res.size() != 10) {
            cout << "Wrong number of results" << endl;
            for (vector<unsigned int> vec : res) {
                cout << vec_to_string(vec) << endl;
            }

            return false;
        }

        return true;
    }

  } // chapter16
} // epi
