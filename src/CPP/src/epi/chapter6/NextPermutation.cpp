#include "NextPermutation.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include "../../MyUtils.h"

using std::cout;
using std::endl;
using std::vector;
using std::find;
using std::reverse;
using myutils::vec_to_string;
using std::invalid_argument;

namespace epi {
  namespace chapter6 {
    bool NextPermutation::isOneOfPerm(int num, vector<int> perm) {
        while (num) {
            vector<int>::iterator iter = find(perm.begin(), perm.end(), num % 10);
            if (iter == perm.end())
                return false;

            perm.erase(iter);
            num /= 10;
        }

        return true;
    }

    vector<int> NextPermutation::nextPermutationBruteForce(vector<int> perm) {
        vector<int> res;

        if (perm.size() == 0)
            return res;

        int sum = 0;

        bool theLastPerm = true;
        for (size_t i = 0; i != perm.size(); ++i) {
            if (perm[i] >= 10 || perm[i] < 0)
                throw invalid_argument("Element not in 0 ~ 9");

            if (i != 0)
                if (perm[i] > perm[i - 1])
                    theLastPerm = false;

            sum = sum * 10 + perm[i];
        }

        if (theLastPerm)
            return res;

        while (true) {
            ++sum;
            if (isOneOfPerm(sum, perm)) {
                break;
            }
        }

        while(sum) {
            res.insert(res.begin(), sum % 10);
            sum /= 10;
        }
        return res;
    }

    vector<int> NextPermutation::nextPermutation(vector<int> perm) {
        int k = perm.size() - 2;
        while (k >= 0 && perm[k] >= perm[k + 1])
            --k;

        if (k == -1)
            return {};

        for (int i = perm.size() - 1; i != k; --i) {
            if (perm[i] > perm[k]) {
                int tmp = perm[i];
                perm[i] = perm[k];
                perm[k] = tmp;
                break;
            }
        }

        reverse(perm.begin() + k + 1, perm.end());

        return perm;
    }

    bool NextPermutation::test() {
        vector<int> perm1 = {1, 0, 2, 3};
        vector<int> perm2 = {1, 0, 3, 2};
        vector<int> perm3 = {0, 3, 2, 1};
        vector<int> perm4 = {3, 2, 1, 0};
        vector<int> perm5 = {6, 2, 1, 5, 4, 3, 0};
        vector<int> perm6 = {2, 1, 0, 1};
        vector<int> perm7 = {2, 1, 1, 3};
        vector<int> perm8 = {2, 3, 1, 1};
        vector<vector<int>> perms = {perm1, perm2, perm3, perm4, perm5, perm6, perm7, perm8};

        for (vector<int> perm : perms) {
            if (nextPermutationBruteForce(perm) != nextPermutation(perm)) {
                cout << "Should be: " << vec_to_string(nextPermutationBruteForce(perm)) << endl;
                cout << "Result: " << vec_to_string(nextPermutation(perm)) << endl;
                return false;
            }
        }

        return true;
    }

  } // chapter6
} // epi
