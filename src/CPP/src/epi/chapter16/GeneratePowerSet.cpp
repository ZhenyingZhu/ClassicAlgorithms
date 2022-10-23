#include "GeneratePowerSet.hpp"

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
    void GeneratePowerSet::generatePowerSetHelper(const vector<int> &array, size_t pos, vector<int> &prevAdded, vector<vector<int>> &result) {
        result.push_back(prevAdded);

        for (size_t i = pos; i != array.size(); ++i) {
            if (i != pos && array[i] == array[i - 1])
                continue;

            prevAdded.push_back(array[i]);
            generatePowerSetHelper(array, i + 1, prevAdded, result);
            prevAdded.pop_back();
        }
    }

    vector<vector<int>> GeneratePowerSet::generatePowerSet(const vector<int> &array) {
        vector<int> input(array);
        sort(input.begin(), input.end());

        vector<vector<int>> res;
        vector<int> prev;
        generatePowerSetHelper(input, 0, prev, res);

        return res;
    }

    bool GeneratePowerSet::test() {
        vector<int> array = {1, 2, 3, 2};
        vector<vector<int>> res = generatePowerSet(array);

        if (res.size() != 12) {
            cout << "Wrong number of results" << endl;
            for (vector<int> vec : res) {
                cout << vec_to_string(vec) << endl;
            }

            return false;
        }

        return true;
    }

  } // chapter16
} // epi
