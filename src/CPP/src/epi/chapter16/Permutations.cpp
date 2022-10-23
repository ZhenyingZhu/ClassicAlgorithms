#include "Permutations.hpp"

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::unique_ptr;
using std::sort;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter16 {
    void Permutations::permutationsHelper(vector<int> &array, vector<int> &prevAdded,
            vector<bool> &isEntriesAdded, vector<vector<int>> &result) {
        if (prevAdded.size() == array.size()) {
            result.push_back(vector<int>(prevAdded));
            return;
        }

        bool first = true;
        int dup = 0;
        for (size_t i = 0; i != array.size(); ++i) {
            if (isEntriesAdded[i])
                continue;

            if (!first && array[i] == dup)
                continue;

            prevAdded.push_back(array[i]);
            isEntriesAdded[i] = true;
            dup = array[i];
            permutationsHelper(array, prevAdded, isEntriesAdded, result);

            prevAdded.pop_back();
            isEntriesAdded[i] = false;
            first = false;
        }
    }

    std::vector<std::vector<int>> Permutations::permutations(std::vector<int> array) {
        sort(array.begin(), array.end());

        vector<vector<int>> res;

        vector<bool> isEntriesAdded(array.size(), false);
        vector<int> permutation;
        permutationsHelper(array, permutation, isEntriesAdded, res);

        return res;
    }

    bool Permutations::test() {
        vector<int> array = {1, 2, 3, 2};
        vector<vector<int>> res = permutations(array);

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
